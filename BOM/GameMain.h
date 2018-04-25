#pragma once

#include "MainSorce.h"
#include "Bom.h"
#include "PlayerControle.h"

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

//関数のプロトタイプ宣言
void DrawStage();
int StageStateInit();