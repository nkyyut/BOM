#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "myfunc.h"

int main(void)
{
	int num1, num2, ans;

	printf("１番目の整数");
	scanf("%d", &num1);

	printf("2番目の整数");
	scanf("%d", &num2);

	ans = max(num1, num2);

	printf("最大値は%dです。\n", ans);

	return 0;
}