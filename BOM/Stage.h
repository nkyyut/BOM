#pragma once
#include <stdio.h>
#include "DxLib.h"

//�u���b�N�̍\����
typedef struct Block
{
	int x;
	int y;
	int img[2];
	int flg;
}Block;

void DrawStage(Block *BlockStat);
int BlockInit(Block *BlockStat, int x, int y);