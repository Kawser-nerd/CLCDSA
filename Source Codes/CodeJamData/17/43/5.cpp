#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
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

const int maxn = 60;

const int maxN = 100100;

int n, m;

char g[maxn + 5][maxn + 5];

int id[maxn + 5][maxn + 5];

int N;
vector<int> adj[maxN + 5];

inline void add_con(int x, int y) { adj[x].pb(y), adj[y ^ 1].pb(x ^ 1); }

int tot = 0;

bool in[maxN + 5];

int belong[maxN + 5];

int cnts;
vector<int> scc[maxN + 5];
int dfn[maxN + 5], low[maxN + 5];

int stk[maxN + 5];

void dfs(int x)
{
	int tmp = tot;
	stk[dfn[x] = low[x] = tot++] = x;
	in[x] = 1;
	for (auto y : adj[x])
	{
		if (!~dfn[y]) dfs(y), chkmin(low[x], low[y]);
		else if (in[y]) chkmin(low[x], dfn[y]);
	}
	if (dfn[x] == low[x])
	{
		scc[cnts].clear();
		while (tot != tmp)
		{
			--tot;
			scc[cnts].pb(stk[tot]);
			in[stk[tot]] = 0;
			belong[stk[tot]] = cnts;
		}
		++cnts;
	}
}

vector<int> pre[maxN + 5];
bool ban[maxN + 5];

bool picked[maxN + 5];

void dfs_ban(int x)
{
	if (ban[x]) return;
	ban[x] = 1;
	for (auto y : pre[x]) dfs_ban(y);
}

inline bool work()
{
	memset(dfn, -1, sizeof dfn), tot = 0, cnts = 0;
	REP(i, 0, N) if (!~dfn[i]) dfs(i);
	REP(i, 0, N) if (belong[i] == belong[i ^ 1]) return 0;
	REP(i, 0, N) pre[i].clear();
	REP(u, 0, N) for (auto v : adj[u])
		if (belong[v] != belong[u]) pre[belong[v]].pb(belong[u]);
	memset(ban, 0, sizeof ban);
	memset(picked, 0, sizeof picked);
	REP(i, 0, cnts) if (!ban[i])
	{
		for (auto u : scc[i])
		{
			picked[u] = 1;
			dfs_ban(belong[u ^ 1]);
		}
	}
	return 1;
}

vector<int> shooter;

const int walk[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

inline void go(int x, int y, int way)
{
	x += walk[way][0], y += walk[way][1];
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (g[x][y] == '\\') way ^= 1;
	else if (g[x][y] == '/') way ^= 3;
	else if (~id[x][y])
	{
		shooter.pb(id[x][y] << 1 | (way & 1));
		return;
	}
	else if (g[x][y] == '#') return;
	go(x, y, way);
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int case_cnt;
	scanf("%d", &case_cnt);
	for (int case_id = 1; case_id <= case_cnt; ++case_id)
	{
		printf("Case #%d: ", case_id);;
		scanf("%d%d", &n, &m);
		REP(i, 0, n) scanf("%s", g[i]);
		work();
		N = 0;
		memset(id, -1, sizeof id);
		REP(i, 0, n) REP(j, 0, m) if (g[i][j] == '-' || g[i][j] == '|') id[i][j] = N++;
		N <<= 1;
		REP(i, 0, N) adj[i].clear();
		REP(i, 0, n) 
		{
			REP(j, 0, m)
			{
				if (~id[i][j]) 
				{
					shooter.clear();
					go(i, j, 0);
					go(i, j, 2);
					if (!shooter.empty()) add_con(id[i][j] << 1, id[i][j] << 1 | 1);
					shooter.clear();
					go(i, j, 1);
					go(i, j, 3);
					if (!shooter.empty()) add_con(id[i][j] << 1 | 1, id[i][j] << 1);
				}
				else if (g[i][j] == '.')
				{
					vector<int> v0, v1;
					shooter.clear();
					go(i, j, 0);
					go(i, j, 2);
					v0 = shooter;
					if (SZ(v0) == 2) v0.clear();
					shooter.clear();
					go(i, j, 1);
					go(i, j, 3);
					v1 = shooter;
					if (SZ(v1) == 2) v1.clear();
					if (v0.empty() && v1.empty()) add_con(0, 1), add_con(1, 0);
					else if (v0.empty()) add_con(v1[0] ^ 1, v1[0]);
					else if (v1.empty()) add_con(v0[0] ^ 1, v0[0]);
					else add_con(v1[0] ^ 1, v0[0]);
				}
			}
		}
		if (work())
		{
			puts("POSSIBLE");
			REP(i, 0, n) REP(j, 0, m) if (~id[i][j])
			{
				if (picked[id[i][j] << 1]) g[i][j] = '|';
				else g[i][j] = '-';
			}
			REP(i, 0, n) puts(g[i]);
		}
		else puts("IMPOSSIBLE");
	}
	return 0;
}
