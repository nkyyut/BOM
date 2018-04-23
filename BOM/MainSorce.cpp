#include "MainSorce.h"
#include "Bom.h"
#include "PlayerControle.h"
#define DEBUG

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetWindowSizeChangeEnableFlag(TRUE, TRUE);
	SetGraphMode(880, 660, 32);
	SetWindowSize(880, 660);

	ChangeWindowMode(TRUE); // ウィンドウモードで起動

	if (DxLib_Init() == -1) return -1; // DX ライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK); // 描画先画面を裏にする

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
	Bomber = LoadGraph("image/bomberman1.png");

	return 0;
}