#include <stdio.h>

int main(void)
{
	int n,k,min=1,i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		{
		if(min<=k)
			{min*=2;}
		else
			{min+=k;}
		}
	printf("%d",min);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^