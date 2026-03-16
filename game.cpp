//ヘッダファイル読み込み
#include "game.h"
#include "key.h"

//グローバル変数の定義

//ゲームシーン
enum GameScene NowGameScene; //現在のゲームシーン
enum GameScene ChangeGameScene; //切り替えるゲームシーン

//ゲームシーンの名前
char GameSceneName[GameSceneCount][GameSceneNameMax]
{
	"タイトル画面",
	"プレイ画面",
	"リザルト画面"
};

//シーン切り替え後のフレーム数を管理
int GameSceneFrameCount[GameSceneCount];

//関数

//タイトル初期化
extern VOID TitleInit(VOID)
{
	if(GameDebug == TRUE)
	{
		//シーン名表示
		DrawFormatString(
			GameWidth - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", GameSceneName[ChangeGameScene], "Init");

		//適切なシーンの初期化ができているかテスト
		//ScreenFlip();	//あえて裏画面を描画
		//WaitTimer(2000);	//2秒待つ
	}	

	//シーンを切り替えたフレーム数を初期化
	GameSceneFrameCount[ChangeGameScene] = 0;

	return;
}
//タイトル管理
extern VOID TitleCtrl(VOID)
{
	TitleProc();	//処理をしてから
	TitleDraw();	//描画する
	return;
}
//タイトル処理
extern VOID TitleProc(VOID)
{
	//シーン切り替え後のフレーム数をカウントアップ
	GameSceneFrameCount[NowGameScene]++;
	
	//シーン切り替え
	if (KeyDown(KEY_INPUT_SPACE) == TRUE								//スペースキーが押され,
		&& GameSceneFrameCount[NowGameScene] >= GameSceneChangeFrame)	//かつ、切り替え可能なフレーム数を超えたら
	{
		//シーン切り替え
		ChangeGameScene = PlayScene;

		//すぐに切り替える
		return;
	}

	return;
}
//タイトル描画
extern VOID TitleDraw(VOID)
{
	if (GameDebug == TRUE)
	{
		//適当に描画
		DrawBox(0, 0, GameWidth, GameHeight, GetColor(255, 0, 255), TRUE);

		//シーン名表示
		DrawFormatString(
			GameWidth - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", GameSceneName[NowGameScene], "描画中");
	}

	return;
}

//プレイ初期化
extern VOID PlayInit(VOID)
{
	if (GameDebug == TRUE)
	{
		//シーン名表示
		DrawFormatString(
			GameWidth - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", GameSceneName[ChangeGameScene], "Init");

		//適切なシーンの初期化ができているかテスト
 		//ScreenFlip();	//あえて裏画面を描画
		//WaitTimer(2000);	//2秒待つ
	}

	//シーンを切り替えたフレーム数を初期化
	GameSceneFrameCount[ChangeGameScene] = 0;

	return;
}
//プレイ管理
extern VOID PlayCtrl(VOID)
{
	PlayProc();	//処理をしてから
	PlayDraw();	//描画する

	return;
}
//プレイ処理
extern VOID PlayProc(VOID)
{
	//シーン切り替え後のフレーム数をカウントアップ
	GameSceneFrameCount[NowGameScene]++;

	//シーン切り替え
	if (KeyDown(KEY_INPUT_SPACE) == TRUE								//スペースキーが押され,
		&& GameSceneFrameCount[NowGameScene] >= GameSceneChangeFrame)	//かつ、切り替え可能なフレーム数を超えたら
	{
		//シーン切り替え
		ChangeGameScene = ResultScene;

		//すぐに切り替える
		return;
	}

	return;
}
//プレイ描画
extern VOID PlayDraw(VOID)
{
	if (GameDebug == TRUE)
	{
		//適当に描画
		DrawBox(0, 0, GameWidth, GameHeight, GetColor(0, 255, 255), TRUE);

		//シーン名表示
		DrawFormatString(
			GameWidth - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", GameSceneName[NowGameScene], "描画中");
	}

	return;
}

//リザルト初期化
extern VOID ResultInit(VOID)
{
	if (GameDebug == TRUE)
	{
		//シーン名表示
		DrawFormatString(
			GameWidth - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", GameSceneName[ChangeGameScene], "Init");

		//適切なシーンの初期化ができているかテスト
		//ScreenFlip();	//あえて裏画面を描画
		//WaitTimer(2000);	//2秒待つ
	}

	//シーンを切り替えたフレーム数を初期化
	GameSceneFrameCount[ChangeGameScene] = 0;

	return;
}
//リザルト管理
extern VOID ResultCtrl(VOID)
{
	ResultProc();	//処理をしてから
	ResultDraw();	//描画する

	return;
}
//リザルト処理
extern VOID ResultProc(VOID)
{
	//シーン切り替え後のフレーム数をカウントアップ
	GameSceneFrameCount[NowGameScene]++;

	//シーン切り替え
	if (KeyDown(KEY_INPUT_SPACE) == TRUE								//スペースキーが押され,
		&& GameSceneFrameCount[NowGameScene] >= GameSceneChangeFrame)	//かつ、切り替え可能なフレーム数を超えたら
	{
		//シーン切り替え
		ChangeGameScene = TitleScene;

		//すぐに切り替える
		return;
	}

	return;
}
//リザルト描画
extern VOID ResultDraw(VOID)
{
	if (GameDebug == TRUE)
	{
		//適当に描画
		DrawBox(0, 0, GameWidth, GameHeight, GetColor(255, 255, 0), TRUE);

		//シーン名表示
		DrawFormatString(
			GameWidth - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", GameSceneName[NowGameScene], "描画中");
	}

	return;
}