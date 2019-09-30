#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

const ll INF = (ll)1e18;
const int N = 1010;
int n;
ll m;
ll a[N];

ll check(ll x)
{
	ll res = 0;
	for (int i = 0; i < n; i++)
		res = min(INF, res + (x + a[i] - 1) / a[i]);
	return res;
}

void solve()
{
	scanf("%d%lld", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	ll l = 0, r = INF;
	while(r - l > 1)
	{
		ll x = (l + r) / 2;
		ll st = check(x);
		if (st < m)
			l = x;
		else
			r = x;
	}
	ll cnt = m - check(l);
	for (int i = 0; i < n; i++)
	{
		if (l % a[i] != 0) continue;
		if (cnt == 1)
		{
			printf("%d\n", i + 1);
			return;
		}
		else
			cnt--;
	}
	throw;
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
	}

	return 0;
}
