#include <stdio.h>

typedef struct {
	int HP;         //HP
	int MP;         //MP
	int Money;      //������
	int Exp;        //�o���l
}SaveData_t;

int main() {
	SaveData_t Data = { 200, 100, 1000, 1000 };
	FILE *fp = fopen("�Z�[�u�f�[�^.dat", "wb");//�o�C�i���t�@�C�����J��
	if (fp == NULL) {//�G���[���N������NULL��Ԃ�
		return 0;
	}
	fwrite(&Data, sizeof(Data), 1, fp); // SaveData_t�\���̂̒��g���o��
	fclose(fp);//�t�@�C�������
	return 0;
}