#include<stdio.h>

int main(void)
{
	int X,Y;

	scanf("%d %d",&X,&Y);

	printf("%d",X+(Y/2));

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&X,&Y);
  ^