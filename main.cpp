#include "DxLib.h"
#include "fps.h"
#include "game.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);			//Log.txtを作成しないように設定
	ChangeWindowMode(TRUE);							//ウィンドウモードに設定 
	SetGraphMode(GameWidth, GameHeight, GameColor); //解像度を1280x720、色数を32ビットに設定
	SetWindowSize(GameWidth, GameHeight);			//ウィンドウサイズを1280x720に設定
	SetMainWindowText(GameTitle);					//ウィンドウタイトルを設定
	SetBackgroundColor(0, 0, 0);					//背景色を黒に設定
	SetWaitVSyncFlag(GameVSync);					//垂直同期を設定
	SetAlwaysRunFlag(TRUE);							//ウィンドウがアクティブでないときも処理を続行する);
	SetWindowIconID(GameIcon);						//アイコン					
	SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8);

	// Initialize the library
	if (DxLib_Init() == -1) {
		return -1; // Initialization failed
	}

	//裏画面に描画する（ダブルバッファリング）
	SetDrawScreen(DX_SCREEN_BACK);

	//FPS初期化
	FPSInit();

	//最初のシーンはタイトルから
	NowGameScene = TitleScene;

	//無限ループ（ゲームループ）
	while (TRUE)
	{
		//メッセージ処理をする（マウス操作やキー入力などを受け続ける）
		if (ProcessMessage() != 0)
		{
			break; // 無限ループから出る(ゲーム終了)
		}

		//画面を消去する（１ループずつ書き換える）
		if (ClearDrawScreen() != 0)
		{
			break; // 無限ループから出る(ゲーム終了)
		}

		//ここに全てのゲームの動作が入る
		{
			FPSCheck(); //FPS計測

			//シーン切り替え
			switch (NowGameScene)
			{
			case TitleScene:
				TitleCtrl();
				break;
			case PlayScene:
				PlayCtrl();
				break;
			case ResultScene:
				ResultCtrl();
				break;
			default:
				break;
			}

			FPSDraw();  //FPS描画
			FPSWait();  //FPS待機
		}

		//裏画面の内容を表画面に反映させる
		ScreenFlip();
	}

	DxLib_End(); // Clean up and exit

	return 0;  //ソフト終了
}