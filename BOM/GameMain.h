#pragma once

#include "MainSorce.h"
#include "Bom.h"
#include "PlayerControle.h"

//�\���̂̐錾
typedef struct StageState
{
	short int x;
	short int y;
	short int blockimg;
	short int bomimg;
	short int timer;
}STAGE_STATE;

//�ϐ��̐錾
extern int StageImage[3];

//�֐��̃v���g�^�C�v�錾
void DrawStage();
int StageStateInit();