#include<stdio.h>
int main()
{
	long long n,m;
	scanf("%lld%lld",&n,&m);
	if(m<=2*n)printf("%lld\n",m/2);
	else printf("%lld\n",n+(m-2*n)/4);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^