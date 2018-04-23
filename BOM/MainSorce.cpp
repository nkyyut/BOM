#include "MainSorce.h"
#define DEBUG

enum { GAME_TITLE, GAME_INIT, GAME_MAIN, GAME_RESULT, GAME_END = 99 } GAME_MODE;

//�u���b�N�̍\����
Block BlockStat[11][15];

int GameMode;
int MouseX, MouseY;
int NowKey;
int OldKey;
int KeyFlg;
int Blockimg[7];

void GameMain();//�Q�[�����C��
void GameInit();//�Q�[���̏�����
int LoadImage();//�摜�̓ǂݍ���

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
		if (BlockStat[(MouseY - 100) / 50][(MouseX - 65) / 50].flg == 0)
		{
			if (KeyFlg & MOUSE_INPUT_LEFT) BlockStat[(MouseY - 100) / 50][(MouseX - 65) / 50].flg = 3;
		}
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
			DrawStage(&BlockStat[i][j], Blockimg, j, i);
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
			BlockInit(&BlockStat[i][j], j, i);
		}
	}

	if (LoadImage() == -1) GameMode = GAME_END;
}
//�摜�̓ǂݍ���
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