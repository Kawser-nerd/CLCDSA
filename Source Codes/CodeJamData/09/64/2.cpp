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

struct tp{int x, y;};

int n, m, qq, k, z;
tp p[1024];
int r[1024];
int s[1024];
int a[1024][1024];
int f[1024][1024];
bool g[1024][1024];
bool g2[1024][1024];
bool u[1024];
int d[1024];
int q[1024];
int pa[1024];
int t[1024];
int tt;
VI w[1024];
//int col[1024];
int e[1024];
//int num[1024];

void dfs1(int v)
{
	u[v] = true;
	forn(i, k)
	{
		if (!u[i] && g[v][i])
		{
			dfs1(i);
		}
	}
	t[tt++] = v;
}

void dfs2(int v)
{
	u[v] = true;
//	col[v] = z;
	w[z].pb(v);
	e[z] += s[v];
	forn(i, k)
	{
		if (!u[i] && g[i][v])
		{
			dfs2(i);
		}
	}
	t[tt++] = v;
}

int dist2(tp p1, tp p2)
{
	return sqr(p1.x-p2.x) + sqr(p1.y-p2.y);
}

int find(int st, int en)
{
	int qb, qe;
	qb = qe = 0;
	clr(d);
	d[st] = 1000000;
	q[qe++] = st;

	while (qb != qe)
	{
		int p = q[qb++];
		forn(i, z + 2)
		{
			if (a[p][i] - f[p][i] > 0 && !d[i])
			{
				d[i] = min(d[p], a[p][i] - f[p][i]);
				pa[i] = p;
				q[qe++] = i;
			}
		}
	}

	return d[en];
}

void flow(int st, int en)
{
	for(;;)
	{
		int j = find(st, en);
//		cerr << "f = " << j << endl;
		if (j == 0) break;

		int k = en;
		while (k != st)
		{
			f[pa[k]][k] += j;
			f[k][pa[k]] -= j;
			k = pa[k];
		}
	}
}

void dfs(int v)
{
	u[v] = true;
	forn(i, z+2)
	{
		if (!u[i] && a[v][i] - f[v][i] > 0)
		{
			dfs(i);
		}
	}
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		scanf("%d", &k);
		forn(i, k)
		{
			scanf("%d%d%d%d", &p[i].x, &p[i].y, &r[i], &s[i]);
		}

		clr(g);
		forn(i, k)
		{
			forn(j, k)
			{
				if (i == j)
				{
//					cerr << g[i][j] << " ";
					continue;
				}
				if (dist2(p[i], p[j]) <= r[i] * r[i])
				{
					g[i][j] = true;
				}
//				cerr << g[i][j] << " ";
			}
//			cerr << endl;
		}

		clr(a);
		tt = 0;
		clr(u);
		forn(i, k)
		{
			if (!u[i])
			{
				dfs1(i);
			}
		}

		clr(e);
		z = 0;
		clr(u);
		ford(i1, k)
		{
			int i = t[i1];
			if (!u[i])
			{
//				cerr << i << endl;
				dfs2(i);
				z++;
			}
		}

		clr(g2);
		forn(i, z)
		{
			forn(j, z)
			{
				if (i == j) continue;
				forn(i1, w[i].sz)
				{
					forn(j1, w[j].sz)
					{
						if (g[w[i][i1]][w[j][j1]])
						{
							g2[i][j] = true;
						}
					}
				}
			}
		}

		n = m = 0;
		forn(i, z)
		{
			if (e[i] >= 0)
			{
//				num[i] = n;
				n++;
			}
			else
			{
//				num[i] = m;
				m++;
			}
		}

		int st = z;
		int en = z + 1;

		clr(f);
		forn(i, z)
		{
			if (e[i] >= 0)
			{
				a[st][i] = e[i];
			}
			else
			{
				a[i][en] = -e[i];
			}
		}
		forn(i, z)
		{
			forn(j, z)
			{
//				cerr << g2[i][j] << " ";
				if (g2[i][j])
				{
					a[i][j] = 1000000;
				}
			}
//			cerr << endl;
		}
//		cerr << z << endl;
//		forn(i, z)
//		{
//			cerr << e[i] << " ";
//		}
//		cerr << endl;

		flow(st, en);
/*		forn(i, z+2)
		{
			forn(j, z+2)
			{
				cerr << a[i][j] << " ";
			}
			cerr << endl;
		}
*/
		clr(u);
		dfs(st);
		int ans = 0;

		forn(i, z)
		{
			if (u[i])
			{
				ans += e[i];
			}
		}

		printf("Case #%d: %d\n", ii+1, ans);

		forn(i, z)
		{
			w[i].clear();
		}
	}

	return 0;
}
