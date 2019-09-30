#include <stdio.h>
#include <string.h>

int main(void)
{
	int n,k;
	scanf("%d%d",&n,&k);
	int ans=k,i=1;
	for(i;i<=n-1;i++)
		{ans *= (k-1);}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^