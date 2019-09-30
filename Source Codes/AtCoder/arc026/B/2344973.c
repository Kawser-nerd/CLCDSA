#include <stdio.h>

long long sum_yueshu(long long n)
{
	long long i,sum=1;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			sum +=i;
			sum +=n/i;
		}
		if(i*i==n)
		{
			sum -= i;
		}
	}
	return sum;
}
int main()
{
	long long n;
	scanf("%lld",&n);
	
	if(n==1)
	{
		printf("Deficient\n");
		return 0;
	}
	if(n==sum_yueshu(n))
	
		{
			printf("Perfect\n");	
		}
		else if(n>sum_yueshu(n))
		{
			printf("Deficient\n");
		} 
		else
		{
			printf("Abundant\n");
		}
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^