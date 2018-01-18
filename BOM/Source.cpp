#include "DxLib.h"
#include <stdlib.h>
#include <math.h>
#include "Stage.h"

enum { GAME_TITLE, GAME_INIT, GAME_MAIN, GAME_RESULT, GAME_END = 99 } GAME_MODE;

int GameMode;

void GameMain();//�Q�[�����C��
void GameInit();//�Q�[���̏�����

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetWindowSize(880, 660);
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ŋN��

	if (DxLib_Init() == -1) return -1; // DX ���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK); // �`����ʂ𗠂ɂ���

	GameMode = GAME_MAIN;//�Q�[�����[�h�̏�����

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && GameMode != GAME_END) {

		ClearDrawScreen(); // ��ʂ̏�����

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

		ScreenFlip(); // ����ʂ̓��e��\��ʂɔ��f

	}

	DxLib_End(); // DX ���C�u�����g�p�̏I������

	return 0; // �\�t�g�̏I��
}
//�Q�[�����C��
void GameMain()
{
	DrawStage();
}
//�Q�[���̏�����
void GameInit()
{
	GameMode = GAME_MAIN;
}