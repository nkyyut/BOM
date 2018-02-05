#include "Bom.h"
#define DEBUG

enum { GAME_TITLE, GAME_INIT, GAME_MAIN, GAME_RESULT, GAME_END = 99 } GAME_MODE;

//ブロックの構造体
Block BlockStat[11][15];

int GameMode;
int MouseX, MouseY;
int NowKey;
int OldKey;
int KeyFlg;

void GameMain();//ゲームメイン
void GameInit();//ゲームの初期化

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetWindowSizeChangeEnableFlag(TRUE, TRUE);
	SetGraphMode(880, 660, 32);
	SetWindowSize(880, 660);

	ChangeWindowMode(TRUE); // ウィンドウモードで起動

	if (DxLib_Init() == -1) return -1; // DX ライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK); // 描画先画面を裏にする

	GameMode = GAME_INIT;//ゲームモードの初期化

	// ゲームループ
	while (ProcessMessage() == 0 && GameMode != GAME_END) {


		#ifdef DEBUG 
		GetMousePoint(&MouseX, &MouseY); // マウスの位置を取得
		OldKey = NowKey;
		NowKey = GetMouseInput();
		KeyFlg = NowKey & ~OldKey;
		if (KeyFlg & MOUSE_INPUT_LEFT) BlockStat[(MouseY-100) / 50][(MouseX-65) / 50].flg = 3;
		#endif

		ClearDrawScreen(); // 画面の初期化

		DrawFormatString(0, 0, 0xffffff, "X:%d  Y:%d", MouseX, MouseY);

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
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 15; j++) 
		{
			DrawStage(&BlockStat[i][j]);
		}
	}
}
//ゲームの初期化
void GameInit()
{	
	GameMode = GAME_MAIN;
	
	for (int i = 0; i < 11; i++) 
	{
		for (int j = 0; j < 15; j++) 
		{
			if(BlockInit(&BlockStat[i][j], j, i) == -1) GAME_MODE = GAME_END;
		}
	}
}