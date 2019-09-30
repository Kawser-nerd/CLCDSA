#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

long double c[MAXN][MAXN], d[MAXN], f[MAXN];

void init() {
	for (int i = 0; i < MAXN; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}
	d[0] = 1;
	d[1] = 0;
	for (int i = 2; i < MAXN; ++i) {
		d[i] = (i - 1) * (d[i - 2] + d[i - 1]);
	}
	f[0] = 1;
	for (int i = 1; i < MAXN; ++i) {
		f[i] = f[i - 1] * i;
	}
	//printf("%Le\n", f[MAXN - 1]);
}

int main() {
	int re, n, m, a[MAXN], b[MAXN];
	long double dp[MAXN];

	init();
	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		copy(a, a + n, b);
		sort(b, b + n);
		m = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] == b[i]) {
				++m;
			}
		}

		dp[n] = 0;
		for (int i = n - 1; i >= m; --i) {
			dp[i] = 1;
			for (int j = i + 1; j <= n; ++j) {
				dp[i] += c[n - i][n - j] * d[n - j] / f[n - i] * dp[j];
			}
			dp[i] /= 1 - c[n - i][n - i] * d[n - i] / f[n - i];
		}
	//	fprintf(stderr, "%d %d %d\n", n, m, n - m);
		printf("Case #%d: %.6Lf\n", ri, dp[m]);
	}

	return 0;
}

