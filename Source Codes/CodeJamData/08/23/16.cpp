#include<stdio.h>

int F(int total,int koto,int i)
{
	int x,a,b,c;

	a=total;
	b=koto;
	c=i;

	while(1)
	{
		total=a;
		koto=b;
		i=c;

		if(i%total==0) x=total;
		else x=i%total;

		if(x==koto) return i;
		else if(x<koto) a=total-1,b=koto-x,c=i+1;
		else a=total-1,b=-x+total+koto,c=i+1;
	}
}

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);

	int Q,ks,n,i,K,a;

	scanf("%d",&Q);
	for(ks=1;ks<=Q;ks++)
	{
		scanf("%d",&K);
		scanf("%d",&n);
		printf("Case #%d:",ks);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a);
			printf(" %d",F(K,a,1));
		}

		printf("\n");
	}

	return 0;
}