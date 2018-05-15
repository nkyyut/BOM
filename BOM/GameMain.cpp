#include "PlayerControle.h"
#include "GameMain.h"
#include"Bom.h"


void GameMain()
{
	DrawStage();
	DrawPlayer();
	DrawBom(*StageState);
	BlastAnimation();
	PlayerControl();
}