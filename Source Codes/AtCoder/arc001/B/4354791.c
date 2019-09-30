#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int a, b, ans=0, d;
	scanf("%d%d",&a,&b);
	d=abs(a-b);
	ans+=d/10;
	d=d%10;
	switch(d)
	{
	    case 0:break;
		case 3:case 7:case 8:ans+=3;break;
		case 2:case 4:case 6:case 9:ans+=2;break;
		default : ans+=1;
	}
	printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^