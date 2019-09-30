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

#define clz __builtin_clz
#define ctz __builtin_ctz
#define bcnt __builtin_popcount
#define bpar __builtin_parity  

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 25, maxm = 16;

int a[maxn + 5];

vector<int> adj[(maxn << 1) + 5];

bool vis[(maxn << 1) + 5];

int bc[(1 << maxm) + 5];

int n;

int cnta = 0, cntb = 0;

void dfs(int x)
{
	if (vis[x]) return;
	if (x >= n) ++cntb;
	else ++cnta;
	vis[x] = 1;
	for (auto y : adj[x]) dfs(y);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	REP(i, 0, 1 << maxm) bc[i] = bcnt(i);
	int T;
	scanf("%d", &T);
	for (int cc = 1; cc <= T; ++cc)
	{
		printf("Case #%d: ", cc);
		static char s[maxn + 5];
		int tot = 0;
		scanf("%d", &n);
		REP(i, 0, n << 1) adj[i].clear();
		REP(i, 0, n)
		{
			scanf("%s", s);
			REP(j, 0, n) if (s[j] == '1') adj[i].pb(j + n), adj[j + n].pb(i), --tot;
		}
		memset(vis, 0, sizeof vis);
		vector<pair<int, int> > all;
		int cnt0 = 0, cnt1 = 0;
		REP(i, 0, n << 1) if (!vis[i])
		{
			cnta = 0, cntb = 0;
			dfs(i);
			if (cnta == 1 && cntb == 1) ++tot;
			else 
			{
				if (cnta == 1 && cntb == 0) ++cnt0;
				else if (cnta == 0 && cntb == 1) ++cnt1;
				else all.pb(mp(cnta, cntb));
			}
		}
		int m = SZ(all);
		static int sum[(1 << maxm) + 5], sz[(1 << maxm) + 5]; 
		static int dp[(1 << maxm) + 5][maxn + 1][maxn + 1];
		REP(i, 0, 1 << m)
		{
			sum[i] = 0;
			sz[i] = 0;
			REP(j, 0, m) if (i >> j & 1) sum[i] += all[j].x, sum[i] -= all[j].y;
			REP(j, 0, m) if (i >> j & 1) sz[i] += all[j].y;
			if (sum[i] > 0) sz[i] += sum[i];
		}
		memset(dp, oo, sizeof dp);
		dp[0][0][0] = 0;
		int S = (1 << m) - 1;
		REP(i, 0, 1 << m) REP(j, 0, cnt0 + 1) REP(k, 0, cnt1 + 1) if (dp[i][j][k] < oo)
		{
			int tmp = S ^ i;
			for (int mask = tmp; mask > 0; mask = (mask - 1) & tmp)
			{
				if (sum[mask] > 0 && k + sum[mask] <= cnt1) chkmin(dp[i | mask][j][k + sum[mask]], dp[i][j][k] + sz[mask] * sz[mask]);
				else if (sum[mask] <= 0 && j - sum[mask] <= cnt0) chkmin(dp[i | mask][j - sum[mask]][k], dp[i][j][k] + sz[mask] * sz[mask]);
			}
		}
		int ans = oo;
		REP(i, 0, min(cnt0, cnt1) + 1) chkmin(ans, dp[S][cnt0 - i][cnt1 - i] + i);
		ans += tot;
		printf("%d\n", ans);
	}
	return 0;
}
