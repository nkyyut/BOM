#pragma once
#include <stdio.h>
#include "DxLib.h"

//�u���b�N�̍\����
typedef struct Block
{
	int x;
	int y;
	int bomTimer;
	int flg;
}Block;

//�ϐ��̐錾
extern int BomImage[2];
extern int StageImage[3];

void DrawStage(Block *BlockStat, int *BlockimgP, int x, int y);
void BlockInit(Block *BlockStat, int x, int y);