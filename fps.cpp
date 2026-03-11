//FPS処理のソースファイル

//ヘッダファイル読み込み
#include "fps.h"

//グローバル変数の定義
FPS fps;

//FPS初期化
VOID FPSInit(VOID)
{

	//Windowsが起動してから現在までの時間を得る（マイクロ秒）
	fps.FirstTakeTime = GetNowHiPerformanceCount();

	//ほかの値も初期化
	fps.NowTakeTime = fps.FirstTakeTime;
	fps.OldTakeTime = fps.FirstTakeTime;
	fps.DeltaTime = 0.000001f;
	fps.FrameCount = 1;
	fps.Average = 0.0f;

	return;
}

//計測
VOID FPSCheck(VOID)
{
	//現在の時刻を取得
	fps.NowTakeTime = GetNowHiPerformanceCount();

	//デルタタイムを計算
	fps.DeltaTime = (fps.NowTakeTime - fps.OldTakeTime) / MicroSecond;

	//現在の時刻を保存
	fps.OldTakeTime = fps.NowTakeTime;

	//現在がMAXフレーム目なら
	if (fps.FrameCount == GameFPS)
	{
		//１フレーム目～MAXフレーム目までの合計時間を計算
		float TotalFrameTime = fps.NowTakeTime - fps.FirstTakeTime;

		//合計時間を理想のFPS値で割って平均値を計算
		float CalcAverage = TotalFrameTime / GameFPS;

		//１秒当たりのフレーム数に変換
		fps.Average = MicroSecond / CalcAverage;

		//１フレーム目の時刻を取得
		fps.FirstTakeTime = GetNowHiPerformanceCount();

		//フレーム数を１に戻す
		fps.FrameCount = 1;
	}
	else
	{
		//フレーム数をカウントアップ
		fps.FrameCount++;
	}

	return;
}

//FPS描画
VOID FPSDraw(VOID)
{
	DrawFormatString(0, 0, GetColor(255, 255, 255),"FPS:%3.1f", fps.Average);
	return;
}

//FPS待機
VOID FPSWait(VOID)
{
	//早すぎたときに待機するミリ秒
	int wait = 0;

	//待ち時間を計測
	wait =
		MicroSecond / GameFPS * fps.FrameCount		//理想の時間
		- (fps.NowTakeTime - fps.FirstTakeTime);	//実際の時間

	//マイクロ秒をミリ秒に変換
	wait /= MilliSecond;

	//待ち時間があるならば
	if (wait > 0 && wait <= WaitTimeMilli)
	{
		//「メッセージ」を処理しながら待つ
		WaitTimer(wait);

		//Sleep(wait); //これだと完全に待ってしまうので、メッセージ処理ができない
	}

	return;
}