#include<stdio.h>
#define max(a,b) a>b?a:b
long long int rev(long long int n)
{
	long long int num=0;
	while(n>0)
	{
		num=(num*10)+n%10;
		n=n/10;
	}
	return num;
}
long long int dp[1000005],dp1[1000005];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	long long int t,T,n,i,p;
		for(i=1;i<=10;i++)
		{
			dp[i]=i;
			dp1[i]=i-1;
		}
		
		for(i=11;i<=1000000;i++)
		{
			p=rev(i);
			if(p<i && i%10!=0)
			{
				if(dp[i-1]>=dp[p])
				{
					dp[i]=dp[p]+1;
					dp1[i]=p;
				}
				else if(dp[i-1]<dp[p])
				{
					dp[i]=dp[i-1]+1;
					dp1[i]=i-1;
				}
			}
			else
			{
				dp[i]=dp[i-1]+1;
				dp1[i]=i-1;
			}
		}

	scanf("%lld",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%lld",&n);
		printf("Case #%lld: %lld\n",t,dp[n]);
	}
//		for(i=1;i<=n;i++)
//			printf("%2lld ",i);
//		printf("\n");
//		for(i=1;i<=n;i++)
//			printf("%2lld ",dp[i]);
//		printf("\n");
//		for(i=1;i<=n;i++)
//			printf("%2lld ",dp1[i]);
//		printf("\n\n");

	return 0;
}
