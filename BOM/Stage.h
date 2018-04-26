#pragma once

#include "MainSorce.h"

//構造体の宣言
typedef struct StageState
{
	short int x;
	short int y;
	short int blockimg;
	short int bomimg;
	short int timer;
}STAGE_STATE;

//変数の宣言
extern int StageImage[3];
extern STAGE_STATE StageState[STAGE_HEIGHT][STAGE_WIDTH];

//関数のプロトタイプ宣言
void DrawStage();
int StageStateInit();