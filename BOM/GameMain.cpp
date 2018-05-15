#include "PlayerControle.h"
#include "GameMain.h"


void GameMain()
{
	DrawStage();
	DrawBom(*StageState);
	DrawPlayer();
	PlayerControl();
}