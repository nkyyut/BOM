#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "myfunc.h"

int main(void)
{
	int num1, num2, ans;

	printf("�P�Ԗڂ̐���");
	scanf("%d", &num1);

	printf("2�Ԗڂ̐���");
	scanf("%d", &num2);

	ans = max(num1, num2);

	printf("�ő�l��%d�ł��B\n", ans);

	return 0;
}