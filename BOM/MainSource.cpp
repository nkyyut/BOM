#include "MainSource.h"
#include"Bom.h"
#include"GameBattleInit.h"
#include"GameMain.h"
#include"PlayerControle.h"
#include"GameTitle.h"
#include "Result.h"

#define DEBUG

//変数の宣言
short int GameMode;
int MouseX, MouseY;
int NowKey[PLAYER_LIMIT];
int OldKey[PLAYER_LIMIT];
int KeyFlg[PLAYER_LIMIT];

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetWindowSizeChangeEnableFlag(TRUE, TRUE);
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32);
	SetWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	ChangeWindowMode(TRUE); // ウィンドウモードで起動

	SetMainWindowText("BONDER MAN");

	if (DxLib_Init() == -1) return -1; // DX ライブラリの初期化処理

	SetDrawScreen(DX_SCREEN_BACK); // 描画先画面を裏にする

	GameMode = GAME_TITLE;//ゲームモードの初期化

	#ifdef DEBUG
		//GameMode = GAME_MAIN;
	#endif // DEBUG

	if (LoadImage() == -1) GameMode = GAME_END;

	if(StageStateInit() == -1) GameMode = GAME_END;

	// ゲームループ
	while (ProcessMessage() == 0 && GameMode != GAME_END) {

		ClearDrawScreen(); // 画面の初期化

		for (int i = PLAYER1; i < PLAYER_LIMIT; i++)
		{
			OldKey[i] = NowKey[i];
		}
		
		NowKey[PLAYER1] = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		NowKey[PLAYER2] = GetJoypadInputState(DX_INPUT_PAD2);
		NowKey[PLAYER3] = GetJoypadInputState(DX_INPUT_PAD3);
		NowKey[PLAYER4] = GetJoypadInputState(DX_INPUT_PAD4);
	
		for (int i = PLAYER1; i < PLAYER_LIMIT; i++)
		{
			KeyFlg[i] = NowKey[i] & ~OldKey[i];
		}

		switch(GameMode)
		{
			case GAME_TITLE:
				DrawTitle();
				break;
			case GAME_INIT:
				StageStateInit();
				PlayerStateInit();
				break;
			case GAME_MAIN:
				GameMain();
				break;
			case GAME_RESULT:
				GameResult();
				break;
		}

		DxLib::ScreenFlip(); // 裏画面の内容を表画面に反映

	}

	DxLib_End(); // DX ライブラリ使用の終了処理

	return 0; // ソフトの終了
}
//ゲームの初期化
void GameStatInit()
{	
	GameMode = GAME_MAIN;
	
}
//画像の読み込み
int LoadImage()
{
	if ((StageImage[0] = LoadGraph("image/BlockImage.png")) == -1) return -1;
	if ((StageImage[1] = LoadGraph("image/BlockImage1.png")) == -1) return -1;
	if ((StageImage[2] = LoadGraph("image/BlockImage2.png")) == -1) return -1;

	if ((BomImage[0] = LoadGraph("image/Bom.png")) == -1) return -1;
	if ((BomImage[1] = LoadGraph("image/BomEffect.png")) == -1) return -1;
	if ((BomImage[2] = LoadGraph("image/BomEffect1.png")) == -1) return -1;
	if ((BomImage[3] = LoadGraph("image/BomEffect2.png")) == -1) return -1;

	if ((ExprotionSE = LoadSoundMem("sounds/bomb1.mp3")) == -1) return -1;
	if ((StartSE = LoadSoundMem("sounds/nc26818.mp3")) == -1) return -1;
	if ((BattleBGM = LoadSoundMem("sounds/solid_infinity.mp3")) == -1) return -1;

	return 0;
}