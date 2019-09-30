#include<stdio.h>
int main()
{
	long long int n,m;
	scanf("%lld %lld",&n,&m);
	long long int sum;
	sum = n;
	if(m == 1|| m == 2 && n == 0)
	{
		printf("0\n");
	}
	else
	{
		if(n * 2 < m)
		{
			m = m - sum * 2;
			if(m >= 4)
			{
			sum += m / 4;
			printf("%lld\n",sum);
			}
			else
			{
				printf("%lld\n",sum);
			}
		}
		else if(n * 2 >= m)
		{
			printf("%lld\n",m / 2);
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld",&n,&m);
  ^