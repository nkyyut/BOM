#include "Stage.h"
 
//�X�e�[�W�̕`��
void DrawStage(Block *BlockStat) 
{
		DrawRotaGraph(BlockStat -> x, BlockStat -> y, 1, 0, BlockStat -> img, TRUE);
}

//�u���b�N�̃X�e�[�^�X������
int BlockInit(Block *BlockStat, int x, int y) 
{
	BlockStat-> x = x * 50 + 25;
	BlockStat->y = y * 50 + 110;
	if((x % 2 == 0 && y % 2 == 0) && (BlockStat->img = LoadGraph("image/BlockImage.png")) == -1) return -1;

	return 0;
}