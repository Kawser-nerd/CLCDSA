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
vector<PII> g[MAX];
vector<PLL> A[MAX];
int sz;

bool cmp(PLL a, PLL b)
{
	return a.second < b.second;
}

int dfs(int v, LL T)
{
	if (SZ(g[v]) == 0)
	{
		A[sz].push_back(MP(0, 0));
		sz++;
		return sz - 1;
	}

	int i1 = dfs(g[v][0].first, T);
	int i2 = dfs(g[v][1].first, T);
	int vi = g[v][0].second;
	int vk = g[v][1].second;
	int p = 0;
	sort(ALL(A[i1]), cmp);
	sort(ALL(A[i2]));
	LL mind = LINF;
	RFOR(i, SZ(A[i1]), 0)
	{
		LL a = A[i1][i].first;
		LL b = A[i1][i].second;
		while (p != SZ(A[i2]) && b + A[i2][p].first + vi + vk <= T)
		{
			mind = min(A[i2][p].second, mind);
			p++;
		}

		if (mind == LINF) continue;
		A[sz].push_back(MP(a + vi, mind + vk));
	}

	sort(ALL(A[i1]));
	sort(ALL(A[i2]), cmp);
	LL minc = LINF;
	p = 0;
	
	RFOR(i,SZ(A[i1]), 0)
	{
		LL a = A[i1][i].first;
		LL b = A[i1][i].second;

		while (p != SZ(A[i2]) && a + A[i2][p].second + vi + vk <= T)
		{
			minc = min(minc, A[i2][p].first);
			p++;
		}

		if (minc == LINF) continue;
		A[sz].push_back(MP(minc + vk, b + vi));
	}

	sz++;
	return sz - 1;
}

bool ok(LL c)
{
	FOR(i, 0, sz) A[i].clear();
	sz = 0;
	int ind = dfs(0, c);
	return SZ(A[ind]);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int n, p, v;
	cin >> n;
	FOR(i, 0, n - 1)
	{
		cin >> p >> v;
		p--;
		g[p].push_back(MP(i + 1, v));
	}

	LL l = -1, r = 1000 * (LL)1000 * (LL)1000 * (LL)1000;
	while (r - l > 1)
	{
		//cout << l << " " << r << endl;
		LL c = (r + l) / 2;
		if (ok(c))
		{
			r = c;
		}
		else
		{
			l = c;
		}
	}

	cout << r << endl;
}