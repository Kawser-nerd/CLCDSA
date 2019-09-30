#include <stdio.h>
int main(void)
{
	int x,y,t;
	scanf("%d%d",&x, &y);
	t = y / x;
	printf("%d\n", t);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&x, &y);
  ^