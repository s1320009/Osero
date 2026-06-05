//フォントのヘッダファイル
#pragma once

//ヘッダファイル読み込み
#include "DxLib2.h"

//フォントのパスと名前

//外部フォント
#define FontPathJiyu ".\\font\\Jiyucho.ttf"	//フリーフォント「じゆうちょう」のパスと名前
#define FontNameJiyu "じゆうちょうフォント"	//フリーフォント「じゆうちょう」のパスと名前

//内部フォント
#define FontNameMSMincho "ＭＳ 明朝"	//Windowsに標準で入っている「ＭＳ 明朝」の名前

//デフォルトのフォント
#define FontDefName		FontNameMSMincho				//デフォルトのフォントは「ＭＳ 明朝」
#define FontDefSize		20								//デフォルトのフォントサイズは20
#define FontDefThinck	1								//デフォルトのフォントの太さは1
#defint FontDefType		DX_FONTTYPE_ANTIALIASING_8X8	//デフォルトのフォントの種類はアンチエイリアス8x8

//文字列の長さ
#define FontNameStrMax  256	//フォントの名前の文字列の最大値
#define FontErrStrMax   512	//エラー値の文字列の最大値