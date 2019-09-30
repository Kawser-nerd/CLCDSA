#include <stdio.h>

int main()
{
	int cases;scanf("%d",&cases);
	for (int cs=1;cs<=cases;cs++)
	{
		int b,f=2;
		long long s;
		scanf("%d%lld",&b,&s);
		while (f<63 && s>(1LL<<(f-2))) f++;
		if (b<f) {printf("Case #%d: IMPOSSIBLE\n",cs);continue;}
		if (s<(1LL<<(f-2))) f--;
		s-=1LL<<(f-2);
		printf("Case #%d: POSSIBLE\n",cs);
		for (int y=0;y<b;y++)
		{
			long long a=y?1ULL<<(y-1):0;
			for (int x=0;x<b;x++)
			{
				int c=0;
				if (x>y && x<f) c=1;
				if (x==y+1) c=1;
				if (x==b-1 && (s&a)) c=1;
				printf("%d",c);
			}
			printf("\n");
		}
	}
}