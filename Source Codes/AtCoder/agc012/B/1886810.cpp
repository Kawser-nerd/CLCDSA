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

struct Item
{
	int v, d, c;
};

Item Q[MAX];
vector<int> g[MAX];
int U[MAX];
int D[MAX];
int C[MAX];
int iter;

void dfs(int v, int d, int curD, int color)
{
	if (d > curD) return;
	if (curD - d <= D[v]) return;
	D[v] = curD - d;
	if (C[v] == 0) C[v] = color;
	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];
		dfs(to, d + 1, curD, color);
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	FOR(i, 0, m)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int q;
	cin >> q;
	FOR(i, 0, q)
	{
		cin >> Q[i].v >> Q[i].d >> Q[i].c;
		Q[i].v--;
	}

	reverse(Q, Q + q);
	FILL(D, -1);
	FOR(i, 0, q)
	{
		dfs(Q[i].v, 0, Q[i].d, Q[i].c);
	}

	FOR(i, 0, n)
	{
		//cout << i + 1 << ": " << C[i] << "\n";
		cout << C[i] << "\n";

	}
}