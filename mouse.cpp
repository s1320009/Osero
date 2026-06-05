//マウス処理のソースファイル

//ヘッダファイル読み込み
#include "mouse.h"
#include "game.h"

//グローバル変数
MousePoint NowPoint;			//現在のマウスの位置
MousePoint OldPoint;			//以前のマウスの位置

int NowMousePressFrame[MouseKindMax];	//現在のマウスを押しているフレーム数
int OldMousePressFrame[MouseKindMax];	//以前のマウスを押しているフレーム数

int NowWheelValue;	//現在のマウスのホイール回転量
int OldWheelValue;	//以前のマウスのホイール回転量

//マウスのボタンコードとフレーム数を管理している配列の要素数を紐づける
int MouseCodeIndex[MouseKindMax]
{
	MOUSE_INPUT_LEFT,		//配列の要素数0にはマウスのボタン情報の0x0001の情報を入れる
	MOUSE_INPUT_RIGHT,		//配列の要素数1にはマウスのボタン情報の0x0002の情報を入れる
	MOUSE_INPUT_MIDDLE,		//配列の要素数2にはマウスのボタン情報の0x0004の情報を入れる
	MOUSE_INPUT_4,			//配列の要素数3にはマウスのボタン情報の0x0008の情報を入れる
	MOUSE_INPUT_5,			//配列の要素数4にはマウスのボタン情報の0x0010の情報を入れる
	MOUSE_INPUT_6,			//配列の要素数5にはマウスのボタン情報の0x0020の情報を入れる
	MOUSE_INPUT_7,			//配列の要素数6にはマウスのボタン情報の0x0040の情報を入れる
	MOUSE_INPUT_8,			//配列の要素数7にはマウスのボタン情報の0x0080の情報を入れる
};

//Now???系の変数の値をOld系の変数へ入れる
VOID MouseNowIntoOld(VOID)
{
	OldPoint = NowPoint;	//マウスの位置

	//フレーム数
	for (int i = 0; i < MouseKindMax; i++)
	{
		OldMousePressFrame[i] = NowMousePressFrame[i];
	}

	//ホイール量
	OldWheelValue = NowWheelValue;

	return;
}

//マウスのボタンコードを配列の要素数に変換する
int MouseCodeToIndex(int MOUSE_INPUT_)
{
	for (int i = 0; i < MouseKindMax; i++)
	{
		//マウスコードが紐づけされているなら
		if (MouseCodeIndex[i] == MOUSE_INPUT_)
		{
			return i;	//その要素数を返す
		}
	}

	//マウスコードが紐づけされていないなら、エラー値を返す
	return MouseCodeErrIndex;
}

//マウス処理の初期化
VOID MouseInit(VOID)
{
	NowPoint.x = 0;
	NowPoint.y = 0;

	//フレーム数
	for (int i = 0; i < MouseKindMax; i++)
	{
		NowMousePressFrame[i] = 0;
	}

	//ホイール量
	NowWheelValue = 0;

	//Old系も初期化
	MouseNowIntoOld();

	return;
}

//マウス処理の更新
VOID MouseUpdate(VOID)
{
	//マウスのボタン情報を全て取得
	int Input;

	//現在の情報を以前の情報として保存
	MouseNowIntoOld();

	//現在のマウスのクライアント座標の位置を取得
	GetMousePoint(&NowPoint.x, &NowPoint.y);

	//もし、マウスの座標がゲーム画面外にあるなら、ゲーム画面内に収める
	if (NowPoint.x < 0) { NowPoint.x = 0; } //左
	else if (NowPoint.x > GameWidth) { NowPoint.x = GameWidth; } //右
	if (NowPoint.y < 0) { NowPoint.y = 0; } //上
	else if (NowPoint.y > GameHeight) { NowPoint.y = GameHeight; } //下

	//マウスのボタン情報を全て取得
	Input = GetMouseInput();

	//マウスのボタンの種類ごとに、押しているフレーム数を管理
	for (int i = 0; i < MouseKindMax; i++)
	{
		//【if文の条件説明】
		//取得した値をマウスコードでマスクした結果が、そのマウスコードならば
		// 例）取得した値が0x0007		→ 最後のバイトが00000111のとき
		//		マウスコードが0x0001(左)→ 最後のバイトが00000001で、
		//論理積でマスク処理(上下とも1なら1/それ以外は0)&----------
		//				結果0x0001		→ 最後のバイトが00000001となる
		// 複数の値が入っていても、マスク処理をすれば、特定の値のみ抽出できる!
		// ※某サイトでは、Input & 1<<i としている。(左シフトで1のビットをずらす)
		if ((Input & MouseCodeIndex[i]) == MouseCodeIndex[i])
		{
			//現在押しているボタンのフレーム数をカウントアップ
			NowMousePressFrame[i]++;
		}
		else if ((Input & MouseCodeIndex[i]) != MouseCodeIndex[i])
		{
			//現在押しているボタンのフレーム数をゼロにする
			NowMousePressFrame[i] = 0;
		}
	}

	//マウスのホイール回転量を取得
	NowWheelValue = GetMouseWheelRotVol();

	return;
}

//特定のマウスのボタンを押したか
BOOL MouseDown(int MOUSE_INPUT_)
{
	//マウスコードを配列の要素数に変換
	int index = MouseCodeToIndex(MOUSE_INPUT_);

	//実在するマウスコードなら
	if (index != MouseCodeErrIndex)
	{
		//現在押しているなら
		if (NowMousePressFrame[index] > 0)
		{
			return TRUE;	//押している
		}
	}

	
	return FALSE; //押していない
}

//特定のマウスのボタンをクリックしたか
BOOL MouseClick(int MOUSE_INPUT_)
{
	//マウスコードを配列の要素数に変換
	int index = MouseCodeToIndex(MOUSE_INPUT_);

	//実在するマウスコードなら
	if (index != MouseCodeErrIndex)
	{
		if (NowMousePressFrame[index] == 0		//現在は押していないが
			&& OldMousePressFrame[index] > 0)	//以前は押していた
		{
			return TRUE;	//押している
		}
	}

	return FALSE; //押していない
}

//特定のマウスのボタンを押したフレーム数
int MousePressFrame(int MOUSE_INPUT_)
{
	//マウスコードを配列の要素数に変換
	int index = MouseCodeToIndex(MOUSE_INPUT_);

	//実在するマウスコードなら
	if (index != MouseCodeErrIndex)
	{
		return NowMousePressFrame[MOUSE_INPUT_];
	}
	return 0;
}

//マウスポインタの現在の座標を取得
MousePoint GetPointMouse(VOID)
{
	return NowPoint;
}

//前フレームのマウスポインタの座標を取得
MousePoint GetOldPointMouse(VOID)
{
	return OldPoint;
}

//マウスポインタの以前と現在の座標の差分を取得;
MousePoint GetDiffPointMouse(VOID)
{
	MousePoint diff;
	diff.x = OldPoint.x - NowPoint.x;
	diff.y = OldPoint.y - NowPoint.y;
	return diff;
}

//マウスの現在のホイール量を取得する
int GetWheelMouse(VOID)
{
	return NowWheelValue;
}