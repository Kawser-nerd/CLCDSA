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
typedef pair<long long, long long> PLL;


const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 2 * 1000 * 100 + 47;
const int MOD = 1000 * 1000 * 1000 + 7;

vector<int> g[MAX];
vector<int> SMAX[MAX];
string s;
int PMAX[MAX];
int P[MAX];
int CNT[MAX];
int H[MAX];

void dfs(int v, int p)
{
	int ind = -1;
	FOR(i, 0, SZ(g[v]))
	{
		if (g[v][i] == p)
		{
			ind = i;
			break;
		}
	}

	if (ind != -1)
	{
		g[v].erase(g[v].begin() + ind);
	}
	
	CNT[v] = s[v] == '1';
	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];
		dfs(to, v);
		H[v] = max(H[v], H[to] + 1);
		CNT[v] += CNT[to];
	}
}

void dfs1(int v)
{
	int pmax = -INF;
	int pmin = INF;

	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];

		PMAX[to] = max(pmax + 1, PMAX[v] + 1);
		if (i + 1 != SZ(g[v])) PMAX[to] = max(PMAX[to], SMAX[v][i + 1] + 1);

		pmax = max(pmax, H[to] + 1);
		pmin = min(pmin, H[to] + 1);
	}

	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];
		dfs1(to);
	}
}

vector<int> A;
int getMax2(int v)
{
	A.clear();
	A.push_back(PMAX[v]);
	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];
		A.push_back(H[to] + 1);
	}

	sort(ALL(A));
	reverse(ALL(A));
	if (SZ(g[v]) == 0)
	{
		if (A[0] > 1) return 1;
		return 0;
	}

	int ans = A[1] + 1;
	while (ans >= A[0]) ans--;

	return ans;
}

int getMin(int v)
{
	int ans = INF;
	if (CNT[0] != CNT[v])
	{
		ans = min(ans, PMAX[v]);
	}

	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];
		if (CNT[to] != 0)
		{
			ans = min(ans, H[to] + 1);
		}
	}


	return ans;
}

//#define DEBUG
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	FOR(i, 0, n - 1)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	cin >> s;
	dfs(0, 0);
#ifdef DEBUG
	cout << "H=" << endl;
	FOR(i, 0, n)
	{
		cout << i + 1 << " " << H[i] << endl;
	}
#endif
	FOR(v, 0, n)
	{
		SMAX[v].assign(SZ(g[v]), -INF);

		RFOR(i, SZ(g[v]), 0)
		{
			int to = g[v][i];

			if (i + 1 != SZ(g[v])) SMAX[v][i] = SMAX[v][i + 1];
			SMAX[v][i] = max(SMAX[v][i], H[to] + 1);
		}
	}

#ifdef DEBUG
	cout << "SMAX" << endl;
	FOR(i, 0, n)
	{
		cout << i + 1 << ": ";
		FOR(j, 0, SZ(g[i]))
		{
			cout << SMAX[i][j] << " ";
		}
		cout << endl;
	}
#endif
	PMAX[0] = -INF;
	if (SZ(g[0]) == 1)
	{
		PMAX[0] = 0;
	}
	dfs1(0);
	LL ans = 0;
#ifdef DEBUG
	cout << "PMAX=" << endl;
	FOR(i, 0, n)
	{
		cout << i + 1 << " " << PMAX[i] << endl;
	}

	cout << "2max" << endl;
	FOR(i, 0, n)
	{
		cout << i + 1 << " " << getMax2(i) << endl;
	}

	cout << "min" << endl;
	FOR(i, 0, n)
	{
		cout << i + 1 << " " << getMin(i) << endl;
	}
#endif

	FOR(v, 0, SZ(s))
	{
		if (s[v] == '1')
		{
			ans += getMax2(v) + 1;
			continue;
		}

		//cout << "!!" << getMax2(v) << " " << getMin(v) << endl;
		ans += max(getMax2(v) - getMin(v) + 1, 0);
	}
	
	cout << ans + 1 << endl;
}