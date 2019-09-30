#include <stdio.h>

int main(void)
{
	int Y;
	scanf("%d", &Y);
	if (Y % 400 == 0) puts("YES");
	else if (Y % 100 == 0) puts("NO");
	else if (Y % 4 == 0) puts("YES");
	else puts("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &Y);
  ^