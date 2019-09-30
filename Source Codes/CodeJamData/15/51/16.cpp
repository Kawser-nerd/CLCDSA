#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int maxn = (int) 1e6 + 100;
int s[maxn];
int m[maxn];
vector <pair <int, int> > ve;
vector <int> g[maxn];

multiset <int> cur;
bool onSegm[maxn], sw[maxn];

void dfsOn(int v)
{
	if (!onSegm[v] )
		return;
	sw[v] = true;
//	eprintf("ins %d %d\n", v, s[v] );
	cur.insert(s[v] );
	for (int i = 0; i < (int) g[v].size(); i++)
		dfsOn(g[v][i] );
}

void swOn(int v)
{
//	eprintf("ON %d\n", v);
	onSegm[v] = true;
	if (v != 0 && !sw[m[v] ] )
		return;
	dfsOn(v);
}

void dfsOff(int v)
{
	if (!sw[v] )
		return ;
	sw[v] = false;
//	eprintf("er %d\n", v);
	cur.erase(cur.find(s[v] ) );
	for (int i = 0; i < (int) g[v].size(); i++)
		dfsOff(g[v][i] );
}

void swOff(int v)
{
//	eprintf("OFF %d\n", v);
	onSegm[v] = false;
	dfsOff(v);
}

int d;
bool bad()
{
	if (cur.empty() )
		return false;
//	eprintf("%d %d\n", *cur.rbegin(), *cur.begin() );
	return (*cur.rbegin() - *cur.begin() > d);
}


void solve()
{
	int n;
	scanf("%d%d", &n, &d);
	
	cur.clear();
	ve.clear();
	for (int i = 0; i < n; i++)
	{
		sw[i] = false;
		onSegm[i] = false;
		g[i].clear();
	}
	
	int as, cs, rs;
	scanf("%d%d%d%d", &s[0], &as, &cs, &rs);
	int am, cm, rm;
	scanf("%d%d%d%d", &m[0], &am, &cm, &rm);


	for (int i = 1; i < n; i++)
	{
		s[i] = (s[i - 1] * 1LL * as + cs) % rs;
		m[i] = (m[i - 1] * 1LL * am + cm) % rm;
	}
	m[0] = -1;
	for (int i = 1; i < n; i++)
	{
		m[i] %= i;
		g[m[i] ].push_back(i);
//		eprintf("%d : %d %d\n", i, s[i], m[i] );
	}
	for (int i = 0; i < n; i++)
	{
		ve.push_back(make_pair(s[i], i) );
	}
	sort(ve.begin(), ve.end() );
	
	int pl = 0;

	int ans = 0;
	for (int pr = 0; pr < n; pr++)
	{
		swOn(ve[pr].second);
		while (bad() )
		{
			swOff(ve[pl++].second);
		}
//		eprintf("%d %d\n", pl, pr);
		int curans = (int) cur.size();
		ans = max(ans, curans);
	}
	printf("%d\n", ans);
}

void multitest()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("Case #%d: ", i);
		eprintf("Case #%d .. %d\n", i, n);
		solve();
	}


}

int main(int argc, char **)
{
	if (argc == 1)
		multitest();
	else
		solve();

	return 0;
}


