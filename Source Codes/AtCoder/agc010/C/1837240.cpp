#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iterator>
#include <bitset>
#include <ctime>
#include<complex>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b)-1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))

#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 1000 * 100 + 47;

int n;
int A[MAX];
vector<int> g[MAX];
vector<int> L[MAX];

void no()
{
	cout << "NO" << endl;
	exit(0);
}

LL dfs(int v, int p)
{
	if (SZ(g[v]) == 1 && v != 0) return A[v];
	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];
		if (to == p) continue;
		L[v].push_back(dfs(to, v));
	}

	LL s = 0;
	int maxx = -INF;
	FOR(i, 0, SZ(L[v]))
	{
		s += L[v][i];
		maxx = max(maxx, L[v][i]);
	}

	if (A[v] > s) no();
	LL all = s;
	if (maxx > s - maxx)
	{
		all = 2 * (s - maxx);
	}

	if (2 * (s - A[v]) > all) no();
	
	LL totop = s - 2 * (s - A[v]);
	if (v == 0)
	{
		if (SZ(g[v]) == 1 && A[v] != totop) no();
		if (SZ(g[v]) != 1 && totop != 0) no();
	}

	return totop;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	FOR(i, 0, n) cin >> A[i];
	FOR(i, 0, n - 1)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(0, 0);
	cout << "YES" << endl;
	return 0;
}