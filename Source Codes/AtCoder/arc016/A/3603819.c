#include <stdio.h>

int main(void)
{
	int M;
	scanf("%*d%d", &M);
	if (M == 1) puts("2");
	else puts("1");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%*d%d", &M);
  ^