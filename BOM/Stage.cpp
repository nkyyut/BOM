#include "Stage.h"
 
//�X�e�[�W�̕`��
void DrawStage(Block *BlockStat, int x, int y) 
{
	DrawRotaGraph(BlockStat -> x, BlockStat -> y, 1, 0, BlockStat -> img[BlockStat -> flg], TRUE);

	if ((BlockStat->flg == 3) && ++(*BlockStat).bomTimer == 60)//���e�̔��j
	{
		BlockStat->flg = 4;
		BlockStat->bomTimer = 0;
		if (x != 14 && ((BlockStat+1) -> flg == 0 || (BlockStat + 1)->flg == 2))
		{
			(BlockStat + 1)->flg = 5;
		}
		if (x != 0 && ((BlockStat - 1)->flg == 0 || (BlockStat - 1)->flg == 2))
		{
			(BlockStat - 1)->flg = 5;
		}
		if (y != 10 && ((BlockStat + 15)->flg == 0 || (BlockStat + 15)->flg == 2))
		{
			(BlockStat + 15)->flg = 6;
		}
		if (y != 0 && ((BlockStat - 15)->flg == 0 || (BlockStat - 15)-> flg == 2))
		{
			(BlockStat - 15)->flg = 6;
		}
	}
	else if ((BlockStat->flg >= 4) && ++(*BlockStat).bomTimer > 10)
	{
		BlockStat->bomTimer = 0;
		BlockStat->flg = 0;
	}

	DrawLine(0, 100, 880, 100, 0xffffff);
	DrawLine(65, 100, 65, 650, 0xffffff);
	DrawLine(0, 650, 880, 650, 0xffffff);
	DrawLine(815, 100, 815, 650, 0xffffff);
}

//�u���b�N�̃X�e�[�^�X������
int BlockInit(Block *BlockStat, int x, int y) 
{
	BlockStat->bomTimer = 0;
	BlockStat->x = x * 50 + 90;
	BlockStat->y = y * 50 + 125;
	BlockStat->flg = 0;

	if ((BlockStat->img[0] = LoadGraph("image/BlockImage.png")) == -1) return -1;
	if ((BlockStat->img[1] = LoadGraph("image/BlockImage1.png")) == -1) return -1;
	if ((BlockStat->img[2] = LoadGraph("image/BlockImage2.png")) == -1) return -1;
	if ((BlockStat->img[3] = LoadGraph("image/Bom.png")) == -1) return -1;
	if ((BlockStat->img[4] = LoadGraph("image/BomEffect.png")) == -1) return -1;
	if ((BlockStat->img[5] = LoadGraph("image/BomEffect1.png")) == -1) return -1;
	if ((BlockStat->img[6] = LoadGraph("image/BomEffect2.png")) == -1) return -1;

	if (x % 2 == 1 && y % 2 == 1)//�n�[�h�u���b�N�̔z�u
	{
		BlockStat->flg = 1;
	}
	else if (GetRand(1) == 1)//�\�t�g�u���b�N�̔z�u
	{
		BlockStat->flg = 2;
	}
	else
	{
		BlockStat->flg = 0;
	}

	if ((y == 0 || y == 10) && (x == 0 || x == 1 || x == 13 || x == 14)) //�L�����N�^�[�̏����ʒu��������
	{
		BlockStat->flg = 0;
	}
	else if ((y == 1 || y == 9) && (x == 0 || x == 14))
	{
		BlockStat->flg = 0;
	}

	return 0;
}