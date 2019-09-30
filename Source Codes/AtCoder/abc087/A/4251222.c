#include <stdio.h>

int main(void)
{
	int x,a,b;
	scanf("%d%d%d",&x,&a,&b);
	int m=(x-a)/b;
	int rest = x-a-m*b;
	printf("%d\n",rest);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&x,&a,&b);
  ^