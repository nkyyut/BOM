#include "GameTitle.h"
#include "MainSource.h"

short int drawTimer;
short int drawTimrMax;
short int timerInitFlg;
short int checkSeen;
int StartSE;

void DrawTitle()
{
	if (timerInitFlg == 0)
	{
		timerInitFlg = TitleTimerInit();
	}

	SetFontSize(100);
	DrawString(120, 100, "BOMDER MAN", 0xffffff, FALSE);
	SetFontSize(40);

	if (drawTimer++ < drawTimrMax)
	{
		DrawString(230, 500, "--- SPACE KEY ---", 0xffffff, TRUE);
	}
	else if (drawTimer > drawTimrMax + (drawTimrMax / 2))
	{
		drawTimer = 0;
	}

	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		drawTimrMax = 4;
		drawTimer = 0;
		PlaySoundMem(StartSE, DX_PLAYTYPE_BACK, FALSE);
	}

	if (drawTimrMax == 4)
	{
		if (CheckSoundMem(StartSE) == 0)
		{
			GameMode = GAME_INIT;
			SetFontSize(20);
			checkSeen = 0;
			timerInitFlg = 0;
		}
		checkSeen++;
	}
}

int TitleTimerInit()
{
	drawTimer = 0;
	drawTimrMax = 50;

	return 1;
}