#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>

using namespace std;

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

typedef vector<int> VI;
typedef pair<int, int> pii;
typedef long long ll;

#define NMAX 505

int n, k;
vector<int> g[NMAX];

struct Vert
{
	int id;
	int h;
};
int prev[NMAX];
Vert vert[NMAX];

void dfs(int v, int p)
{
	prev[v] = p;
	forv(i, g[v])
	{
		int u = g[v][i];
		if (u != p)
		{
			vert[u].h = vert[v].h + 1;
			dfs(u, v);						
		}
	}
}

bool Cmp(const Vert& v1, const Vert& v2)
{
	return v1.h < v2.h;
}

ll mod = 1000000009ll;

ll ans;
bool used[NMAX];

void calc(int v)
{
	int p = prev[v];
	int cnt = 0;
	forv(i, g[p])
	{
		if (g[p][i] != prev[p] && used[g[p][i]]) ++cnt;
	}
	p = prev[p];
	if (p != -1)
	{
		forv(i, g[p])
		{
			if (g[p][i] != prev[p] && used[g[p][i]]) ++cnt;
		}	
		if (used[p]) ++cnt;
	}

	if (cnt < k) ans = (ans * ll(k - cnt)) % mod;
	else ans = 0;
	used[v] = true;
}
void solve(int test)
{
	printf("Case #%d: ", test);
	scanf("%d %d", &n, &k);
	int u, v;
	forn(i, n) g[i].clear();
	forn(i, n - 1)
	{
		scanf("%d %d", &u, &v);
		--u; --v;
		g[u].pb(v);
		g[v].pb(u);
	}
	forn(i, n)
	{
		vert[i].id = i;
		vert[i].h = 0;
	}
	dfs(0, -1);
	sort(vert, vert + n, Cmp);
	ans = 1;
	forn(i, n) used[vert[i].id] = false;
	for1(i, n - 1)
	{
		calc(vert[i].id);
	}
	cout << ans << endl;
}
int main()
{
	freopen(CIN_FILE, "rt", stdin);
	freopen(COUT_FILE, "wt", stdout);

	int tc; scanf("%d", &tc);
	forn(it, tc)
	{
		solve(it + 1);
	}
	return 0;
}
         	

