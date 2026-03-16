//キーボード処理のソースファイル

//ヘッダファイル読み込み
#include "key.h"

//グローバル変数

//現在のキーを押しているフレーム数
int NowKeyPressFrame[KeyKindMax];

//１つ前のキーを押しているフレーム数
int OldKeyPressFrame[KeyKindMax];

//関数

//キーボード処理の初期化
VOID KeyInit(VOID)
{
	//配列の初期化
	for (int i = 0; i < KeyKindMax; i++)
	{
		NowKeyPressFrame[i] = 0;
		OldKeyPressFrame[i] = 0;
	}

	return;
}

//キーボード処理の更新
VOID KeyUpdate(VOID)
{
	//一時的に保持するキー情報
	char KeyState[KeyKindMax];

	//すべてのキー情報を一度に取得
	GetHitKeyStateAll(KeyState);

	//キー情報を更新
	for (int i = 0; i < KeyKindMax; i++)
	{
		//1つ前のキー入力を保存
		OldKeyPressFrame[i] = NowKeyPressFrame[i];

		//現在、キーが押されているとき
		if (KeyState[i] > 0)
		{
			//押されているフレーム数をカウントアップ
			NowKeyPressFrame[i]++;
		}
		else if (KeyState[i] == 0)
		{
			//押されていないなら、フレーム数をゼロにする
			NowKeyPressFrame[i] = 0;
		}
	}

	return;
}

//特定のキーを押したか
//引数：KEY_INPUT_　キーコードのマクロ定義
BOOL KeyDown(int KEY_INPUT_)
{
	//現在押されているキーのフレーム数が１以上なら
	if (NowKeyPressFrame[KEY_INPUT_] > 0)
	{
		return TRUE;	//押している
	}
	return FALSE;	//押していない
}

//特定のキーをクリックしたか
//引数：KEY_INPUT_　キーコードのマクロ定義
//説明：「キーを押す→キーを上げる」がセットで行われた時が、クリック
BOOL KeyClick(int KEY_INPUT_)
{
	//現在、キーは押されておらず、かつ
	//ひとつ前のフレームでは、キーが押されていたとき
	if (NowKeyPressFrame[KEY_INPUT_] == 0
	&& OldKeyPressFrame[KEY_INPUT_] > 0)
	{
		return TRUE;	//押している
	}
	return FALSE;	//押していない
}

//特定のキーを押したフレーム数
//引数：KEY_INPUT_　キーコードのマクロ定義
//説明：キーを押しているフレーム数を返す
int KeyPressFrame(int KEY_INPUT_)
{
	return NowKeyPressFrame[KEY_INPUT_];
}