#include "PlayerControle.h"
#include "GameMain.h"
#include"Bom.h"

int BattleBGM;
short int gameTimer;
short int bomAmp;
short int drawFlg;
short int drawCount;

void GameMain()
{
	if (CheckSoundMem(BattleBGM) == 0)
	{
		PlaySoundMem(BattleBGM, DX_PLAYTYPE_BACK, TRUE);
	}

	DrawStage();
	DrawPlayer();
	DrawBom(*StageState);
	PlayerControl();

	if (GameMode == GAME_RESULT)
	{
		StopSoundMem(BattleBGM);
		gameTimer = 0;
		bomAmp = 0;
		drawFlg = 0;
		drawCount = 0;
	}

	if (gameTimer > 1000)
	{
		if (bomAmp < 6)
		{
			for (int i = 0; i < PLAYER_LIMIT; i++)
			{
				PlayerState[i].BPower++;
			}

			drawFlg = 1;
			bomAmp++;
		}

		gameTimer = 0;
		drawCount = 0;
	}

	if (drawFlg == 1)
	{
		SetFontSize(50);
		DrawString(250, 0, "ƒ{ƒ€‚ÌˆÐ—ÍUP!!", 0xff0000, true);
		SetFontSize(20);
		if (++drawCount > 300)
		{
			drawFlg = 0;
		}
	}

	gameTimer++;
}