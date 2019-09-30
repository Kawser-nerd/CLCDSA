#include <stdio.h>


int main(void)
{
	int min=0,h,m,ans=0;
	scanf("%d %d",&h,&m);
	
	min=h*60+m;
	ans=18*60-min;
	
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&h,&m);
  ^