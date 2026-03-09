#include "DxLib.h"

//マクロ定義　//マジックナンバー(急に出てくる数字)を定義する
#define GameWidth 1280				// ゲームの横幅
#define GameHeight 720				// ゲームの縦幅  //ctrl + dで同じ行を複製する
#define GameColor   32				// ゲームの色
#define GameTitle "Title"			//画面タイトル
#define GameVSync TRUE				//V-Syncを使うならTRUE
#define GameIcon   555				//画面アイコン

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

	// Initialize the library
	if (DxLib_Init() == -1) {
		return -1; // Initialization failed
	}

	//裏画面に描画する（ダブルバッファリング）
	SetDrawScreen(DX_SCREEN_BACK);

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

			//文字を画面に出力
			DrawString(0, 0, "Helllo DxLib", GetColor(255, 255, 255));
		}
	}

	DxLib_End(); // Clean up and exit
	return 0;  //ソフト終了
}