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

const int nmax = 35;

bool bit(int msk, int i)
{
	return msk & (1 << i);
}

int A, B, K;
int a[nmax], b[nmax], c[nmax], n;
lint dp[nmax][2][2][2];

void convert(lint x, int * a)
{
	int len = 0;
	for (int i = 0; i < n; i ++)
	{
		a[i] = bit(x, i);
	}
	reverse(a, a + n);
}

void upd(int pos, int i, int j, int k, lint val)
{
	dp[pos][i][j][k] += val;
}

bool solve()
{
	cin >> A >> B >> K;
	A--;
	B--;
	K--;
	n = 31;
	convert(A, a);
	convert(B, b);
	convert(K, c);
	
	_(dp, 0);
	upd(0, 0, 0, 0, 1);
	for (int pos = 0; pos < n; pos ++)
	{
		for (int fa = 0; fa <= 1; fa ++)
		{
			for (int fb = 0; fb <= 1; fb ++)
			{
				for (int fc = 0; fc <= 1; fc ++)
				{
					lint cur = dp[pos][fa][fb][fc];
					if (!cur) continue;

					int boundA = (fa ? 1 : a[pos]);
					int boundB = (fb ? 1 : b[pos]);
					int boundC = (fc ? 1 : c[pos]);
					for (int xa = 0; xa <= boundA; xa ++)
					{
						for (int xb = 0; xb <= boundB; xb ++)
						{
							int res = (xa & xb);
							if (res <= boundC)
							{
								upd(pos + 1, fa | (xa < boundA), fb | (xb < boundB), fc | (res < boundC), cur);
							}
						}
					}
				}
			}
		}
	}
	lint ans = 0;
	for (int i = 0; i < 2; i ++)
	{
		for (int j = 0; j < 2; j ++)
		{
			for (int k = 0; k < 2; k ++)
			{
				ans += dp[n][i][j][k];
			}
		}
	}
	printf("%lld\n", ans);
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
