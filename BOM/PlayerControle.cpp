#include "MainSource.h"
#include "PlayerControle.h"

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
			PlayerState[i].x = 100;
		}
		else
		{
			PlayerState[i].x = 650;
		}

		if (i < 2)
		{
			PlayerState[i].y = 100;
		}
		else
		{
			PlayerState[i].y = 650;
		}

		PlayerState[i].w = 50;
		PlayerState[i].h = 100;
		PlayerState[i].BCount = STATE_INIT;
		PlayerState[i].BPower = STATE_INIT;
		PlayerState[i].PSpeed = STATE_INIT;
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
		}
		if (NowKey[i] & PAD_INPUT_DOWN)
		{
			PlayerState[i].y += PlayerState[i].PSpeed;
		}
		if (NowKey[i] & PAD_INPUT_LEFT)
		{
			PlayerState[i].x -= PlayerState[i].PSpeed;
		}
		if (NowKey[i] & PAD_INPUT_RIGHT)
		{
			PlayerState[i].x += PlayerState[i].PSpeed;
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
