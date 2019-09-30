#include <stdio.h>

int main(void)
{
	int zahyou = 0, x, i ;
	scanf("%d", &x);
	for(i = 0; zahyou < x ; i++) zahyou += i;
	printf("%d\n", i - 1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &x);
  ^