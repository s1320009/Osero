//ヘッダファイル読み込み
#include "game.h"

//グローバル変数の定義

//ゲームシーン
enum GameScene NowGameScene; //現在のゲームシーン

//ゲームシーンの名前
char GameSceneName[GameSceneCount][GameSceneNameMax]
{
	"タイトル画面",
	"プレイ画面",
	"リザルト画面"
};

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
			"%s%s", GameSceneName[NowGameScene], "Init");
	}	

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
	//シーン切り替え
	if (CheckHitKey(KEY_INPUT_SPACE) == TRUE)
	{
		//スペースキーが押されたらプレイシーンに切り替える

		//シーン初期化
		PlayInit();

		//シーン切り替え
		NowGameScene = PlayScene;

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
			"%s%s", GameSceneName[NowGameScene], "Init");
	}

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
	//シーン切り替え
	if (CheckHitKey(KEY_INPUT_SPACE) == TRUE)
	{
		//スペースキーが押されたらプレイシーンに切り替える

		//シーン初期化
		ResultInit();

		//シーン切り替え
		NowGameScene = ResultScene;

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
			"%s%s", GameSceneName[NowGameScene], "Init");
	}

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
	//シーン切り替え
	if (CheckHitKey(KEY_INPUT_SPACE) == TRUE)
	{
		//スペースキーが押されたらプレイシーンに切り替える

		//シーン初期化
		TitleInit();

		//シーン切り替え
		NowGameScene = TitleScene;

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
		//シーン名表示
		DrawFormatString(
			GameWidth - 200, 0,
			GetColor(255, 255, 255),
			"%s%s", GameSceneName[NowGameScene], "描画中");
	}

	return;
}