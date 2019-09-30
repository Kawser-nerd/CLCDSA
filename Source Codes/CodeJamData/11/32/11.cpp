#include<stdio.h>
#include<algorithm>

int d[1000], dd[1000000];
double h[1000000];
int main()
{
	int t;
	scanf("%d", &t);
	for(int cc=1;cc<=t;cc++)
	{
		int l, n, c;
		long long t;
		scanf("%d%lld%d%d", &l, &t, &n, &c);
		for(int i=0;i<c;i++)
		{
			scanf("%d", &d[i]);
		}
		for(int i=0;i<n;i++)
		{
			dd[i]=d[i%c];
		}
		long long s=0;
		int hh=0;
		for(int i=0;i<n;i++)
		{
			if(s+dd[i]*2<t);
			else if(s>=t)
			{
				h[hh]=dd[i]*2;
				hh++;
			}
			else
			{
				h[hh]=dd[i]*2-(t-s);
				hh++;
			}
			s=s+dd[i]*2;
		}

		long long r=0;
		for(int i=0;i<n;i++)
		{
			r=r+dd[i]*4;
		}
		std::sort(h, h+hh);
		for(int i=hh-1;i>=0&&i>=hh-l;i--)
		{
			r=r-h[i];
		}
		printf("Case #%d: %lld\n", cc, r/2);
	}
}
