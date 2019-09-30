#include <stdio.h>

int main(void)
{
	int r,g,p;
	
	scanf("%d\n%d",&r,&g);
	
	p=g*2-r;
	
	printf("%d\n",p);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n%d",&r,&g);
  ^