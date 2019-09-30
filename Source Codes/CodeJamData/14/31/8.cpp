#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


long long gcd(long long a, long long b)
{
	return b ? gcd(b, a % b) : a;
}

void imp()
{
	printf("impossible");
}

void solve()
{
	long long p, q;
	scanf("%lld/%lld", &p, &q);
	long long g = gcd(p, q);
	p /= g;
	q /= g;
	long long UP = (1LL << 40);
	if (UP % q != 0)
	{
		imp();
		return;
	}
	p *= (UP / q);
	int ans = -1;
	int cur = 40;

	while (p)
	{
		if (p & 1LL)
		{
			ans = cur;
		}
		cur--;
		p >>= 1;
	}
	printf("%d", ans);
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		solve();
		printf("\n");
	}

	return 0;
}