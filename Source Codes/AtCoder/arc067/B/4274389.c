#include<stdio.h>
int main()
{
	long long int i;
	int s[100000];
	long long int n,a,b;
	scanf("%lld %lld %lld",&n,&a,&b);
	for(i = 0;i<n;i++)
	{
		scanf("%d",&s[i]);
	}
	long long int sum = 0;
	for(i = 1;i<n;i++)
	{
		if((s[i] - s[i-1]) * a > b)
		{
			sum += b;
		}
		else
		{
			sum += (s[i] - s[i-1])*a;
		}
	}
	printf("%lld",sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld",&n,&a,&b);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&s[i]);
   ^