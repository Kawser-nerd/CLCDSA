#include<stdio.h>
int main(void)
{
	int x,y;
	scanf("%d %d",&x,&y);
	printf("%d\n",y/2+x);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&x,&y);
  ^