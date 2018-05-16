#include "MainSource.h"
#include "PlayerControle.h"
#include"Stage.h"

int Playerimg[2];
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
			PlayerState[i].img = 0;
		}
		else
		{
			PlayerState[i].x = 700;
			PlayerState[i].img = 1;
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
		PlayerState[i].BCount = STATE_INIT+3;
		PlayerState[i].BPower = STATE_INIT;
		PlayerState[i].PSpeed = STATE_INIT+2;
		PlayerState[i].Pnumber = i;
		PlayerState[i].Alive = true;
	}
	Playerimg[0] = LoadGraph("image/bomberman1.png");
	Playerimg[1] = LoadGraph("image/bomberman2.png");
	GameMode = GAME_MAIN;
}

void PlayerControl()
{
	for (int i = PLAYER1; i < PLAYER_LIMIT; i++)
	{
		if (PlayerState[i].Alive == true) 
		{
			if (NowKey[i] & PAD_INPUT_UP)
			{
				PlayerState[i].y -= PlayerState[i].PSpeed;
				PlayerState[i].hy -= PlayerState[i].PSpeed;
				if (StageState[(PlayerState[i].y + 50) / 50][(PlayerState[i].x + 25) / 50].blockimg != 0 || 
					(StageState[(PlayerState[i].y + 50) / 50][(PlayerState[i].x + 25) / 50].bomflg == true &&
					StageState[(PlayerState[i].hy) / 50][(PlayerState[i].x + 25) / 50].bomflg != true))
				{
					PlayerState[i].y += PlayerState[i].PSpeed;
					PlayerState[i].hy += PlayerState[i].PSpeed;
				}
				else if (StageState[(PlayerState[i].y + 50) / 50][(PlayerState[i].x + 25) / 50].bomimg != 0)
				{
					PlayerState[i].Alive = false;
				}
			}

			if (NowKey[i] & PAD_INPUT_DOWN)
			{
				PlayerState[i].y += PlayerState[i].PSpeed;
				PlayerState[i].hy += PlayerState[i].PSpeed;
				if (StageState[PlayerState[i].hy / 50][(PlayerState[i].x + 25) / 50].blockimg != 0 ||
					(StageState[(PlayerState[i].hy - 35) / 50 +1][(PlayerState[i].x + 25) / 50].bomflg == true &&
					StageState[(PlayerState[i].hy) / 50][(PlayerState[i].x + 25) / 50].bomflg != true))
				{
					PlayerState[i].y -= PlayerState[i].PSpeed;
					PlayerState[i].hy -= PlayerState[i].PSpeed;
				}
				else if (StageState[PlayerState[i].hy / 50][(PlayerState[i].x + 25) / 50].bomimg != 0)
				{
					PlayerState[i].Alive = false;
				}
			}

			if (NowKey[i] & PAD_INPUT_LEFT)
			{
				PlayerState[i].x -= PlayerState[i].PSpeed;
				PlayerState[i].wx -= PlayerState[i].PSpeed;
				if (StageState[(PlayerState[i].y + 50) / 50][PlayerState[i].x / 50].blockimg != 0 || 
					(StageState[(PlayerState[i].y + 50) / 50][(PlayerState[i].x-10) / 50].bomflg == true &&
						StageState[(PlayerState[i].y + 50) / 50][PlayerState[i].x / 50].bomflg != true))
				{
					PlayerState[i].x += PlayerState[i].PSpeed;
					PlayerState[i].wx += PlayerState[i].PSpeed;
				}
				else if (StageState[(PlayerState[i].y + 50) / 50][PlayerState[i].x / 50].bomimg != 0)
				{
					PlayerState[i].Alive = false;
				}
			}

			if (NowKey[i] & PAD_INPUT_RIGHT)
			{
				PlayerState[i].x += PlayerState[i].PSpeed;
				PlayerState[i].wx += PlayerState[i].PSpeed;
				if (StageState[(PlayerState[i].y + 50) / 50][(PlayerState[i].wx) / 50].blockimg != 0 ||
					(StageState[(PlayerState[i].y + 50) / 50][(PlayerState[i].wx+10) / 50 +1].bomflg == true &&
						StageState[(PlayerState[i].y + 50) / 50][(PlayerState[i].wx) / 50].bomflg != true))
				{
					PlayerState[i].x -= PlayerState[i].PSpeed;
					PlayerState[i].wx -= PlayerState[i].PSpeed;
				}
				else if (StageState[(PlayerState[i].y + 50) / 50][PlayerState[i].wx / 50].bomimg != 0)
				{
					PlayerState[i].Alive = false;
				}
			}

			if (KeyFlg[i] & PAD_INPUT_A)
			{
				if (CheckBombSet(PlayerState[i].BCount, PlayerState[i].x, PlayerState[i].y) == true)
				{
					BombSet(PlayerState[i].BPower, PlayerState[i].Pnumber,
						(PlayerState[i].y + 50) / 50, (PlayerState[i].x + 25) / 50);
				}
			}
			if (StageState[(PlayerState[i].y + 50) / 50][(PlayerState[i].x + 25) / 50].bomimg != 0)
			{
				PlayerState[i].Alive = false;
			}

		}
	}
	DrawPlayer();
	if (KeyFlg[PLAYER1] & PAD_INPUT_START)
	{
		GameMode = GAME_INIT;
	}
}

void DrawPlayer()
{
	for (int i = PLAYER1; i < PLAYER_LIMIT; i++)
	{
		if (PlayerState[i].Alive == true)
		{
			DrawGraph(PlayerState[i].x, PlayerState[i].y, Playerimg[PlayerState[i].img], TRUE);
			DrawFormatString(PlayerState[i].x, PlayerState[i].y, 0x00ff00, "%d",PlayerState[i].BCount);
		}
		DrawBox(PlayerState[i].x, PlayerState[i].y+50, PlayerState[i].wx, PlayerState[i].hy, 0xff0000, FALSE);
	}
}

bool CheckBombSet(short int BombStock,short int Px,short int Py)
{
	if (BombStock != 0 && StageState[(Px+25)/50][(Py+50)/50].bomflg == false)
	{
		return true;
	}

	return false;
}

void BombSet(short int Bpower, short int PNumber,short int playery,short int playerx)
{
	StageState[playery][playerx].PNumber = PNumber;
	StageState[playery][playerx].timer = 100;
	StageState[playery][playerx].bomflg = true;
	PlayerState[PNumber].BCount--;

}
