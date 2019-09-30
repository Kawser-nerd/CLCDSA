#include<stdio.h>

int main(void)
{
	int a;
	scanf("%d", &a);
	if (a == 111)
	{
		printf("999");
	}
	if (a == 119)
	{
		printf("991");
	}
	if (a == 191)
	{
		printf("919");
	}
	if (a == 199)
	{
		printf("911");
	}
	if (a == 911)
	{
		printf("199");
	}
	if (a == 919)
	{
		printf("191");
	}
	if (a == 991)
	{
		printf("119");
	}
	if (a == 999)
	{
		printf("111");
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &a);
  ^