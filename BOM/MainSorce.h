#pragma once

#ifndef _BOM
#define _BOM

#include "DxLib.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

//�Q�[�����[�h�̗񋓌^
typedef enum GAME_MODE { GAME_TITLE, GAME_INIT, GAME_MAIN, GAME_RESULT, GAME_END = 99 } GAME_MODE;

//�萔�̐錾
const short int STAGE_WIDTH = 880;
const short int STAGE_HEIGHT = 660;

//�ϐ��̐錾
extern short int GameMode;

#endif//��x�ǂݖh�~����