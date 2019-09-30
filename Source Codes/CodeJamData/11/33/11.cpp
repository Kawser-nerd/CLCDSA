#include<stdio.h>
#include<algorithm>

long long f[10000];
long long gcd[10000], lcm[10000];

long long cgcd(long long a, long long b)
{
	while(a%b!=0) return cgcd(b, a%b);
	return b;
}
int main()
{
	int t;
	scanf("%d", &t);
	for(int cc=1;cc<=t;cc++)
	{
		int n;
		long long l, h;
		scanf("%d%lld%lld", &n, &l, &h);
		for(int i=0;i<n;i++)
		{
			scanf("%lld", &f[i]);
		}
		std::sort(f, f+n);

		gcd[n-1]=f[n-1];
		for(int i=n-2;i>=0;i--)
		{
			gcd[i]=cgcd(gcd[i+1], f[i]);
		}

		lcm[0]=f[0];
		long long inf=10000000000000001LL;
		for(int i=1;i<n;i++)
		{
			if(lcm[i-1]==inf) lcm[i]=inf;
			else
			{
				long long v=lcm[i-1]/cgcd(lcm[i-1], f[i]);
				if(inf/v>=f[i]) lcm[i]=v*f[i];
				else lcm[i]=inf;
			}
		}
		long long r=inf;
		for(int i=0;i<n-1;i++)
		{
			if(lcm[i]==inf) break;
			if(lcm[i]<f[i+1]&&gcd[i+1]>=f[i]&&gcd[i+1]%lcm[i]==0)
			{
				long long vl=lcm[i], vh=gcd[i+1], x=vh/vl;
				for(long long j=1;j*j<=x;j++)
				{
					if(x%j==0)
					{
						long long v=vl*(x/j);
						if(v>=l&&v<=h&&v>=vl&&v<=vh&&v<r)
						{
							r=v;
						}
						v=vl*j;
						if(v>=l&&v<=h&&v>=vl&&v<=vh&&v<r)
						{
							r=v;
							break;
						}
					}
				}
			}
		}
		{
			long long v=gcd[0];
			if(v>=l)
			{
				for(long long i=1;i*i<=v;i++)
				{
					if(v%i==0)
					{
						long long vv=v/i;
						if(vv>=l&&vv<=h&&vv<r) r=vv;
						if(i>=l&&i<=h&&i<r)
						{
							r=i;
							break;
						}
					}
				}
			}
		}
		{
			long long v=lcm[n-1];
			long long vv=(l+v-1)/v*v;
			if(vv>=l&&vv<=h&&vv<r) r=vv;
		}
		printf("Case #%d: ", cc);
		if(r==inf)
		{
			puts("NO");
		}
		else
		{
			printf("%lld\n", r);
		}
	}
}
