#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "myfunc.h"

int main(void)
{
	int num1, num2, ans;

	printf("‚P”Ô–Ú‚Ì®”");
	scanf("%d", &num1);

	printf("2”Ô–Ú‚Ì®”");
	scanf("%d", &num2);

	ans = max(num1, num2);

	printf("Å‘å’l‚Í%d‚Å‚·B\n", ans);

	return 0;
}