#include <stdio.h>

int main(void)
{
	int x;
	scanf("%d",&x);
	if(x < 1200)
		{printf("ABC");}
	else
		{printf("ARC");}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&x);
  ^