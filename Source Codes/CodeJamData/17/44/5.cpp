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

const int maxn = 110;

int n, m, K;
char g[maxn + 5][maxn + 5];

vector<int> dom[maxn + 5][maxn + 5];

int ns, nt;
int id[maxn + 5][maxn + 5];

const int walk[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int seq[maxn + 5][maxn + 5];
int seqn[maxn + 5];

inline void BFS(int i, int j)
{
	static bool vis[maxn + 5][maxn + 5];
	static int dis[maxn + 5][maxn + 5];
	static bool vist[maxn + 5];
	memset(vist, 0, sizeof vist);
	memset(vis, 0, sizeof vis);
	queue<pair<int, int> > q;
	dis[i][j] = 0;
	vis[i][j] = 1;
	q.push(mp(i, j));
	seqn[id[i][j]] = 0;
	while (!q.empty())
	{
		pair<int, int> x = q.front(); q.pop();
		for (auto t : dom[x.x][x.y]) if (!vist[t]) seq[id[i][j]][seqn[id[i][j]]++] = t, vist[t] = 1;
		if (dis[x.x][x.y] == K) continue;
		REP(k, 0, 4)
		{
			int u = x.x + walk[k][0], v = x.y + walk[k][1];
			if (u < 0 || u >= n || v < 0 || v >= m || g[u][v] == '#') continue;
			if (!vis[u][v]) dis[u][v] = dis[x.x][x.y] + 1, vis[u][v] = 1, q.push(mp(u, v));
		}
	}
}

bool vis[maxn + 5];
int lk[maxn + 5];

int atk[maxn + 5];

bool find(int x)
{
	REP(i, 0, seqn[x])
	{
		int y = seq[x][i];
		if (!vis[y])
		{
			vis[y] = 1;
			if (!~lk[y] || find(lk[y]))
			{
				lk[y] = x;
				return 1;
			}
		}
	}
	return 0;
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
		debug("%d\n", case_id);
		printf("Case #%d: ", case_id);;
		scanf("%d%d%d", &m, &n, &K);
		REP(i, 0, n) scanf("%s", g[i]);
		ns = nt = 0;
		REP(i, 0, n) REP(j, 0, m) dom[i][j].clear();
		REP(i, 0, n) REP(j, 0, m) 
			if (g[i][j] == 'T')
			{
				id[i][j] = nt++;
				REP(k, 0, 4)
				{
					int u = i, v = j;
					while (u >= 0 && u < n && v >= 0 && v < m && g[u][v] != '#')
					{
						dom[u][v].pb(id[i][j]);
						u += walk[k][0], v += walk[k][1];
					}
				}
			}
		REP(i, 0, n) REP(j, 0, m) if (g[i][j] == 'S')
		{
			id[i][j] = ns++;
			BFS(i, j);
		}
		memset(lk, -1, sizeof lk);
		int ans = 0;
		REP(i, 0, ns)
		{
			memset(vis, 0, sizeof vis);
			ans += find(i);
		}
		printf("%d\n", ans);
		memset(atk, -1, sizeof atk);
		REP(i, 0, nt) if (~lk[i]) atk[lk[i]] = i;
		static bool destroyed[maxn + 5];
		memset(destroyed, 0, sizeof destroyed);
		REP(i, 0, ans)
		{
			bool ok = 0;
			REP(j, 0, ns) if (~atk[j])
			{
				REP(k, 0, seqn[j])
				{
					if (!destroyed[seq[j][k]])
					{
						if (seq[j][k] == atk[j]) ok = 1;
						break;
					}
				}
				if (ok)
				{
					destroyed[atk[j]] = 1;
					printf("%d %d\n", j + 1, atk[j] + 1);
					break;
				}
			}
			assert(ok);
		}
	}
	return 0;
}
