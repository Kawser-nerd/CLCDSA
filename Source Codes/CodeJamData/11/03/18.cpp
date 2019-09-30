#include <stdio.h>

int n,x,sum,xor,min,T,t;

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		xor=0;
		sum=0;
		min=1999999999;
		while(n--)
		{
			scanf("%d",&x);
			xor^=x;
			sum+=x;
			if(x<min)
				min=x;
		}
		if(xor)
			printf("Case #%d: NO\n",++t);
		else
			printf("Case #%d: %d\n",++t,sum-min);
	}
	return 0;
}

