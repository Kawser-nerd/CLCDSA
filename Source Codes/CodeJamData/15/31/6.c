#include<stdio.h>
int main()
{
	long long int t,T,r,c,w,ans;
	scanf("%lld",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%lld %lld %lld",&r,&c,&w);
		ans=((c/w)*r)+w;
		if(c%w==0)
			ans--;
		printf("Case #%lld: %lld\n",t,ans);
	}
	return 0;
}
