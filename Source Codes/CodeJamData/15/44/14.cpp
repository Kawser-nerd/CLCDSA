#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll MOD = (ll)(1e9 + 7);
const int N = 104;

ll sum(ll x, ll y)
{
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}

ll dp[N][2][10];
int n, m;
int a[] = {2, 1, 2, 2, 3};
int b[] = {1, 1, 6, 3, 4};
int c[] = {-1, -1, 0, 1, 2};
int d[] = {1, 6, 3, 6, 4, 12, 12, 12};

int gcd(int x, int y)
{
	return (y == 0 ? x : gcd(y, x % y));
}

void solve()
{
	memset(dp, 0, sizeof dp);
	dp[0][0][0] = dp[0][1][0] = 1;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
		for (int ot = 0; ot < 2; ot++)
			for (int mask = 0; mask < 8; mask++)
				for (int nt = 0; nt < 5; nt++)
				{
					if (!((ot == 0) ^ (nt == 0))) continue;
					if (m % b[nt] != 0) continue;
					int np = i + a[nt];
					if (np > n) continue;
					int nmask = mask;
					if (c[nt] != -1)
						nmask |= 1 << c[nt];
					int diff = gcd(d[mask], b[nt]);
					dp[np][ot ^ 1][nmask] = sum(dp[np][ot ^ 1][nmask], mult(dp[i][ot][mask], diff));
				}
	ll ans = 0;
	for (int t = 0; t < 2; t++)
		for (int mask = 0; mask < 8; mask++)
			ans = sum(ans, dp[n][t][mask]);
	printf("%lld\n", ans);
	return;
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
