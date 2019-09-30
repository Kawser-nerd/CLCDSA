#include<stdio.h>
int main()
{
	unsigned long long n,m;
	unsigned long long ans;
	scanf("%llu%llu",&n,&m);
	if(n==1)
	{
		if(m==1) ans=1;
		else  ans=m-2;
	}
	else
	{
		if(m==1)
	 {
		if(n==1) ans=1;
		else ans=n-2;
	 }
	 else
	   ans=(m-2)*(n-2);
	}
	printf("%llu\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%llu%llu",&n,&m);
  ^