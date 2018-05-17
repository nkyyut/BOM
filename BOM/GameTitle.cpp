#include "GameTitle.h"
#include "MainSource.h"

short int drawTimer;
short int drawTimerMax;
short int timerInitFlg;
int StartSE;

void DrawTitle()
{
	OldSpaceKeyFlg = NowSpaceKeyFlg;
	NowSpaceKeyFlg = CheckHitKey(KEY_INPUT_SPACE);
	SpaceKeyFlg = NowSpaceKeyFlg & ~OldSpaceKeyFlg;

	if (timerInitFlg == 0)
	{
		timerInitFlg = TitleTimerInit();
	}

	SetFontSize(100);
	DrawString(150, 100, "BOMDER MAN", 0xffffff, FALSE);
	SetFontSize(40);

	if (drawTimer++ < drawTimerMax)
	{
		DrawString(230, 500, "--- SPACE KEY ---", 0xffffff, TRUE);
	}
	else if (drawTimer > drawTimerMax + (drawTimerMax / 2))
	{
		drawTimer = 0;
	}

	if (SpaceKeyFlg)
	{
		drawTimerMax = 4;
		drawTimer = 0;
		PlaySoundMem(StartSE, DX_PLAYTYPE_BACK, FALSE);
	}

	if (drawTimerMax == 4)
	{
		if (CheckSoundMem(StartSE) == 0)
		{
			GameMode = GAME_INIT;
			SetFontSize(20);
			timerInitFlg = 0;
		}
	}
}

int TitleTimerInit()
{
	drawTimer = 0;
	drawTimerMax = 50;

	return 1;
}