#pragma once

#include "DxLib.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

//�Q�[�����[�h�̗񋓌^
typedef enum GAME_MODE { GAME_TITLE, GAME_INIT, GAME_MAIN, GAME_RESULT, GAME_END = 99 } GAME_MODE;

//�萔�̐錾
const short int STAGE_WIDTH = 17;
const short int STAGE_HEIGHT = 13;
const short int WINDOW_WIDTH = 850;
const short int WINDOW_HEIGHT = 650;

//�ϐ��̐錾
extern short int GameMode;

enum PLAYER_NUMBER
{
	PLAYER1,
	PLAYER2,
	PLAYER3,
	PLAYER4,
	PLAYER_LIMIT
};

//�֐��̃v���g�^�C�v�錾
void GameStatInit();
int LoadImage();