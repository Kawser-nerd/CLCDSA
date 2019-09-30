#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

int Mod(int x, int mod)
{
	return (x % mod + mod) % mod;
}

const int inf = (int) 1e9 + 100;
const int maxn = 1005;
int a[maxn];
const int maxk = 105;
int m[maxk], M[maxk];

int dp[maxk][maxk][maxk];

void solve()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < (n - k + 1); i++)
		scanf("%d", &a[i] );
//	eprintf("n = %d, k = %d\n", n, k);
	for (int i = 0; i < k; i++)
	{
		int d = 0;
		m[i] = 0;
		M[i] = 0;
		for (int j = i; j < n - k + 1; j += k)
		{
			if (j == 0)
				continue;
			d += a[j] - a[j - 1];
			m[i] = min(m[i], d);
			M[i] = max(M[i], d);
		}
//		eprintf("%d: %d %d\n", i, m[i], M[i] );
	}
	int need = Mod(a[0], k);
	for (int i = 0; i <= k; i++)
		for (int j = 0; j <= k; j++)
			for (int h = 0; h <= k; h++)
				dp[i][j][h] = inf;
	
	dp[1][Mod(-m[0], k) ][0] = M[0] - m[0];
	for (int i = 1; i < k; i++)
	{
//		eprintf("i = %d\n", i);
		for (int s = 0; s < k; s++)
			for (int d = 0; d < k; d++)
			{
				int cur = dp[i][s][d];
				if (cur == inf)
					continue;
				for (int cs = -(k - 1); cs < k; cs++)
				{
					int ns = Mod(s + cs - m[i], k);
					int nd = max(d, -cs);
					int nxt = max(cur, cs + M[i] - m[i] );
					dp[i + 1][ns][nd] = min(dp[i + 1][ns][nd], nxt);
				}
			}
	}
	int ans = inf;
	for (int d = 0; d < k; d++)
		ans = min(ans, dp[k][need][d] + d);
	printf("%d\n", ans);
}

void multitest()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("Case #%d: ", i);
		eprintf("Case #%d .. %d\n", i, n);
		solve();
	}


}

int main(int argc, char **)
{
	if (argc == 1)
		multitest();
	else
		solve();

	return 0;
}


