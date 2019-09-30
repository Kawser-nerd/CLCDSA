#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1005;
int p[N], v[N][N], vis[N], dp[N];

int dfs(int k) {
	vis[k] = 1;
	dp[k] = 1;
	int cc = 0, v1=0, v2=0;
	for (int i = 0; i < p[k]; i++) {
		int y = v[k][i];
		if (vis[y]) continue;
		int v3 = dfs(y);
		if (v3 > v1)
			swap(v1, v3);
		if (v3 > v2)
			swap(v3, v2);
		cc++;
	}
	dp[k] = (cc >= 2 ? 1 + v1 + v2 : 1);
	return dp[k];
}

int main() {
	int T, cas;
	scanf("%d", &T);
	for (cas = 1; cas <= T; cas++) {
		int n, x, y;
		scanf("%d", &n);
		memset(p, 0, sizeof(p));
		for (int i = 0; i < n - 1; i++) {
			scanf("%d%d", &x, &y);
			v[x][p[x]++] = y;
			v[y][p[y]++] = x;
		}
		int ans = 0;
		for (int r = 1; r <= n; r++) {
			memset(vis, 0, sizeof(vis));
			int cur = dfs(r);
			if (cur > ans) ans = cur;
		}
		printf("Case #%d: %d\n", cas, n - ans);
	}
	return 0;
}
