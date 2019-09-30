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

#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define RFOR(i,b,a) for(int i = (b) - 1; i >= (a); i--)
#define ITER(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a, value) memset(a, value, sizeof(a))

#define SZ(a) (int) a.size()
#define ALL(a) a.begin(),a.end()
#define PB push_back
#define MP make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double PI = acos(-1.0);
const LL INF = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * (LL)INF;

const int MAX = 1000 * 100 + 47;

vector<PII> g[MAX];
int S[MAX];
LL res = 0;
int n;

void dfsSZ(int v, int p)
{
	//cout << v << ": " << p << endl;
	S[v] = 1;
	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i].first;
		int w = g[v][i].second;

		if (to == p) continue;
		dfsSZ(to, v);
		res += 2 * min(S[to], n - S[to]) * (LL)w;
		S[v] += S[to];
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	FOR(i, 0, n - 1)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		g[a].push_back(MP(b, c));
		g[b].push_back(MP(a, c));
	}

	dfsSZ(0, -1);
	//cout << "res=" << res << endl;
	int v = 0;
	int p = -1;

	while (1)
	{
		int w = -1;
		FOR(i, 0, SZ(g[v]))
		{
			int to = g[v][i].first;

			if (S[to] * 2 > n && to != p)
			{
				w = to;
				break;
			}
		}

		if (w == -1) break;
		p = v;
		v = w;
	}

	//cout << v + 1 << endl;
	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i].first;
		int w = g[v][i].second;
		if (S[to] * 2 == n)
		{
			cout << res - w << endl;
			return 0;
		}
	}

	LL ans = -LINF;
	FOR(i, 0, SZ(g[v]))
	{
		int w = g[v][i].second;
		ans = max(ans, res - w);
	}

	cout << ans << endl;
}