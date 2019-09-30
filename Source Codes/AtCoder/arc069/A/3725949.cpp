#include<stdio.h>
int main()
{
	long long n,m;
	scanf("%lld%lld",&n,&m);
	if(m<=2*n)printf("%lld\n",m/2);
	else printf("%lld\n",n+(m-2*n)/4);
	return 0;
}