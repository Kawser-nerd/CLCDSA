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

vector<int> V;
vector<int> g[MAX];
int U[MAX];

void dfs(int v)
{
	U[v] = 1;
	V.push_back(v);
	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];
		if (U[to]) continue;
		
		dfs(to);
		break;
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
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

	U[0] = 1;
	V.push_back(0);
	dfs(g[0][0]);
	reverse(ALL(V));

	FOR(i, 0, SZ(g[0]))
	{
		int to = g[0][i];
		if (U[to]) continue;

		dfs(to);
		break;
	}

	cout << SZ(V) << endl;
	FOR(i, 0, SZ(V))
	{
		cout << V[i] + 1 << " ";
	}
	cout << endl;
}