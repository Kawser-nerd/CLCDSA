#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef std::pair<int, int> pii;

#define DEBUG 1

void dbg(const char * fmt, ...)
{
#if DEBUG
	va_list args;
	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	va_end(args);
#endif
}


ll mod;

ll pow(ll x, ll n)
{
	ll ans = 1;
	while(n)
	{
		if (n & 1)
			ans = (ans * x) % mod;
		x = (x*x) % mod;
		n >>= 1;
	}
	return ans % mod;
}

ll rev(ll x)
{
	return pow(x, mod - 2);
}

int ar[10];


int prime[1000010];
int _pow10[10];

ll norm(ll x)
{
	x = x % mod;
	return (x+mod) % mod;
}

void solve(int test_case)
{
	printf("Case #%d: ", test_case);
	int n, k;
	scanf("%d%d", &n, &k);
	n = _pow10[n];
	int m = 0;
	int testans = -1;
	for(int i = 0; i < k; i++)
	{
		scanf("%d", &ar[i]);
		m = std::max(m, ar[i]);
	}
	for(int j = 0; j < k - 1; j++)
		if (ar[j] == ar[k-1])
		{
			//dbg("equal\n");
			printf("%d\n", ar[j+1]);
			return;
		}
	if (k < 3)
	{
		printf("I don't know.\n");
		return;
	}
	for(int i = m+1; i <= n; i++)
	{
		if (prime[i])
			continue;
		mod = i;
		ll x1 = ar[0], x2 = ar[1], x3 = ar[2];
		ll a,b;
		if (x1 == 0)
		{
			b = x2;
			a = norm((x3-b)* rev(x2));
		}
		else
		{
			b = norm((x2*x2-x1*x3) % mod * rev(x2-x1+mod));	
			a = norm((x2-b)*rev(x1));
		}
		bool good = 1;
//		dbg("P: %d, a: %lld, b: %lld\n", i, a, b);
		for (int j = 1; j < k; j++)
		{
			if(ar[j] != norm(ar[j-1] * a + b))
			{
				assert(j >= 3);
				good = 0;
			}
		}
		if (good)
		{			
			ll temp = norm(ar[k-1] * a + b);
//			dbg("%d %lld\n", i, temp);
			if (testans == -1 || testans == temp)
				testans = temp;
			else
			{
				printf("I don't know.\n");
				return;
			}
		}
	}
	if (testans == -1)
		assert(false);
	printf("%d\n", testans);
}



int main()
{
	int n;
	scanf("%d", &n);
	_pow10[0] = 1;
	for(int i = 1; i <= 6; i++)
		_pow10[i] = _pow10[i-1] * 10;
	clr(prime);
	for(int i = 2; i <= _pow10[6]; i++)
		if (prime[i] == 0)
		{
			for(int j = i + i; j <= _pow10[6]; j += i)
				prime[j] = i;
		}

	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
