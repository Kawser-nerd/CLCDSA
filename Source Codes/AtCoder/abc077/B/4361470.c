#include <stdio.h>

int main(void)
{
	int n,i,ans;
	scanf("%d",&n);
	for(i=0;i*i<=n;i++)
		{ans=i*i;}
	printf("%d\n",ans);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^