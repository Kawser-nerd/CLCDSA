#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
#define rep(i, a, b) for (int i = a; i <= b; ++ i)
const int N = 100005, M = 1000005, V = 500, inf = 1000000007;
using namespace std;
int T, s, t, e, ter[M], nxt[M], lnk[N], cur[N], w[M], rec[M], dis[N];
int opt[N], n, m, c[N], d[N], g[V][V];
bool a[V][V], b[V][V], A[V][V], B[V][V];
void add(int x, int y, int z) {
	ter[++ e] = y, nxt[e] = lnk[x], lnk[x] = e, w[e] = z, rec[e] = e + 1;
	ter[++ e] = x, nxt[e] = lnk[y], lnk[y] = e, w[e] = 0, rec[e] = e - 1;
}
bool bfs() {
	rep(i, s, t) dis[i] = 0;
	int he = 0, ta = 1; opt[1] = s, dis[s] = 1;
	for ( ; he != ta; ) {
		++ he; int u = opt[he];
		for (int i = lnk[u]; i; i = nxt[i]) if (!dis[ter[i]] && w[i])
			dis[ter[i]] = dis[u] + 1, opt[++ ta] = ter[i];
	}
	return dis[t];
}
int dfs(int p ,int sum) {
	if (p == t) return sum;
	int res = 0;
	for (int i = cur[p]; i; i = nxt[i]) if (w[i] && dis[ter[i]] == dis[p] + 1) {
		int tmp = dfs(ter[i], min(sum - res, w[i]));
		w[i] -= tmp, res += tmp, w[rec[i]] += tmp;
		if (w[i]) cur[p] = i;
		if (res == sum) return sum;
	}
	return res;
}
void dinic() {
	int ret = 0;
	for ( ; bfs() ; ) {
		rep(i, s, t) cur[i] = lnk[i];
		ret += dfs(s, inf);
	}
}
int main() {
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	scanf("%d", &T); char ch[200]; int x, y;
	rep(cas, 1, T) {
		scanf("%d%d", &n, &m); 
		rep(i, 1, n) rep(j, 1, n) a[i][j] = b[i][j] = false;
		rep(i, 1, m) {
			scanf("%s%d%d", ch, &x, &y);
			if (ch[0] != '+') a[x][y] = true;
			if (ch[0] != 'x') b[x][y] = true;
		}
		rep(i, 1, n) rep(j, 1, n) A[i][j] = a[i][j], B[i][j] = b[i][j];
		c[0] = d[0] = 0;
		rep(i, 1, n) {
			bool flg = true;
			rep(j, 1, n) if (a[i][j]) flg = false;
			if (flg) c[++ c[0]] = i;
			flg = true;
			rep(j, 1, n) if (a[j][i]) flg = false;
			if (flg) d[++ d[0]] = i;
		}
		rep(i, 1, c[0]) a[c[i]][d[i]] = true;
		s = 0, t = 2 * (2 * n - 1) + 1;
		rep(i, 1, 2 * n - 1) {
			bool flg = true;
			rep(j, 1, n) {
				int x = i - j + 1;
				if (x > 0 && x <= n && b[x][j]) flg = false;
			}
			if (flg) add(s, i, 1);
			flg = true;
			rep(j, 1, n) {
				int x = i + j - n;
				if (x > 0 && x <= n && b[x][j]) flg = false;
			}
			if (flg) add(2 * n - 1 + i, t, 1);
		}
		rep(i, 1, n) rep(j, 1, n) if (!b[i][j]) add(i + j - 1, 2 * n - 1 + i - j + n, 1);
		dinic();
		rep(i, 1, 2 * n - 1) rep(j, 1, 2 * n - 1) g[i][j] = false;
		rep(i, 1, 2 * n - 1) for (int j = lnk[i]; j; j = nxt[j]) if (ter[j] > 2 * n - 1 && !w[j])
			g[i][ter[j] - 2 * n + 1] = true;
		rep(i, 1, n) rep(j, 1, n) b[i][j] |= g[i + j - 1][i - j + n];
		int ans = 0, ret = 0;
		rep(i, 1, n) rep(j, 1, n) {
			if (a[i][j]) ++ ans;
			if (b[i][j]) ++ ans;
			if (a[i][j] != A[i][j] || b[i][j] != B[i][j]) ++ ret;
		}
		printf("Case #%d: %d %d\n", cas, ans, ret);
		rep(i, 1, n) rep(j, 1, n) if (a[i][j] != A[i][j] || b[i][j] != B[i][j]) {
			printf((a[i][j] && b[i][j] ? "o" : (a[i][j] ? "x" : "+")));
			printf(" %d %d\n", i, j);
		}
		rep(i, s, t) lnk[i] = 0; e = 0;
	}
	return 0;
}