#include "Bom.h"
#include "PlayerControle.h"
 
CheckBlastType checkBlastType;

//ïœêîÇÃêÈåæ
int BomImage[4];
short int TimerSort;
int ExprotionSE;
short int BomTimer[20];

void DrawBom(STAGE_STATE *StagePointer)
{
	for (int i = 0; i < STAGE_HEIGHT; i++)
	{
		for (int j = 0; j < STAGE_WIDTH; j++)
		{
			if (StagePointer->timer > 1)
			{
				DrawRotaGraph(StagePointer->x, StagePointer->y,
					1, 0, BomImage[StagePointer->bomimg], TRUE);
				StagePointer->timer--;
			}
			else if (StagePointer->timer == 1)
			{
				CheckBlast(StagePointer, SENTER, PlayerState[StagePointer->PNumber].BPower);
				StagePointer->timer = 0;
				StagePointer->bomflg = false;
				PlayerState[StagePointer->PNumber].BCount++;
				PlaySoundMem(ExprotionSE, DX_PLAYTYPE_BACK, TRUE);
			}
			else if (StagePointer->bomimg > 0)
			{
				if (StagePointer->bomEfectTimer > 0)
				{
					DrawRotaGraph(StagePointer->x, StagePointer->y,
						1, 0, BomImage[StagePointer->bomimg], TRUE);
					StagePointer->bomEfectTimer--;
				}
				else
				{
					StagePointer->bomimg = 0;
				}
			}

			StagePointer++;
		}
	}
}

int CheckBlast(STAGE_STATE *StagePointer, CheckBlastType checkBlastType, short int power)
{
	switch (checkBlastType)
	{
	case SENTER:
		StagePointer->bomEfectTimer = 50;

		StagePointer->bomimg = 1;

		if ((StagePointer - 17)->blockimg == 2 || (StagePointer - 17)->blockimg == 0)
		{
			if ((StagePointer - 17)->bomimg == 0)
			{
				CheckBlast(StagePointer - 17, UP, power - 1);
			}
		}
		if ((StagePointer + 17)->blockimg == 2 || (StagePointer + 17)->blockimg == 0)
		{
			if ((StagePointer + 17)->bomimg == 0)
			{
				CheckBlast(StagePointer + 17, DOWN, power - 1);
			}
		}
		if ((StagePointer + 1)->blockimg == 2 || (StagePointer + 1)->blockimg == 0)
		{
			if ((StagePointer + 1)->bomimg == 0)
			{
				CheckBlast(StagePointer + 1, RIGHT, power - 1);
			}
		}
		if ((StagePointer - 1)->blockimg == 2 || (StagePointer - 1)->blockimg == 0)
		{
			if ((StagePointer - 1)->bomimg == 0)
			{
				CheckBlast(StagePointer - 1, LEFT, power - 1);
			}
		}
		break;
	case UP:
		if ((StagePointer - 17)->bomimg > 0) break;

		StagePointer->bomEfectTimer = 50;

		StagePointer->bomimg = 3;

		if (StagePointer->blockimg == 2)
		{
			StagePointer->blockimg = 0;
			break;
		}

		if (StagePointer->timer > 1)
		{
			StagePointer->timer = 1;
			break;
		}

		StagePointer->blockimg = 0;
		if (power > 0 && ((StagePointer - 17)->blockimg == 2 || (StagePointer - 17)->blockimg == 0))
		{
			CheckBlast(StagePointer - 17, UP, power - 1);
		}
		break;
	case DOWN:
		if ((StagePointer + 17)->bomimg > 0) break;

		StagePointer->bomEfectTimer = 50;

		StagePointer->bomimg = 3;

		if (StagePointer->blockimg == 2)
		{
			StagePointer->blockimg = 0;
			break;
		}

		if (StagePointer->timer > 1)
		{
			StagePointer->timer = 1;
			break;
		}

		StagePointer->blockimg = 0;
		if (power > 0 && ((StagePointer + 17)->blockimg == 2 || (StagePointer + 17)->blockimg == 0))
		{
			CheckBlast(StagePointer + 17, DOWN, power - 1);
		}
		break;
	case RIGHT:
		if ((StagePointer + 1)->bomimg > 0) break;

		StagePointer->bomEfectTimer = 50;

		StagePointer->bomimg = 2;

		if (StagePointer->blockimg == 2)
		{
			StagePointer->blockimg = 0;
			break;
		}

		if (StagePointer->timer > 1)
		{
			StagePointer->timer = 1;
			break;
		}

		StagePointer->blockimg = 0;
		if (power > 0 && ((StagePointer + 1)->blockimg == 2 || (StagePointer + 1)->blockimg == 0))
		{
			CheckBlast(StagePointer + 1, RIGHT, power - 1);
		}
		break;
	case LEFT:
		if ((StagePointer - 1)->bomimg > 0) break;

		StagePointer->bomEfectTimer = 50;

		StagePointer->bomimg = 2;

		if (StagePointer->blockimg == 2)
		{
			StagePointer->blockimg = 0;
			break;
		}

		if (StagePointer->timer > 1)
		{
			StagePointer->timer = 1;
			break;
		}

		StagePointer->blockimg = 0;
		if (power > 0 && ((StagePointer - 1)->blockimg == 2 || (StagePointer - 1)->blockimg == 0))
		{
			CheckBlast(StagePointer - 1, LEFT, power - 1);
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

//void BlastAnimation()
//{
//	for (blastCountI = 0; blastCountI < 10; blastCountI++)
//	{
//		for (blastCountJ = 0; blastCountJ < 15; blastCountJ++)
//		{
//			if (bomBlast[blastCountI][blastCountJ].flg == 1 && 
//				bomBlast[blastCountI][blastCountJ].timer > 1)
//			{
//				DrawRotaGraph(bomBlast[blastCountI][blastCountJ].x,
//					bomBlast[blastCountI][blastCountJ].y, 1,
//					bomBlast[blastCountI][blastCountJ].angle,
//					BomImage[bomBlast[blastCountI][blastCountJ].image], TRUE);
//				bomBlast[blastCountI][blastCountJ].timer--;
//			}else
//			{
//				bomBlast[blastCountI][blastCountJ].flg = 0;
//				bomBlast[blastCountI][blastCountJ].image = 0;
//			}
//		}
//	}
//}

//int CheckBlastStat(short int img, short int x, short int y, short int angle)
//{
//	for (checkBlastI = 0; checkBlastI < 10; checkBlastI++)
//	{
//		for (checkBlastJ = 0; checkBlastJ < 15; checkBlastJ++)
//		{
//			if (bomBlast[checkBlastI][checkBlastJ].flg == 0)
//			{
//				bomBlast[checkBlastI][checkBlastJ].image = img;
//				bomBlast[checkBlastI][checkBlastJ].timer = 50;
//				bomBlast[checkBlastI][checkBlastJ].x = x;
//				bomBlast[checkBlastI][checkBlastJ].y = y;
//				bomBlast[checkBlastI][checkBlastJ].angle = angle;
//				bomBlast[checkBlastI][checkBlastJ].flg = 1;
//				return 1;
//			}
//		}
//	}
//
//	return 0;
//}