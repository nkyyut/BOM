#include "Stage.h"
 
//�X�e�[�W�̕`��
void DrawStage(Block *BlockStat) 
{
	int MouseX, MouseY;
	GetMousePoint(&MouseX, &MouseY); // �}�E�X�̈ʒu���擾
	DrawFormatString(0, 0, 0xffffff, "X:%d  Y:%d", MouseX, MouseY);
	DrawRotaGraph(BlockStat -> x, BlockStat -> y, 1, 0, BlockStat -> img, TRUE);
	DrawLine(0, 100, 880, 100, 0xffffff);
	DrawLine(65, 100, 65, 650, 0xffffff);
	DrawLine(0, 650, 880, 650, 0xffffff);
	DrawLine(815, 100, 815, 650, 0xffffff);
}

//�u���b�N�̃X�e�[�^�X������
int BlockInit(Block *BlockStat, int x, int y) 
{
	BlockStat->x = x * 50 + 90;
	BlockStat->y = y * 50 + 125;
	if((x % 2 == 1 && y % 2 == 0) && (BlockStat->img = LoadGraph("image/BlockImage.png")) == -1) return -1;

	if (x % 2 == 0 && y % 2 == 1) BlockStat->flg = 0;//�ʍs�\�s�̃t���O�̏�����
	else BlockStat->flg = 1;

	return 0;
}