#include <stdio.h>

int main(void)
{
	int cur,aft;
	scanf("%d%d",&cur,&aft);
	int time = (cur + aft%24)%24;
	printf("%d",time);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&cur,&aft);
  ^