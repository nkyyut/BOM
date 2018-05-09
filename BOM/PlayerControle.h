#pragma once

#include "MainSource.h"

struct PLAYER
{
	short int x, y;
	short int w, h;
	short int Pnumber;
	short int BCount;
	short int BPower;
	short int PSpeed;
	short int img;
	bool Alive;
};

void PlayerControl();
void PlayerStateInit();
void DrawPlayer();
bool CheckBombSet();
void BombSet(short int Bpower, short int PNumber);