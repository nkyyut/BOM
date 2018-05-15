#pragma once

#include "MainSource.h"

//変数の宣言
extern int StageImage[3];
extern STAGE_STATE StageState[STAGE_HEIGHT][STAGE_WIDTH];

//関数のプロトタイプ宣言
void DrawStage();
int StageStateInit();
int LoadStageState();