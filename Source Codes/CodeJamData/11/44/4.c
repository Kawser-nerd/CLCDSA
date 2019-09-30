#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <typeinfo>
#include <utility>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstddef>
#include <complex>
#include <ctime>
#include <cassert>
using namespace std;

typedef long long int64;
static inline int Rint()
{
	struct X{ int dig[256]; X(){
	for(int i = '0'; i <= '9'; ++i) dig[i] = 1; dig['-'] = 1;
	}};
	static 	X fuck;int s = 1, v = 0, c;
	for (;!fuck.dig[c = getchar()];);
	if (c == '-') s = 0; else if (fuck.dig[c]) v = c ^ 48;
	for (;fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48));
	return s ? v : -v;
}
typedef vector<int> vi;
typedef vi::iterator ivi;
typedef map<int, int> mii;
typedef mii::iterator imii;
typedef set<int> si;
typedef si::iterator isi;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define rep(i, s, e) for (int i = (s); i < (e); ++i)
#define foreach(itr, c) for(__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); ++itr)
template<typename T> void cmax(T& a, const T& b){if(b>a)a=b;}
template<typename T> void cmin(T& a, const T& b){if(b<a)a=b;}

int mat[512][512];
vi adj[512];
int level[512];
int n, w;
void init()
{
	memset(mat, 0, sizeof mat);
	memset(level, -1, sizeof level);
	rep(i, 0, 512) adj[i].clear();
}
void bfs()
{
	queue<int> q;
	q.push(0);
	level[0] = 0;
	while (!q.empty())
	{
		int curr = q.front(); q.pop();
		foreach(it, adj[curr])
		{
			int x = *it;
			if (level[x] != -1) continue;
			level[x] = level[curr] + 1;
			q.push(x);
		}
	}
}

int best = 0;
int L;
int path[256];
void dfs(int curr)
{
	path[level[curr]] = curr;
	if (level[curr] == L)
	{
		if (mat[1][curr] == 0) return;
		int where[256] = {0};
		
		for (int i = 0; i <= level[curr]; ++i) where[path[i]] = 1;
		set<int> x;
		for (int i = 0; i <= level[curr]; ++i)
		{
			int t = path[i];
			foreach(it, adj[t])
			{
				if (where[*it] == 0) x.insert(*it);
			}
		}
		if (sz(x) > best) best = sz(x);
	}
	else
	{
		foreach(it, adj[curr])
		{
			if (level[*it] == level[curr] + 1) dfs(*it);
		}
	}
}

int main()
{
	int T = Rint();
	for (int caseID = 1; caseID <= T; ++caseID)
	{
		n = Rint(), w = Rint();
		init();
		while (w--)
		{
			int u, v;
			scanf("%d,%d", &u, &v);
			mat[u][v] = mat[v][u] = 1;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		bfs();
		printf("Case #%d: %d ", caseID, level[1]-1);
		L = level[1] - 1;
		best = 0;
		dfs(0);
		printf("%d\n", best);
	}
	return 0;
}
