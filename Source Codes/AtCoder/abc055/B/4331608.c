#include<stdio.h>
int main()
{
	int n,i;
	long long count=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	count=count*i%1000000007;
	printf("%lld",count%1000000007);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^