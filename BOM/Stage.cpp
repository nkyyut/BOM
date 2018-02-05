#include "Stage.h"
 
//ステージの描画
void DrawStage(Block *BlockStat) 
{
	if(BlockStat -> flg != 3) DrawRotaGraph(BlockStat -> x, BlockStat -> y, 1, 0, BlockStat -> img[0], TRUE);
	if(BlockStat -> flg == 3) DrawRotaGraph(BlockStat->x, BlockStat->y, 1, 0, BlockStat->img[1], TRUE);
	DrawLine(0, 100, 880, 100, 0xffffff);
	DrawLine(65, 100, 65, 650, 0xffffff);
	DrawLine(0, 650, 880, 650, 0xffffff);
	DrawLine(815, 100, 815, 650, 0xffffff);
}

//ブロックのステータス初期化
int BlockInit(Block *BlockStat, int x, int y) 
{
	BlockStat->x = x * 50 + 90;
	BlockStat->y = y * 50 + 125;
	BlockStat->flg = 0;

	if (x % 2 == 1 && y % 2 == 1)//ハードブロックの配置
	{
		if ((BlockStat->img[0] = LoadGraph("image/BlockImage.png")) == -1) return -1;
		BlockStat->flg = 1;
	}
	else if((BlockStat ->img[1] = LoadGraph("image/Bom.png")) != -1)//爆弾のイメージを初期化
	{
		if (GetRand(1) == 1)//ソフトブロックの配置
		{
			if ((BlockStat->img[0] = LoadGraph("image/BlockImage1.png")) == -1) return -1;
			BlockStat->flg = 2;
		}
		else
		{
			if ((BlockStat->img[0] = LoadGraph("image/BlockImage2.png")) == -1) return -1;
			BlockStat->flg = 0;
		}
	}
	else return -1;

	if ((y == 0 || y == 10) && (x == 0 || x == 1 || x == 13 || x == 14)) //キャラクターの初期位置を初期化
	{
		if ((BlockStat->img[0] = LoadGraph("image/BlockImage2.png")) == -1) return -1;
		BlockStat->flg = 0;
	}
	else if ((y == 1 || y == 9) && (x == 0 || x == 14))
	{
		if ((BlockStat->img[0] = LoadGraph("image/BlockImage2.png")) == -1) return -1;
		BlockStat->flg = 0;
	}

	return 0;
}