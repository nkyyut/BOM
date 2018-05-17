#include "PlayerControle.h"
#include "GameMain.h"
#include"Bom.h"

int BattleBGM;

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
}