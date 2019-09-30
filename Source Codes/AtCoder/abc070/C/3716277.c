#include<stdio.h>
long long int gcm(long long int a,long long int b)
{
	long long int r=a%b;
	while(r>0)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	long long int ans;
	scanf("%lld",&ans);
	long long int t;
	for(i=1;i<n;i++)
	{
		scanf("%lld",&t);
		ans=ans*(t/gcm(ans,t));
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&ans);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t);
   ^