#pragma once

#include "MainSource.h"

struct PLAYER
{
	short int x, y;
	short int wx, hy;
	short int Pnumber;
	short int BCount;
	short int BPower;
	short int PSpeed;
	short int img;
	bool Alive;
};

const short int PLAYER_HEIGHT = 70;
const short int PLAYER_WIDTH = 45;

extern PLAYER PlayerState[PLAYER_LIMIT];

void PlayerControl();
void PlayerStateInit();
void DrawPlayer();
bool CheckBombSet(short int BombStock,short int Px,short int Py);
void BombSet(short int Bpower, short int PNumber, short int playery, short int playerx);