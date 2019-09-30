#include<stdio.h>
int main()
{
	long long int a,b;
	int count=0;
	scanf("%lld%lld",&a,&b);
	while(a<=b)
	{
	  a*=2;
	  count++;
	}
	printf("%d\n",count);
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&a,&b);
  ^