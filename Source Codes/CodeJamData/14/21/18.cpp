#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker,"/STACK:64000000")
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <cassert>
#include <time.h>
#include <bitset>

using namespace std;

#define mp make_pair
#define pb push_back
#define _(a,b) memset( (a), b, sizeof( a ) )
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#ifdef WIN32
#define dbg(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}
#define dbgx(x) {cerr << #x << " = " << x << endl;}
#define dbgv(v) {cerr << #v << " = {"; for (typeof(v.begin()) it = v.begin(); it != v.end(); it ++) cerr << *it << ", "; cerr << "}"; cerr << endl;}
#else
#define dbg(...) { }
#define dbgx(x) { }
#define dbgv(v) { }
#endif

typedef unsigned long long ull;
typedef long long lint;
typedef pair < int , int > pii;
typedef long double ld;

const int INF = 1000 * 1000 * 1000;
const lint LINF = 1000000000000000000LL;
const double eps = 1e-9;

void prepare()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

const int nmax = 105;

int cnt[nmax][nmax];
string s[nmax], t[nmax];
int n;

string compress(int id, string s)
{
	string ret = "";
	for (int i = 0; i < sz(s); i ++)
	{
		if (i > 0 && s[i - 1] == s[i])
		{
			cnt[id][sz(ret) - 1]++;
			continue;
		}
		cnt[id][sz(ret)] = 1;
		ret.pb(s[i]);
	}
	return ret;
}

void read()
{
	_(cnt, 0);
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> s[i];
}

int calc(int pos)
{
	int bst = INF;
	for (int i = 1; i <= 100; i ++)
	{
		int cost = 0;
		for (int j = 0; j < n; j ++)
		{
			cost += abs( i - cnt[j][pos] );
		}
		bst = min(bst, cost);
	}
	return bst;
}

bool solve()
{
	read();
	for (int i = 0; i < n; i ++)
	{
		t[i] = compress(i, s[i]);
		if (t[i] != t[0])
		{
			printf("Fegla Won\n");
			return false;
		}
	}
	int ans = 0;
	for (int i = 0; i < sz(t[0]); i ++)
	{
		ans += calc(i);
	}
	printf("%d\n", ans);
	return false;
}

int main()
{
	prepare();
	int t;
	scanf("%d",&t);
	for (int i = 0; i < t; i ++)
	{
		dbg("Test %d\n", i);
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}
