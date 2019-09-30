#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define bublic public
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en) for(__typeof(en) i=(st); i<=(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(__typeof(n) i=0; i<(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

int qq, n, m;
int p[1024];
PII g[1024];
bool a[1024][1024];
int u[1024];
VI b[1024];
int q[1024];

bool check1()
{
	forn(i, n)
	{
		forn(j, i)
		{
			if (abs(p[i] - p[j]) <= 1) return false;
		}
	}
	return true;
}

bool dfs(int k, int col)
{
	u[k] = col;
	forn(i, n)
	{
		if (a[k][i])
		{
			if (!u[i])
			{
				if (!dfs(i, 3 - col)) return false;
			}
			else
			{
				if (u[i] != 3 - col) return false;
			}
		}
	}
	return true;
}

bool check2()
{
	clr(a);
	forn(i, n)
	{
		For(l, -1, 1)
		{
			For(j, i+1, n-1)
			{
				if (p[i] == p[j] + l)
				{
					a[i][j] = true;
					a[j][i] = true;
					break;
				}
			}
		}
	}

	clr(u);
	forn(i, n)
	{
		if (!u[i])
		{
			if (!dfs(i, 0)) return false;
		}
	}

	return true;
}

bool check3()
{
	clr(u);

	forn(i, n)
	{
		forn(j, n)
		{
			if (a[i][j])
			{
				b[i].pb(j);
			}
		}
	}

	int qb = 0;
	int qe = 0;

l1:;
	forn(i, n)
	{
		if (!u[i]) continue;
		bool bb = false;
		forn(j1, b[i].sz)
		{
			int j = b[i][j1];
			if (u[j]) continue;
			if (abs(p[i] - p[j]) == 1)
			{
				int t = 1;
				if (u[i] == t) t++;
				u[j] = t;
				q[qe++] = j;
				bb = true;
				break;
			}
		}
		if (bb) break;
	}

	if (qb == qe)
	{
		forn(i, n)
		{
			if (u[i]) continue;
			bool bb = false;
			forn(j1, b[i].sz)
			{
				int j = b[i][j1];
				if (u[j]) continue;
				if (abs(p[i] - p[j]) == 1)
				{
					u[i] = 1;
					u[j] = 2;
					q[qe++] = i;
					q[qe++] = j;
					bb = true;
					break;
				}
			}
			if (bb) break;
		}
	}

	if (qb == qe) return true;
	while (qb != qe)
	{
		int i = q[qb++];
		forn(j1, b[i].sz)
		{
			int j = b[i][j1];
			if (!u[j]) continue;
			forn(k1, b[j].sz)
			{
				int k = b[j][k1];
				if (!a[k][i]) continue;
				if (u[k])
				{
					if (k == i || k == j) continue;
					if (u[k] == u[i] || u[k] == u[j])
					{
						return false;
					}
					continue;
				}
				u[k] = 6 - u[i] - u[j];
				q[qe++] = k;
			}
		}
	}
	bool bb = true;
	forn(i, n)
	{
		if (!u[i])
		{
			bb = false;
			break;
		}
	}
	if (!bb)
	{
		goto l1;
	}

	return true;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		scanf("%d", &n);
		int ans = 4;
		forn(i, n)
		{
			scanf("%d%d", &g[i].first, &g[i].second);
		}
		sort(g, g+n);
		forn(i, n)
		{
			p[i] = g[i].second;
		}

		if (check1())
		{
			ans = 1;
		}
		else if (check2())
		{
			ans = 2;
		}
		else if (check3())
		{
			ans = 3;
		}
		forn(i, n)
		{
			b[i].clear();
		}

		printf("Case #%d: %d\n", ii+1, ans);
		fflush(stdout);
	}

	return 0;
}
