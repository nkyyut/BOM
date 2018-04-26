#include "GameMain.h"

//•Ï”‚ÌéŒ¾
short int StageHeightCount;
short int StageWideCount;

void GameMain()
{
	for (StageHeightCount = 0; StageHeightCount < STAGE_HEIGHT; StageHeightCount++)
	{
		for (StageWideCount = 0; StageWideCount < STAGE_WIDTH; StageWideCount++)
		{
			DrawGraph("");
		}
	}
}