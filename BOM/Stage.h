#pragma once

#include "MainSource.h"

//�萔�̐錾
//int TIMELIMIT[5] = {3600,7200,10800,14400,18000};

//�ϐ��̐錾
extern int StageImage[3];
extern STAGE_STATE StageState[STAGE_HEIGHT][STAGE_WIDTH];

//�֐��̃v���g�^�C�v�錾
void DrawStage();
int StageStateInit();
int LoadStageState();