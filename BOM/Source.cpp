#include "DxLib.h"
#include <stdlib.h>
#include <math.h>

typedef enum GAME_MODE{GAME_TITLE, GAME_INIT, GAME_MAIN, GAME_RESULT, GAME_END = 99};

int GameMode;

void GameMain();//ゲームメイン
void GameInit();//ゲームの初期化
void DrawStage();//ステージの描画

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1) return -1; // DX ライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK); // 描画先画面を裏にする

	GameMode = GAME_MAIN;//ゲームモードの初期化

	// ゲームループ
	while (ProcessMessage() == 0 && GameMode != GAME_END) {

		ClearDrawScreen(); // 画面の初期化

		switch(GameMode)
		{
			case GAME_TITLE:
				break;
			case GAME_INIT:
				GameInit();
				break;
			case GAME_MAIN:
				GameMain();
				break;
			case GAME_RESULT:
				break;
		}

		ScreenFlip(); // 裏画面の内容を表画面に反映

	}

	DxLib_End(); // DX ライブラリ使用の終了処理

	return 0; // ソフトの終了
}
//ゲームメイン
void GameMain()
{
	DrawStage();
}
//ゲームの初期化
void GameInit()
{
	GameMode = GAME_MAIN;
}
//ステージの描画
void DrawStage()
{

}