#pragma once

#include "MainSource.h"

//定数の宣言
//int TIMELIMIT[5] = {3600,7200,10800,14400,18000};

//変数の宣言
extern int StageImage[3];
extern STAGE_STATE StageState[STAGE_HEIGHT][STAGE_WIDTH];

//関数のプロトタイプ宣言
void DrawStage();
int StageStateInit();
int LoadStageState();