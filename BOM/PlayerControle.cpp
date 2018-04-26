#include "PlayerControle.h"

void PlayerStateInit()
{	
	const int STATE_INIT = 2;

	for (int i = PLAYER1; i < PLAYER_LIMIT;)
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
}

void PlayerControl()
{

}