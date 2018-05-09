#pragma once

#include "MainSource.h"

//�\���̂̐錾
typedef struct StageState
{
	short int x;
	short int y;
	int blockimg;
	int bomimg;
	int timer;
}STAGE_STATE;

//�ϐ��̐錾
extern int StageImage[3];
extern STAGE_STATE StageState[STAGE_HEIGHT][STAGE_WIDTH];

//�֐��̃v���g�^�C�v�錾
void DrawStage();
int StageStateInit();
int LoadStageState();