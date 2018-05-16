#include "Stage.h"

//変数の宣言
int StageBlockCountH;
int StageBlockCountW;
short int Height;
short int Width;
int StageImage[3];
char LoadStatChar;
STAGE_STATE StageState[STAGE_HEIGHT][STAGE_WIDTH];
FILE *fp;

//ステージの読み込み
int LoadStageState()
{
#pragma warning(disable:4996)

	//ファイルオープン
	if ((fp = fopen("stage/stage.txt", "r")) == NULL) {

		//エラー処理
		printf("Stage Data Error\n");

		return -1;
	}

	for (Height = 0; Height < STAGE_HEIGHT; Height++)
	{
		for (Width = 0; Width < STAGE_WIDTH; Width++)
		{
			if ((LoadStatChar = fgetc(fp)) != '\n')
			{
				StageState[Height][Width].blockimg = LoadStatChar - '0';
			}else
			{
				LoadStatChar = fgetc(fp);
				StageState[Height][Width].blockimg = LoadStatChar - '0';
			}
		}
	}

	//ファイルクローズ
	fclose(fp);

	return 0;
}

//ステージの初期化
int StageStateInit()
{
	if (LoadStageState() == -1) return -1;

	for (Height = 0; Height < STAGE_HEIGHT; Height++)
	{
		for (Width = 0; Width < STAGE_WIDTH; Width++)
		{
			StageState[Height][Width].x = Width * 50 + 25;
			StageState[Height][Width].y = Height * 50 + 25;
			StageState[Height][Width].timer = 0;
			StageState[STAGE_HEIGHT][STAGE_WIDTH].bomimg = 0;
		}
	}

	//StageState[1][1].timer = 100;
	//StageState[1][1].PNumber = 2;

	return 0;
}

//ステージの描画
void DrawStage()
{
	for (StageBlockCountH = 1; StageBlockCountH < STAGE_HEIGHT - 1; StageBlockCountH++)
	{
		for (StageBlockCountW = 1; StageBlockCountW < STAGE_WIDTH - 1; StageBlockCountW++)
		{
			DrawRotaGraph(StageState[StageBlockCountH][StageBlockCountW].x,
				StageState[StageBlockCountH][StageBlockCountW].y, 1, 0,
				StageImage[StageState[StageBlockCountH][StageBlockCountW].blockimg], TRUE);

		}
	}
	for (int i = 0; i < STAGE_HEIGHT; i++)
	{
		for (int j = 0; j < STAGE_WIDTH; j++)
		{
			DrawFormatString(StageState[i][j].x,
				StageState[i][j].y, 0xffffff, "%d", StageState[i][j].blockimg);
		}
	}
}