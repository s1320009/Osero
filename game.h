//ゲーム処理のヘッダファイル
#pragma once

//ヘッダファイル読み込み
#include "DxLib.h"

//マクロ定義　//マジックナンバー(急に出てくる数字)を定義する
#define GameWidth 1280				// ゲームの横幅
#define GameHeight 720				// ゲームの縦幅  //ctrl + dで同じ行を複製する
#define GameColor   32				// ゲームの色
#define GameTitle "Title"			//画面タイトル
#define GameVSync TRUE				//V-Syncを使うならTRUE
#define GameIcon   555				//画面アイコン

#define GameDebug TRUE				//デバッグモード（TRUEならデバッグ用の処理をする）

#define GameSceneCount		3		//シーンの数
#define GameSceneNameMax	20		//シーンの文字数MAX

#define GameSceneChangeFrame 60	//シーン切り替えにかかるフレーム数

//列挙型

//ゲームシーン
enum GameScene {
	TitleScene, //タイトルシーン
	PlayScene,  //プレイシーン
	ResultScene //リザルトシーン
};

//外部のグローバル変数
extern enum GameScene NowGameScene; //現在のゲームシーン
extern enum GameScene ChangeGameScene; //切り替えるゲームシーン

//外部のプロトタイプ宣言
extern VOID TitleInit(VOID);	//タイトル初期化
extern VOID TitleCtrl(VOID);	//タイトル管理
extern VOID TitleProc(VOID);	//タイトル処理
extern VOID TitleDraw(VOID);	//タイトル描画

extern VOID PlayInit(VOID);		//プレイ初期化
extern VOID PlayCtrl(VOID);		//プレイ管理
extern VOID PlayProc(VOID);		//プレイ処理
extern VOID PlayDraw(VOID);		//プレイ描画

extern VOID ResultInit(VOID);	//リザルト初期化
extern VOID ResultCtrl(VOID);	//リザルト管理
extern VOID ResultProc(VOID);	//リザルト処理
extern VOID ResultDraw(VOID);	//リザルト描画