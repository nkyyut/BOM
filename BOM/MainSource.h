#pragma once

#include "DxLib.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

//ゲームモードの列挙型
enum GAME_MODE 
{ 
	GAME_TITLE, 
	GAME_INIT, 
	GAME_MAIN, 
	GAME_RESULT, 
	GAME_END = 99 
};

enum PLAYER_NUMBER
{
	PLAYER1,
	PLAYER2,
	PLAYER3,
	PLAYER4,
	PLAYER_LIMIT
};

//構造体の宣言
typedef struct StageState
{
	short int x;
	short int y;
	int blockimg;
	int bomimg;
	int timer;
}STAGE_STATE;

//定数の宣言
const short int STAGE_HEIGHT = 12;
const short int STAGE_WIDTH = 17;
const short int WINDOW_WIDTH = 850;
const short int WINDOW_HEIGHT = 650;

//変数の宣言
extern short int GameMode;
extern int NowKey[PLAYER_LIMIT];
extern int OldKey[PLAYER_LIMIT];
extern int KeyFlg[PLAYER_LIMIT];


//関数のプロトタイプ宣言
void GameStatInit();
int LoadImage();