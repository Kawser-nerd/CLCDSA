#include <stdio.h>

int main()
{
	long long m,n,max;
	scanf("%lld%lld",&n,&m);
	if(n*2<=m)
	{
	m-=n*2;
	max=n+m/4;
    }
	else
	max=m/2;
	printf("%lld\n",max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^