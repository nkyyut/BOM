#include <stdio.h>

typedef struct {
	int HP;         //HP
	int MP;         //MP
	int Money;      //所持金
	int Exp;        //経験値
}SaveData_t;

int main() {
	SaveData_t Data = { 200, 100, 1000, 1000 };
	FILE *fp = fopen("セーブデータ.dat", "wb");//バイナリファイルを開く
	if (fp == NULL) {//エラーが起きたらNULLを返す
		return 0;
	}
	fwrite(&Data, sizeof(Data), 1, fp); // SaveData_t構造体の中身を出力
	fclose(fp);//ファイルを閉じる
	return 0;
}