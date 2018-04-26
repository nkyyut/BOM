#pragma once

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

struct PLAYER PlayerState[PLAYER_LIMIT];

void PlayerControl();
void PlayerStateInit();
bool CheckBombSet();
void BombSet(short int Bpower, short int PNumber);