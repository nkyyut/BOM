#pragma once
#include <stdio.h>
#include "DxLib.h"

//ブロックの構造体
typedef struct Block
{
	int x;
	int y;
	int bomTimer;
	int flg;
}Block;

//変数の宣言
extern int BomImage[2];
extern int StageImage[3];

void DrawStage(Block *BlockStat, int *BlockimgP, int x, int y);
void BlockInit(Block *BlockStat, int x, int y);