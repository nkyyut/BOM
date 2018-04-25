#pragma once

#ifndef _BOM
#define _BOM

#include "DxLib.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

//ゲームモードの列挙型
typedef enum GAME_MODE { GAME_TITLE, GAME_INIT, GAME_MAIN, GAME_RESULT, GAME_END = 99 } GAME_MODE;

//定数の宣言
const short int STAGE_WIDTH = 880;
const short int STAGE_HEIGHT = 660;

//変数の宣言
extern short int GameMode;

#endif//二度読み防止処理