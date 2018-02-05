#pragma once
#include <stdio.h>
#include "DxLib.h"

//ブロックの構造体
typedef struct Block
{
	int x;
	int y;
	int img[7];
	int bomTimer;
	int flg;
}Block;

void DrawStage(Block *BlockStat, int x, int y);
int BlockInit(Block *BlockStat, int x, int y);