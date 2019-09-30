#include<stdio.h>
long long int mod = 1e9+7;
int main()
{
	int t;
	int n,m;
	int i,j;
	long long int number = 1;
	int a[100000];
	scanf("%d",&n);
	if(n == 1) printf("1");
	else if(n != 1)
	{
		for(i = 2;i <= n;i++)
		{
			t = i;
			for(j = 2;j <= i;j++)
			{
				while(t % j == 0)
				{
					a[j]++;
					t = t / j;
				}
			}
		}
		for(i = 2;i<=n;i++)
		{
			if(a[i] != 0)
			{
				number *= (1 + a[i]);
				number = number % mod;
			}
		}
		printf("%lld",number);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^