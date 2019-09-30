#include<stdio.h>
int x[100005];
int main()
{
	int k,i;long long max=2,min=2;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d",&x[i]);
	}
	for(i=k-1;i>=0;i--)
	{
		if(min%x[i]!=0) min=min/x[i]*x[i]+x[i];
		max=max/x[i]*x[i]+x[i]-1;
		if(max<min)break;
	}
	if(max>=min) printf("%lld %lld\n",min,max);
	else printf("-1\n");
}