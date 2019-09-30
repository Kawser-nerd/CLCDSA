#include <stdio.h>
#include <string.h>

int main(void)
{
	int w,a,b,dis;
	scanf("%d%d%d",&w,&a,&b);
	if(a+w<=b || a>=b+w)
		{
		if(a<b){dis=b-(a+w);}
		else{dis=a-(b+w);}
		}
	else{dis=0;}
	printf("%d",dis);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&w,&a,&b);
  ^