#include <stdio.h>
int main()
{
	int n, x, y;
	scanf("%d", &n);
	x=n*800;
	y=n/15*200;
	printf("%d\n", x-y);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^