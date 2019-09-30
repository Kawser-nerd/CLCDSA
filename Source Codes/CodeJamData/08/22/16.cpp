#include<stdio.h>

int Ps;

int GCD(int x,int y)
{
	if(x%y==0) return y;
	return GCD(y,x%y);
}

int CHECK(int x,int y)
{
	int i;

	int t=GCD(x,y);

	for(i=2;i<Ps;i++)
	{
		while(t%i==0) t/=i;
		if(t==1) return 0;
	}

	if(t==1) return 0;

	return 1;
}

int p[100002];

int P(int x)
{
	if(p[x]==x) return x;
	else return p[x]=P(p[x]);
}

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("output-small-B.out","w",stdout);

	int Q,ks,A,B,i,j,cnt;

	scanf("%d",&Q);
	for(ks=1;ks<=Q;ks++)
	{
		scanf("%d%d%d",&A,&B,&Ps);

		for(i=A;i<=B;i++) p[i]=i;

		cnt=0;
		for(i=A;i<=B;i++)
			for(j=i+1;j<=B;j++)
				if(CHECK(i,j))
				{
					p[P(i)]=P(j);
				}

		for(i=A;i<=B;i++)
			cnt+=(i==P(i));

		printf("Case #%d: %d\n",ks,cnt);
	}

	return 0;
}