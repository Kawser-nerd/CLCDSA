#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef long long ll;

int digs(ll x)
{
	int cnt = 0;
	while(x)
	{
		x /= 10;
		cnt++;
	}
	return cnt;
}

ll rev(ll x)
{
	ll y = 0;
	while(x)
	{
		y = 10 * y + x % 10;
		x /= 10;
	}
	return y;
}

ll work(ll x)
{
	ll ans = 1;
	while(x != 1)
	{
		if(x % 10 != 1 || rev(x) >= x)
		{
			x--, ans++;
			continue;
		}
		if(x < 1000)
		{
			x = rev(x), ans++;
			continue;
		}

		int sz = digs(x) / 2;
		ll base = 1;
		for(int t = 0; t < sz; t++) base *= 10;
		ll rem = x % base - 1;
		x = rev(x - rem), ans += rem + 1;
	}
	return ans;
}

int main()
{
	int t;
	ll x;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
	{
		scanf("%lld", &x);
		printf("Case #%d: %lld\n", i, work(x));
	}
	return 0;
}
