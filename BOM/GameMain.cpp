#include "GameMain.h"

//変数の宣言
short int Height;
short int Width;
int StageImage[3];
STAGE_STATE StageState[STAGE_HEIGHT][STAGE_WIDTH];

//ステージの初期化
int StageStateInit()
{
	for (Height = 0; Height < STAGE_HEIGHT; Height++) 
	{
		for (Width = 0; Width < STAGE_WIDTH; Width++)
		{
			StageState[Height][Width].x = Width * 50 + 50;
			StageState[Height][Width].y = Height * 50 + 50;

			if (Height == 0 || Height == (STAGE_HEIGHT - 1))
			{
				StageState[Height][Width].blockimg = 99;
				StageState[Height][Width].bomimg = 99;
			}
			else if (Width == 0 || Width == (STAGE_WIDTH - 1))
			{
				StageState[Height][Width].blockimg = 99;
				StageState[Height][Width].bomimg = 99;
			}
			else
			{
				if (Height / 2 == 0 || Width / 2 == 0)
				{
					StageState[Height][Width].blockimg = 1;
					StageState[Height][Width].bomimg = 0;
				}
				else
				{
					StageState[Height][Width].blockimg = rand();
					StageState[Height][Width].bomimg = rand();
				}
			}
		}
	}

	return 0;
}

//ステージの描画
void DrawStage()
{
}