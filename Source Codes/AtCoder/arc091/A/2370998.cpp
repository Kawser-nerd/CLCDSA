#include<cstdio>
long long n,m,l;
int main()
{
	scanf("%lld%lld",&n,&m);
	if(n>=2)n-=2;
	if(m>=2)m-=2;
	l=n*m;
	printf("%lld",l);
	return 0;
}