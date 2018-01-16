#define _CRT_SECURE_NO_WARNINGS
#define NULL 0
#define NUM 5
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *f;
	int test[NUM];
	int i, j;

	f = fopen("text.bin", "rb");

	if (f == NULL) {
		printf("error");
		return -1;
	}

	for (i = 0; i < NUM; i++) {
		fread(&test[i], sizeof(int), 1, f);
	}

	for (j = 0; j < NUM; j++) {
		printf("%d\n", test[j]);
	}

	fclose(f);

	return 0;
}