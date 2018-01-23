#pragma once
#include <stdio.h>
#include "DxLib.h"

//ブロックの構造体
typedef struct Block
{
	int x;
	int y;
	int img;
	bool flg;
}Block;

void DrawStage(Block *BlockStat);
int BlockInit(Block *BlockStat, int x, int y);