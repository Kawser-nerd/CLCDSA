#include<stdio.h>
int main()
{
		long long n,a,b;
		scanf("%lld%lld%lld",&n,&a,&b);
		if(b<a)
		puts("0");
		else if(n!=1)
		printf("%lld\n",(n-1)*b+a-((n-1)*a+b)+1);
		else if(a==b)
		puts("1");
		else
		puts("0");
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&n,&a,&b);
   ^