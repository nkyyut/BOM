#include "MainSorce.h"
#include "GameMain.h"

//変数の宣言
short int GameMode = GAME_MAIN;
int MouseX, MouseY;
int NowKey;
int OldKey;
int KeyFlg;
int Blockimg[7];

void GameMain();//ゲームメイン
void GameInit();//ゲームの初期化

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetWindowSizeChangeEnableFlag(TRUE, TRUE);
	SetGraphMode(STAGE_WIDTH, STAGE_HEIGHT, 32);
	SetWindowSize(STAGE_WIDTH, STAGE_HEIGHT);

	ChangeWindowMode(TRUE); // ウィンドウモードで起動

	if (DxLib_Init() == -1) return -1; // DX ライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK); // 描画先画面を裏にする

	GameMode = GAME_INIT;//ゲームモードの初期化

	// ゲームループ
	while (ProcessMessage() == 0 && GameMode != GAME_END) {

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
			DrawStage(&BlockStat[i][j], Blockimg, j, i);
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
			BlockInit(&BlockStat[i][j], j, i);
		}
	}

	if (LoadImage() == -1) GameMode = GAME_END;
}
//画像の読み込み
int LoadImage()
{
	if ((Blockimg[0] = LoadGraph("image/BlockImage.png")) == -1) return -1;
	if ((Blockimg[1] = LoadGraph("image/BlockImage1.png")) == -1) return -1;
	if ((Blockimg[2] = LoadGraph("image/BlockImage2.png")) == -1) return -1;
	if ((Blockimg[3] = LoadGraph("image/Bom.png")) == -1) return -1;
	if ((Blockimg[4] = LoadGraph("image/BomEffect.png")) == -1) return -1;
	if ((Blockimg[5] = LoadGraph("image/BomEffect1.png")) == -1) return -1;
	if ((Blockimg[6] = LoadGraph("image/BomEffect2.png")) == -1) return -1;

	return 0;
}