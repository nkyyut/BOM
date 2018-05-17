#include "Result.h"
#include "MainSource.h"
#include "PlayerControle.h"

short int playerCount;
short int serch;
short int winer;
short int selectSeen;
int titleColor;
int replayColor;
int Mousex, Mousey;
int SpaceKeyFlg;
int OldSpaceKeyFlg;
int NowSpaceKeyFlg;

void SerchWiner(void)
{ 
	for (serch = PLAYER1; serch < PLAYER_LIMIT; serch++)
	{
		if (PlayerState[serch].Alive == true) 
		{
			winer = serch;
			serch = PLAYER_LIMIT;
			break;
		}
	}
}

void GameResult(void)
{

	//GetMousePoint(&Mousex, &Mousey);
	OldSpaceKeyFlg = NowSpaceKeyFlg;
	NowSpaceKeyFlg = CheckHitKey(KEY_INPUT_SPACE);
	SpaceKeyFlg = NowSpaceKeyFlg & ~OldSpaceKeyFlg;
 
	if (serch != PLAYER_LIMIT)
	{
		selectSeen = GAME_TITLE;
		titleColor = 0x0000ff;
		replayColor = 0x000000;
		SerchWiner();
	}

	//DrawFormatString(Mousex, Mousey, 0xffffff, "%d, %d", Mousex, Mousey, TRUE);

	SetFontSize(100);
	DrawFormatString(240, 100, 0xffffff, "%dPLAYER", winer + 1, true);
	SetFontSize(60);

	DrawString(350, 40, "WINER", 0xff0000, true);
	DrawString(200, 350, "TITLE", titleColor, true);
	DrawString(500, 345, "REPLAY", replayColor, true);

	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		selectSeen = GAME_TITLE;
		titleColor = 0x0000ff;
		replayColor = 0x000000;
	}

	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		selectSeen = GAME_INIT;
		titleColor = 0x000000;
		replayColor = 0x0000ff;
	}

	if (SpaceKeyFlg)
	{
		GameMode = selectSeen;
	}

	//GameMode = GAME_TITLE;
}