#include "Stage.h"

//変数の宣言
short int Height;
short int Width;
int StageImage[3];
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
			fscanf(fp, "%hd", &StageState[Height][Width].blockimg);
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

	for (Height = 1; Height < (STAGE_HEIGHT - 1); Height++)
	{
		for (Width = 1; Width < (STAGE_WIDTH - 1); Width++)
		{
			StageState[Height][Width].x = Width * 50 + 50;
			StageState[Height][Width].y = Height * 50 + 50;
			StageState[Height][Width].bomimg = 0;
			StageState[Height][Width].timer = 0;
		}
	}

	return 0;
}

//ステージの描画
void DrawStage()
{
}