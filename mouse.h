//マウス処理のヘッダファイル
#pragma once

//ヘッダファイル読み込み
#include "DxLib.h"

//マクロ定義
#define MouseKindMax 8			//マウスのボタンの種類
#define MouseCodeErrIndex 999	//マウスコードを変換した要素数のエラー値

//構造体
typedef struct _MousePoint
{
	int x; //マウスのX座標
	int y; //マウスのY座標
}MousePoint;

//外部のプロトタイプ変数
extern VOID MouseNowIntoOld(VOID); //Now???系の変数の値をOld???系の変数へ入れる
extern int MouseCodeToIndex(int MOUSE_INPUT_); //マウスのボタンコードを配列の要素数に変換する

extern VOID MouseInit(VOID);					//マウス処理の初期化
extern VOID MouseUpdate(VOID);					//マウス処理の更新
extern BOOL MouseDown(int MOUSE_INPUT_);			//特定のボタンを押したか
extern BOOL MouseClick(int MOUSE_INPUT_);			//特定のボタンをクリックしたか
extern int  MousePressFrame(int MOUSE_INPUT_);	//特定のボタンを押したフレーム数

extern MousePoint GetPointMouse(VOID);			//マウスポインタの現在の座標を取得
extern MousePoint GetOldPointMouse(VOID);		//前フレームのマウスポインタの座標を取得
extern MousePoint GetDiffPointMouse(VOID);		//マウスポインタの以前と現在の座標の差分を取得;

extern int GetWheelMouse(VOID);					//マウスホイールの現在の回転量を取得