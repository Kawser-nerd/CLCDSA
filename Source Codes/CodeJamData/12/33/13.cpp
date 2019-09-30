#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100 + 10;

long long a[maxn], b[maxn], ta[maxn], tb[maxn];
int A[maxn], B[maxn];
long long f[maxn][maxn];
int n, m;

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("c.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%I64d%d", &a[i], &A[i]);
		for (int i = 0; i < m; ++i) scanf("%I64d%d", &b[i], &B[i]);

		memset(f, 0, sizeof(f));
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= m; ++j) {
				if (i + 1 <= n && f[i][j] > f[i + 1][j]) f[i + 1][j] = f[i][j];
				if (j + 1 <= m && f[i][j] > f[i][j + 1]) f[i][j + 1] = f[i][j];

				memcpy(ta, a, sizeof(a));
				memcpy(tb, b, sizeof(b));
				if (i + 1 <= n) {
					long long cnt = f[i][j];
					int tar = A[i];
					for (int x = i, y = j; ; ) {
						while (x < n && A[x] != tar) ++x;
						if (x == n) break;
						while (y < m && B[y] != tar) ++y;
						if (y == m) break;

						if (ta[x] == tb[y]) {
							cnt += ta[x];
							if (cnt > f[x + 1][y + 1]) f[x + 1][y + 1] = cnt;
							++x; ++y;
						}
						else if (ta[x] < tb[y]) {
							cnt += ta[x];
							tb[y] -= ta[x];
							if (cnt > f[x + 1][y + 1]) f[x + 1][y + 1] = cnt;
							++x;
						}
						else {
							cnt += tb[y];
							ta[x] -= tb[y];
							if (cnt > f[x + 1][y + 1]) f[x + 1][y + 1] = cnt;
							++y;
						}
					}
				}

				memcpy(ta, a, sizeof(a));
				memcpy(tb, b, sizeof(b));
				if (j + 1 <= m) {
					long long cnt = f[i][j];
					int tar = B[j];
					for (int x = i, y = j; ; ) {
						while (x < n && A[x] != tar) ++x;
						if (x == n) break;
						while (y < m && B[y] != tar) ++y;
						if (y == m) break;

						if (ta[x] == tb[y]) {
							cnt += ta[x];
							if (cnt > f[x + 1][y + 1]) f[x + 1][y + 1] = cnt;
							++x; ++y;
						}
						else if (ta[x] < tb[y]) {
							cnt += ta[x];
							tb[y] -= ta[x];
							if (cnt > f[x + 1][y + 1]) f[x + 1][y + 1] = cnt;
							++x;
						}
						else {
							cnt += tb[y];
							ta[x] -= tb[y];
							if (cnt > f[x + 1][y + 1]) f[x + 1][y + 1] = cnt;
							++y;
						}
					}
				}
			}

		printf("Case #%d: %I64d\n", nCase, f[n][m]);
	}

	return 0;
}
