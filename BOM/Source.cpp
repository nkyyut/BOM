#include "Bom.h"
#define DEBUG

enum { GAME_TITLE, GAME_INIT, GAME_MAIN, GAME_RESULT, GAME_END = 99 } GAME_MODE;

//�u���b�N�̍\����
Block BlockStat[11][15];

int GameMode;
int MouseX, MouseY;
int NowKey;
int OldKey;
int KeyFlg;

void GameMain();//�Q�[�����C��
void GameInit();//�Q�[���̏�����

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	SetWindowSizeChangeEnableFlag(TRUE, TRUE);
	SetGraphMode(880, 660, 32);
	SetWindowSize(880, 660);

	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ŋN��

	if (DxLib_Init() == -1) return -1; // DX ���C�u�����̏���������

	SetDrawScreen(DX_SCREEN_BACK); // �`����ʂ𗠂ɂ���

	GameMode = GAME_INIT;//�Q�[�����[�h�̏�����

	// �Q�[�����[�v
	while (ProcessMessage() == 0 && GameMode != GAME_END) {


		#ifdef DEBUG 
		GetMousePoint(&MouseX, &MouseY); // �}�E�X�̈ʒu���擾
		OldKey = NowKey;
		NowKey = GetMouseInput();
		KeyFlg = NowKey & ~OldKey;
		if (KeyFlg & MOUSE_INPUT_LEFT) BlockStat[(MouseY-100) / 50][(MouseX-65) / 50].flg = 3;
		#endif

		ClearDrawScreen(); // ��ʂ̏�����

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

		ScreenFlip(); // ����ʂ̓��e��\��ʂɔ��f

	}

	DxLib_End(); // DX ���C�u�����g�p�̏I������

	return 0; // �\�t�g�̏I��
}
//�Q�[�����C��
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
//�Q�[���̏�����
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