#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker,"/STACK:64000000")
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <cassert>
#include <time.h>
#include <bitset>

using namespace std;

#define mp make_pair
#define pb push_back
#define _(a,b) memset( (a), b, sizeof( a ) )
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#ifdef WIN32
#define dbg(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}
#define dbgx(x) {cerr << #x << " = " << x << endl;}
#define dbgv(v) {cerr << #v << " = {"; for (typeof(v.begin()) it = v.begin(); it != v.end(); it ++) cerr << *it << ", "; cerr << "}"; cerr << endl;}
#else
#define dbg(...) { }
#define dbgx(x) { }
#define dbgv(v) { }
#endif

typedef unsigned long long ull;
typedef long long lint;
typedef pair < int , int > pii;
typedef long double ld;

const int INF = 1000 * 1000 * 1000;
const lint LINF = 1000000000000000000LL;
const double eps = 1e-9;

void prepare()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

const int nmax = 55;

int n, m, used[nmax], vis[nmax];
string s[nmax];
vector < int > g[nmax];
int f[nmax][nmax];
string ans;
vector < int > path;

int dfs(int v)
{
	if (used[v] == 2) return 0;
	if (vis[v]) return 0;
	vis[v] = 1;
	int ret = 1;
	for (int i = 0; i < sz(g[v]); i ++)
	{
		int to = g[v][i];
		ret += dfs(to);
	}
	return ret;
}

bool canVisitAll(int start)
{
	int need = n;
	for (int i = 0; i < n; i ++)
	{
		vis[i] = 0;
		if (used[i] == 2)
		{
			need--;
		}
	}
	int cnt = dfs(start);
	return cnt == need;
}

void init()
{
	ans = "";
	path.clear();
	_(f, 0);
	for (int i = 0; i < nmax; i ++)
		g[i].clear();
	_(used, 0);
}

void read()
{
	init();

	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		cin >> s[i];
	for (int i = 0; i < m; i ++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
		f[x][y] = f[y][x] = 1;
	}
}

int getMinCode()
{
	string bst = s[0];
	int ret = 0;
	for (int i = 1; i < n; i ++)
	{
		if (s[i] < bst)
		{
			bst = s[i];
			ret = i;
		}
	}
	return ret;
}

bool cmp(int i, int j)
{
	return s[i] < s[j];
}

vector < int > getCandidates()
{
	vector < int > ret;
	for (int i = 0; i < sz(path); i ++)
	{
		int v = path[i];
		for (int j = 0; j < sz(g[v]); j ++)
		{
			int to = g[v][j];
			if (used[to] == 0)
			{
				ret.pb(to);
			}
		}
	}
	sort(all(ret), cmp);
	return ret;
}

bool can(int target)
{
	int v = path.back();
	int it = sz(path) - 1;
	while (!f[v][target])
	{
		used[v] = 2;
		v = path[--it];
	}

	bool ret = canVisitAll(v);

	v = path.back();
	it = sz(path) - 1;
	while (!f[v][target])
	{
		used[v] = 1;
		v = path[--it];
	}

	return ret;
}

void doit(int v)
{
	while (1)
	{
		vector < int > cand = getCandidates();
		if (sz(cand) == 0)
			return;

		bool ok = false;
		for (int i = 0; i < sz(cand); i ++)
		{
			int to = cand[i];
			if (can(to))
			{
				ok = true;
				while (!f[v][to])
				{
					used[v] = 2;
					path.pop_back();
					v = path.back();
				}
				path.pb(to);
				used[to] = 1;
				ans += s[to];
				v = to;
				break;
			}
		}
		assert(ok);
	}
}

bool solve()
{
	read();
	int start = getMinCode();

	ans = s[start];
	used[start] = 1;
	path.pb(start);
	doit(start);

	cout << ans << endl;
	return false;
}

int main()
{
	prepare();
	int t;
	scanf("%d",&t);
	for (int i = 0; i < t; i ++)
	{
		dbg("Test %d\n", i);
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
