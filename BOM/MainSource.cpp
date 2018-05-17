#include "MainSource.h"
#include"Bom.h"
#include"GameBattleInit.h"
#include"GameMain.h"
#include"PlayerControle.h"
#include"GameTitle.h"
#include "Result.h"

#define DEBUG

//�ϐ��̐錾
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

	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ŋN��

	SetMainWindowText("BONDER MAN");

	if (DxLib_Init() == -1) return -1; // DX ���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK); // �`����ʂ𗠂ɂ���

	GameMode = GAME_TITLE;//�Q�[�����[�h�̏�����

	#ifdef DEBUG
		//GameMode = GAME_MAIN;
	#endif // DEBUG

	if (LoadImage() == -1) GameMode = GAME_END;

	if(StageStateInit() == -1) GameMode = GAME_END;

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && GameMode != GAME_END) {

		ClearDrawScreen(); // ��ʂ̏�����

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

		DxLib::ScreenFlip(); // ����ʂ̓��e��\��ʂɔ��f

	}

	DxLib_End(); // DX ���C�u�����g�p�̏I������

	return 0; // �\�t�g�̏I��
}
//�Q�[���̏�����
void GameStatInit()
{	
	GameMode = GAME_MAIN;
	
}
//�摜�̓ǂݍ���
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