#import <objc/Object.h>
#import <stdio.h>

// twitter.com/P_E

#define MAXN 1000010
int ip[MAXN];
int primes[1000000];
int p = 0;

void prec()
{
	int i;
	for (i = 0; i < MAXN; ++i)
		ip[i] = 1;

	ip[1] = 0;
	ip[2] = 1;

	for (i = 2; (long long)i * i < MAXN; ++i)
		if (ip[i])
		{
			long long k;
			for (k = i * i; k < MAXN; k += i)
				ip[k] = 0;
		}

	p = 0;
	for (i = 2; i < MAXN; ++i)
		if (ip[i])
			primes[p++] = i;
}


void solve(int acase)
{
	long long N;
	scanf("%lld", &N);

	long long ans = N == 1 ? 0 : 1;

	int pp = 0;
	while ((long long)primes[pp] * primes[pp] <= N && pp < p) 
	{
			long long j = primes[pp];
			while (j <= N)
			{
				++ans;
				j *= primes[pp];
			}
			--ans;

			++pp;
	}
	
	printf("Case #%d: %lld\n", acase, ans); 
}

int main()
{
	freopen("cl.in", "r", stdin);
	freopen("cl.out", "w", stdout);

	prec();

	int cases, tc;
	scanf("%d", &cases);
	for (tc = 0; tc < cases; ++tc) 
	{
		solve(tc + 1);
	}

	return 0;
}
