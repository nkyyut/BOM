#include "Bom.h"
 
CheckBlastType checkBlastType;

//ïœêîÇÃêÈåæ
int BomImage[4];
short int blastCountI;
short int blastCountJ;
short int checkBlastI;
short int checkBlastJ;
BomBlast bomBlast[10][15];

void DrawBom(STAGE_STATE *StagePointer)
{
	for (int i = 0; i < STAGE_HEIGHT; i++)
	{
		for (int j = 0; j < STAGE_WIDTH; j++)
		{
			if (StagePointer->timer > 1)
			{
				DrawRotaGraph(StagePointer->x, StagePointer->y,
					1, 0, BomImage[0], TRUE);
				StagePointer->timer--;
			}else if (StagePointer->timer == 1)
			{
				CheckBlast(StagePointer, SENTER);
				StagePointer->timer = 0;
			}

			StagePointer++;
		}
	}
}

int CheckBlast(STAGE_STATE *StagePointer, CheckBlastType checkBlastType)
{
	switch (checkBlastType)
	{
		case SENTER:
			CheckBlastStat(1, StagePointer->x, StagePointer->y, 0);

			if ((StagePointer - 17)->blockimg == 2 || (StagePointer - 17)->blockimg == 0)
			{
				CheckBlast(StagePointer - 17, UP);
			}
			if ((StagePointer + 17)->blockimg == 2 || (StagePointer + 17)->blockimg == 0)
			{
				CheckBlast(StagePointer + 17, DOWN);
			}
			if ((StagePointer + 1)->blockimg == 2 || (StagePointer + 1)->blockimg == 0)
			{
				CheckBlast(StagePointer + 1, RIGHT);
			}
			if ((StagePointer - 1)->blockimg == 2 || (StagePointer - 1)->blockimg == 0)
			{
				CheckBlast(StagePointer - 1, LEFT);
			}
			break;
		case UP:
			CheckBlastStat(3, StagePointer->x, StagePointer->y, 0);

			StagePointer->blockimg = 0;
			if ((StagePointer - 17)->blockimg == 2 || (StagePointer - 17)->blockimg == 0)
			{
				CheckBlast(StagePointer - 17 , UP);
			}
			break;
		case DOWN:
			CheckBlastStat(3, StagePointer->x, StagePointer->y, 0);

			StagePointer->blockimg = 0;
			if ((StagePointer + 17)->blockimg == 2 || (StagePointer + 17)->blockimg == 0)
			{
				CheckBlast(StagePointer + 17, DOWN);
			}
			break;
		case RIGHT:
			CheckBlastStat(2, StagePointer->x, StagePointer->y, 0);

			StagePointer->blockimg = 0;
			if ((StagePointer + 1)->blockimg == 2 || (StagePointer + 1)->blockimg == 0)
			{
				CheckBlast(StagePointer + 1, RIGHT);
			}
			break;
		case LEFT:
			CheckBlastStat(2, StagePointer->x, StagePointer->y, 0);

			StagePointer->blockimg = 0;
			if ((StagePointer - 1)->blockimg == 2 || (StagePointer - 1)->blockimg == 0)
			{
				CheckBlast(StagePointer - 1, LEFT);
			}
			break;
	}

	return 0;
}
//
//int CheckBlastUp(STAGE_STATE *StagePointer)
//{
//	for (blastCountI = 0; blastCountI < 10; blastCountI++)
//	{
//		for (blastCountJ = 0; blastCountJ < 15; blastCountJ++)
//		{
//			if (bomBlast[blastCountI][blastCountJ].image == 0)
//			{
//				bomBlast[blastCountI][blastCountJ].image = 2;
//				bomBlast[blastCountI][blastCountJ].x = StagePointer->x;
//				bomBlast[blastCountI][blastCountJ].y = StagePointer->y;
//				bomBlast[blastCountI][blastCountJ].count = 300;
//				bomBlast[blastCountI][blastCountJ].angel = 0;
//				break;
//			}
//		}
//	}
//
//	if ((StagePointer - 17)->blockimg == 2 || (StagePointer - 17)->blockimg == 0)
//	{
//		StagePointer->blockimg = 0;
//		CheckBlastUp(StagePointer - 17);
//	}
//
//	return 0;
//}
//
//int CheckBlastDown(STAGE_STATE *StagePointer)
//{
//	for (blastCountI = 0; blastCountI < 10; blastCountI++)
//	{
//		for (blastCountJ = 0; blastCountJ < 15; blastCountJ++)
//		{
//			if (bomBlast[blastCountI][blastCountJ].image == 0)
//			{
//				bomBlast[blastCountI][blastCountJ].image = 2;
//				bomBlast[blastCountI][blastCountJ].x = StagePointer->x;
//				bomBlast[blastCountI][blastCountJ].y = StagePointer->y;
//				bomBlast[blastCountI][blastCountJ].count = 300;
//				bomBlast[blastCountI][blastCountJ].angel = 0;
//				break;
//			}
//		}
//	}
//
//	if ((StagePointer + 17)->blockimg == 2 || (StagePointer + 17)->blockimg == 0)
//	{
//		StagePointer->blockimg = 0;
//		CheckBlastDown(StagePointer + 17);
//	}
//
//	return 0;
//}
//
//int CheckBlastLeft(STAGE_STATE *StagePointer)
//{
//	for (blastCountI = 0; blastCountI < 10; blastCountI++)
//	{
//		for (blastCountJ = 0; blastCountJ < 15; blastCountJ++)
//		{
//			if (bomBlast[blastCountI][blastCountJ].image == 0)
//			{
//				bomBlast[blastCountI][blastCountJ].image = 2;
//				bomBlast[blastCountI][blastCountJ].x = StagePointer->x;
//				bomBlast[blastCountI][blastCountJ].y = StagePointer->y;
//				bomBlast[blastCountI][blastCountJ].count = 300;
//				bomBlast[blastCountI][blastCountJ].angel = 90;
//				break;
//			}
//		}
//	}
//
//	if ((StagePointer - 1)->blockimg == 2 || (StagePointer - 1)->blockimg == 0)
//	{
//		StagePointer->blockimg = 0;
//		CheckBlastLeft(StagePointer - 1);
//	}
//
//	return 0;
//}
//
//int CheckBlastRight(STAGE_STATE *StagePointer)
//{
//	for (blastCountI = 0; blastCountI < 10; blastCountI++)
//	{
//		for (blastCountJ = 0; blastCountJ < 15; blastCountJ++)
//		{
//			if (bomBlast[blastCountI][blastCountJ].image == 0)
//			{
//				bomBlast[blastCountI][blastCountJ].image = 2;
//				bomBlast[blastCountI][blastCountJ].x = StagePointer->x;
//				bomBlast[blastCountI][blastCountJ].y = StagePointer->y;
//				bomBlast[blastCountI][blastCountJ].count = 300;
//				bomBlast[blastCountI][blastCountJ].angel = 270;
//				break;
//			}
//		}
//	}
//
//	if ((StagePointer + 1)->blockimg == 2 || (StagePointer + 1)->blockimg == 0)
//	{
//		StagePointer->blockimg = 0;
//		CheckBlastRight(StagePointer + 1);
//	}
//
//	return 0;
//}

void BlastAnimation()
{
	for (blastCountI = 0; blastCountI < 10; blastCountI++)
	{
		for (blastCountJ = 0; blastCountJ < 15; blastCountJ++)
		{
			if (bomBlast[blastCountI][blastCountJ].flg == 1 && 
				bomBlast[blastCountI][blastCountJ].timer > 1)
			{
				DrawRotaGraph(bomBlast[blastCountI][blastCountJ].x,
					bomBlast[blastCountI][blastCountJ].y, 1,
					bomBlast[blastCountI][blastCountJ].angle,
					BomImage[bomBlast[blastCountI][blastCountJ].image], TRUE);
				bomBlast[blastCountI][blastCountJ].timer--;
			}else
			{
				bomBlast[blastCountI][blastCountJ].flg = 0;
				bomBlast[blastCountI][blastCountJ].image = 0;
			}
		}
	}
}

int CheckBlastStat(short int img, short int x, short int y, short int angle)
{
	for (checkBlastI = 0; checkBlastI < 10; checkBlastI++)
	{
		for (checkBlastJ = 0; checkBlastJ < 15; checkBlastJ++)
		{
			if (bomBlast[checkBlastI][checkBlastJ].flg == 0)
			{
				bomBlast[checkBlastI][checkBlastJ].image = img;
				bomBlast[checkBlastI][checkBlastJ].timer = 50;
				bomBlast[checkBlastI][checkBlastJ].x = x;
				bomBlast[checkBlastI][checkBlastJ].y = y;
				bomBlast[checkBlastI][checkBlastJ].angle = angle;
				bomBlast[checkBlastI][checkBlastJ].flg = 1;
				return 1;
			}
		}
	}

	return 0;
}