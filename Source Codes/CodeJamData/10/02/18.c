#include<stdio.h>
int c,n;
int t[1003];

int main()
{
	scanf("%d",&c);
	int i,j,k;
	for(k=1;k<=c;++k)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d",&t[i]);
		int min=t[1];
		for(i=2;i<=n;++i)
			if(t[i]>min) min=t[i];
		for(i=min;i>=1;i--)
		{
			int y=t[1]%i;
			int bl=1;
			for(j=2;j<=n;++j)
				if( (t[j]%i)!=y)
				{
					bl=0;
					break;
				}
			if(bl)
			{
				printf("Case #%d: ",k);
				if(i==1) printf("0\n");
				else if(y==0) printf("0\n");
				else printf("%d\n",i-y);
				break;
			}
		}
	}
	return 1;
}
