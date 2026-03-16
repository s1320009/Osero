//FPS処理のヘッダファイル
#pragma once

//ヘッダファイル読み込み
#include "DxLib.h"

//マクロ定義
#define GameFPS				60	//理想のFPS値

#define MicroSecond 1000000.0f	//マイクロ秒を秒に変換するための定数
#define MilliSecond 1000.0f		//ミリ秒を秒に変換するための定数
#define WaitTimeMilli  3000		//最大で待つ時間（ミリ秒）

//構造体の定義＆名前の再定義
typedef struct _FPS
{
	LONGLONG FirstTakeTime = 0;		//最初の時間
	LONGLONG NowTakeTime = 0;		//現在の計測時間
	LONGLONG OldTakeTime = 0;		//以前の計測時間

	float DeltaTime = 0.000001f;	//前回の時間からの経過時間（デルタタイム）
	int FrameCount = 1;				//現在のフレーム数（1フレーム目～MAXフレーム目まで）
	float Average = 0.0f;		//平均FPS
}FPS;

//外部グローバル変数
extern FPS fps;

extern VOID FPSInit(VOID);	//FPS初期化
extern VOID FPSCheck(VOID);	//FPS計測
extern VOID FPSDraw(VOID);	//FPS描画
extern VOID FPSWait(VOID);	//FPS待機