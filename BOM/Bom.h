#pragma once
#include <stdio.h>
#include "DxLib.h"
#include "GameMain.h"

//�ϐ��̐錾
extern int BomImage[4];

typedef struct BomBlast
{
	int timer;
	short int image;
	short int x;
	short int y;
	short int angle;
	short int flg;
}BomBlast;

typedef enum CheckBlastType
{
	SENTER,
	UP,
	DOWN,
	LEFT,
	RIGHT
}CheckBlastType;

//�֐��̃v���g�^�C�v�錾
int CheckBlast(STAGE_STATE *StagePointer, CheckBlastType checkBlastType);
//int CheckBlastUp(STAGE_STATE *StagePointer);
//int CheckBlastDown(STAGE_STATE *StagePointer);
//int CheckBlastLeft(STAGE_STATE *StagePointer);
//int CheckBlastRight(STAGE_STATE *StagePointer);
//void BlastAnimation();
void DrawBom(STAGE_STATE *StagePointer);
//int CheckBlastStat(short int img, short int x, short int y, short int angle);