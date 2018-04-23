#include "Bom.h"
 
//ステージの描画
void DrawStage(Block *BlockStat, int *BlockimgP, int x, int y)
{
	DrawRotaGraph(BlockStat -> x, BlockStat -> y, 1, 0, BlockimgP[BlockStat -> flg], TRUE);

	if ((BlockStat->flg == 3) && ++(*BlockStat).bomTimer >= 60)//爆弾の爆破
	{
		BlockStat->flg = 4;
		BlockStat->bomTimer = 0;
		if (x != 14 && ((BlockStat + 1)->flg == 0 || (BlockStat + 1)->flg == 2) || (BlockStat + 1)->flg == 3)
		{
			if ((BlockStat + 1)->flg == 3) (BlockStat + 1)->bomTimer = 60;
			else (BlockStat + 1)->flg = 5;
		}
		if (x != 0 && ((BlockStat - 1)->flg == 0 || (BlockStat - 1)->flg == 2) || (BlockStat - 1)->flg == 3)
		{
			if ((BlockStat - 1)->flg == 3) (BlockStat - 1)->bomTimer = 60;
			else (BlockStat - 1)->flg = 5;
		}
		if (y != 10 && ((BlockStat + 15)->flg == 0 || (BlockStat + 15)->flg == 2) || (BlockStat + 15)->flg == 3)
		{
			if ((BlockStat + 15)->flg == 3) (BlockStat + 15)->bomTimer = 60;
			else (BlockStat + 15)->flg = 6;
		}
		if (y != 0 && ((BlockStat - 15)->flg == 0 || (BlockStat - 15)->flg == 2) || (BlockStat - 15)->flg == 3)
		{
			if ((BlockStat - 15)->flg == 3) (BlockStat - 15)->bomTimer = 60;
			else (BlockStat - 15)->flg = 6;
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

//ブロックのステータス初期化
void BlockInit(Block *BlockStat, int x, int y)
{
	BlockStat->bomTimer = 0;
	BlockStat->x = x * 50 + 90;
	BlockStat->y = y * 50 + 125;
	BlockStat->flg = 0;

	if (x % 2 == 1 && y % 2 == 1)//ハードブロックの配置
	{
		BlockStat->flg = 1;
	}
	else if (GetRand(1) == 1)//ソフトブロックの配置
	{
		BlockStat->flg = 2;
	}
	else
	{
		BlockStat->flg = 0;
	}

	if ((y == 0 || y == 10) && (x == 0 || x == 1 || x == 13 || x == 14)) //キャラクターの初期位置を初期化
	{
		BlockStat->flg = 0;
	}
	else if ((y == 1 || y == 9) && (x == 0 || x == 14))
	{
		BlockStat->flg = 0;
	}
}