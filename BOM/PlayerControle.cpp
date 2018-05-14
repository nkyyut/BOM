#include "MainSource.h"
#include "PlayerControle.h"
#include"Stage.h"

int Playerimg;
bool Initflg;
struct PLAYER PlayerState[PLAYER_LIMIT];

void PlayerStateInit()
{	
	const int STATE_INIT = 2;

	for (int i = PLAYER1; i < PLAYER_LIMIT; i++)
	{
		if (i % 2 == 0)
		{
			PlayerState[i].x = 50;
		}
		else
		{
			PlayerState[i].x = 700;
		}

		if (i < 2)
		{
			PlayerState[i].y = 50;
		}
		else
		{
			PlayerState[i].y = 500;
		}

		PlayerState[i].wx = PlayerState[i].x + PLAYER_WIDTH;
		PlayerState[i].hy = PlayerState[i].y + PLAYER_HEIGHT;
		PlayerState[i].BCount = STATE_INIT;
		PlayerState[i].BPower = STATE_INIT;
		PlayerState[i].PSpeed = STATE_INIT+2;
		PlayerState[i].img = 1;
		PlayerState[i].Alive = true;
	}
	Playerimg = LoadGraph("image/bomberman1.png");
	GameMode = GAME_MAIN;
}

void PlayerControl()
{
	for (int i = PLAYER1; i < PLAYER_LIMIT; i++)
	{
		if (NowKey[i] & PAD_INPUT_UP)
		{
			PlayerState[i].y -= PlayerState[i].PSpeed;
			PlayerState[i].hy -= PlayerState[i].PSpeed;
			if (StageState[(PlayerState[i].y + 50) / 50][(PlayerState[i].x + 25) / 50].blockimg != 0)
			{
				PlayerState[i].y += PlayerState[i].PSpeed;
				PlayerState[i].hy += PlayerState[i].PSpeed;
			}
		}
		if (NowKey[i] & PAD_INPUT_DOWN)
		{
			PlayerState[i].y += PlayerState[i].PSpeed;
			PlayerState[i].hy += PlayerState[i].PSpeed;
			if (StageState[PlayerState[i].hy / 50][(PlayerState[i].x + 25) / 50].blockimg != 0)
			{
				PlayerState[i].y -= PlayerState[i].PSpeed;
				PlayerState[i].hy -= PlayerState[i].PSpeed;
			}
		}
		if (NowKey[i] & PAD_INPUT_LEFT)
		{
			PlayerState[i].x -= PlayerState[i].PSpeed;
			PlayerState[i].wx -= PlayerState[i].PSpeed;
			if (StageState[(PlayerState[i].y + 50) / 50][PlayerState[i].x / 50].blockimg != 0)
			{
				PlayerState[i].x += PlayerState[i].PSpeed;
				PlayerState[i].wx += PlayerState[i].PSpeed;
			}
		}
		if (NowKey[i] & PAD_INPUT_RIGHT)
		{
			PlayerState[i].x += PlayerState[i].PSpeed;
			PlayerState[i].wx += PlayerState[i].PSpeed;
			if (StageState[(PlayerState[i].y + 50) / 50][PlayerState[i].wx / 50].blockimg != 0)
			{
				PlayerState[i].x -= PlayerState[i].PSpeed;
				PlayerState[i].wx -= PlayerState[i].PSpeed;
			}
		}
		if (KeyFlg[i] & PAD_INPUT_A)
		{
			if (CheckBombSet((PlayerState[i].y+50)/50,(PlayerState[i].x+25)/50) == true)
			{
				BombSet(PlayerState[i].BPower, PlayerState[i].Pnumber, (PlayerState[i].y + 50)/50, (PlayerState[i].x + 25)/50);
				PlayerState[i].BCount--;
			}
		}

	}

	DrawPlayer();
}

void DrawPlayer()
{
	for (int i = PLAYER1; i < PLAYER_LIMIT; i++)
	{
		DrawGraph(PlayerState[i].x, PlayerState[i].y, Playerimg, TRUE);
	}
}

bool CheckBombSet(short int playery,short int playerx)
{
	if (StageState[playery][playerx].bomimg == 0)
	{
		return true;
	}

	return false;
}

void BombSet(short int Bpower, short int PNumber,short int playery,short int playerx)
{
	StageState[playery][playerx].bomimg = 1;
	StageState[playery][playerx].timer = 0;
}
