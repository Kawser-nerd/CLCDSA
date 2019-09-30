#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 128;

int arr[MAXN];

int dp[MAXN][257];

int better(int a, int b)
{
	if (a < 0) return b;
	if (b < 0) return a;
	return min(a, b);
}

int run()
{
	int d, ii, m, n;
	scanf("%d %d %d %d", &d, &ii, &m, &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
	}
	memset(dp, -1, sizeof(dp));
	dp[0][256] = 0;
	for (int i = 0; i < n; ++i) {
		for (int lastv = 0; lastv <= 255; ++lastv) {
			if (dp[i][lastv] != -1) {
				dp[i + 1][lastv] = better(dp[i + 1][lastv], dp[i][lastv] + d);
				for (int now = 0; now <= 255; ++now) {
					int c = abs(arr[i] - now);
					int diff = abs(now - lastv);
					if (m == 0) {
						if (diff == 0) {
							dp[i + 1][now] = better(dp[i + 1][now], dp[i][lastv] + c);
						}
					}
					else {
						int need;
						if (diff == 0) need = 0;
						else need = (diff - 1) / m;
						c += need * ii;
						dp[i + 1][now] = better(dp[i + 1][now], dp[i][lastv] + c);
					}
				}
			}
		}
		if (dp[i][256] != -1) {
			dp[i + 1][256] = better(dp[i + 1][256], dp[i][256] + d);
			for (int now = 0; now <= 255; ++now) {
				int c = abs(arr[i] - now);
				dp[i + 1][now] = better(dp[i + 1][now], dp[i][256] + c);
			}
		}
	}
	int ret = -1;
	for (int i = 0; i <= 256; ++i) {
		ret = better(ret, dp[n][i]);
	}
	return ret;
}

int main()
{
	freopen("B2.in", "r", stdin);
	freopen("B2.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: %d\n", i, run());
	}
	return 0;
}