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
#include<unordered_set>
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

vector<int> g[MAX];
int C[MAX];
int a = -1;
int b = -1;
bool isLoop;
bool odd;
int VAL[MAX];
int n, m;

void dfs(int v, int c, int p)
{
	C[v] = c;
	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];
		if (to == p) continue;
		if (C[to] != -1)
		{
			if (a == -1)
			{
				isLoop = true;
				if (C[to] != c ^ 1) odd = true;
				a = v;
				b = to;
			}

			continue;
		}

		dfs(to, c ^ 1, v);
	}
}

void imp()
{
	cout << -1 << endl;
	exit(0);
}

void rem(int a, int b)
{
	int ind = -1;
	FOR(i, 0, SZ(g[a]))
	{
		if (g[a][i] == b)
		{
			ind = i;
			break;
		}
	}

	g[a].erase(g[a].begin() + ind);
}

LL ans = 0;
LL dfs1(int v, int p)
{
	LL bal = VAL[v];
	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];
		if (to != p)
		{
			bal += dfs1(to, v);
		}
	}
	
	ans += abs(bal);
	return bal;
}

LL f(int c)
{
	ans = 0;
	VAL[a] += c;
	VAL[b] -= c;
	dfs1(0, 0);
	VAL[a] -= c;
	VAL[b] += c;
	return ans + abs(c);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);

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

	if (n % 2) imp();
	FILL(C, -1);
	dfs(0, 0, 0);
	int cnt = 0;
	FOR(i, 0, n)
	{
		cnt += C[i];
		VAL[i] = C[i] == 0 ? -1 : 1;
	}

	if (!isLoop)
	{
		if (cnt * 2 != n) imp();
		ans = 0;
		dfs1(0, 0);
		cout << ans << endl;
		return 0;
	}

	rem(a, b);
	rem(b, a);

	if (odd)
	{
		int val = (n - 2 * cnt) / 2;
		VAL[a] += val;
		VAL[b] += val;
		ans = 0;
		dfs1(0, 0);
		cout << ans + abs(val) << endl;
		return 0;
	}

	//FOR(i, 0, n)
	//{
	//	cout << VAL[i] << " ";
	//}
	
	//cout << endl;
	if (cnt * 2 != n) imp();
	int l = -n, r = n;
	while (r - l > 2)
	{
		int l1 = l + (r - l) / 3;
		int r1 = l + 2 * (r - l) / 3;
		if (f(l1) > f(r1))
		{
			l = l1;
		}
		else
		{
			r = r1;
		}
	}

	//cout << f(l) << " " << f(l + 1) << " " << f(l + 2) << endl;
	LL ans = min(f(l), min(f(l + 1), f(l + 2)));
	cout << ans << endl;
} ./Main.cpp:66:20: warning: ^ has lower precedence than !=; != will be evaluated first [-Wparentheses]
                                if (C[to] != c ^ 1) odd = true;
                                    ~~~~~~~~~~~^
./Main.cpp:66:20: note: place parentheses around the '!=' expression to silence this warning
                                if (C[to] != c ^ 1) odd = true;
                                               ^
                                    (         )
./Main.cpp:66:20: note: place parentheses around the ^ expression to evaluate it first
                                if (C[to] != c ^ 1) odd = true;
                                               ^
                                             (    )
1 warning generated.