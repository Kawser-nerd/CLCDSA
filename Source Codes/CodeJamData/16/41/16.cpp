#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 12;

char name[] = "RPS";

bool vis[3][maxn + 5];

char ans[3][maxn + 5][(1 << maxn) + 5];

void work(int st, int n)
{
	if (vis[st][n]) return;
	vis[st][n] = 1;
	if (n == 0)
	{
		ans[st][n][0] = name[st];
		ans[st][n][1] = 0;
		return;
	}
	int u = st, v = (st + (1 << (n - 1))) % 3;
	work(u, n - 1);
	work(v, n - 1);
	if (lexicographical_compare(ans[v][n - 1], ans[v][n - 1] + (1 << (n - 1)), ans[u][n - 1], ans[u][n - 1] + (1 << (n - 1)))) swap(u, v);
	REP(i, 0, 1 << (n - 1)) ans[st][n][i] = ans[u][n - 1][i];
	REP(i, 0, 1 << (n - 1)) ans[st][n][(1 << (n - 1)) | i] = ans[v][n - 1][i];
	ans[st][n][1 << n] = 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	memset(vis, 0, sizeof vis);
	REP(i, 0, 3) REP(j, 0, maxn + 1) work(i, j);
	int T;
	scanf("%d", &T);
	for (int cc = 1; cc <= T; ++cc)
	{
		printf("Case #%d: ", cc);
		int n, a[3];
		scanf("%d%d%d%d", &n, a, a + 1, a + 2);
		int Max = max_element(a, a + 3) - a;
		int Min = min_element(a, a + 3) - a;
		if (a[Max] - a[Min] > 1) { printf("IMPOSSIBLE\n"); continue; }
		int st = -1;
		REP(i, 0, 3) if (a[i] > a[(i + 2) % 3]) st = i;
		assert(~st);
		printf("%s\n", ans[st][n]);
	}
	return 0;
}
