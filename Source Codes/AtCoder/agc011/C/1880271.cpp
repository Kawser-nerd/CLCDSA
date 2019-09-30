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

const int MAX = 100000 + 47;
const int MOD = 1000 * 1000 * 1000 + 7;

vector<int> g[MAX];
int C[MAX];
int numb;
bool is;
LL o, e, iz;

void dfs(int v, int c)
{
	if (C[v] != -1)
	{
		if (C[v] != c) is = false;
		return;
	}

	numb++;
	C[v] = c;
	FOR(i, 0, SZ(g[v]))
	{
		int to = g[v][i];
		dfs(to, c ^ 1);
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
	
	FILL(C, -1);
	FOR(i, 0, n)
	{
		if (C[i] == -1)
		{
			numb = 0;
			is = true;
			dfs(i, 0);

			if (numb == 1)
			{
				iz++;
				continue;
			}

			if (is) e++; else o++;
		}
	}

	//cout << res << endl;
	LL res = 2 * e * e + o * o + 2 * o * e + n * iz + iz * (n - iz);
	cout << res << endl;
}