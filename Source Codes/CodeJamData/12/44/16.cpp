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
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

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

const int dx[3] = {0, 0, -1};
const int dy[3] = {-1, 1, 0};

int qq;
int n, m, k;
char a[128][128];
bool u[128][128];
int ly[10240];
int ry[10240];
int xx[10240];
i64 w[64];
i64 g[64];
i64 e[64];
i64 f[64];
i64 q[102400][64];
set < i64 > ss;

void dfs(int x, int y)
{
	u[x][y] = true;
	forn(l, 3)
	{
		int xn = x + dx[l];
		int yn = y + dy[l];
		if (xn < 0 || xn >= n || yn < 0 || yn >= m || a[xn][yn] == '#' || u[xn][yn]) continue;
		dfs(xn, yn);
	}
}

i64 calc_h(i64 *a)
{
	i64 z = 0;
	forn(i, n)
	{
		z = z * 23931117LL + a[i] * 3 + 17;
	}
	return z;
}

void solve(int k, int &cnt, int &ans)
{
	cnt = ans = 0;
	int x0 = 0, y0 = 0;
	forn(i, n)
	{
		forn(j, m)
		{
			if (a[i][j] == '0' + k)
			{
				x0 = i;
				y0 = j;
			}
		}
	}
	clr(u);
	dfs(x0, y0);
	forn(i, n)
	{
		forn(j, m)
		{
			cnt += u[i][j];
		}
	}

	clr(w);
	clr(g);
	forn(i, n)
	{
		forn(j, m)
		{
			if (a[i][j] == '#') w[i] |= 1LL << j;
			if (u[i][j]) g[i] |= 1LL << j;
		}
	}
	memcpy(f, g, sizeof(g));

	ss.clear();
	clr(e);
	e[x0] |= 1LL << y0;
	i64 fh = calc_h(e);
	i64 hh = calc_h(f);
	ss.insert(hh);
	int qb, qe;
	qb = qe = 0;
	memcpy(q[qe++], f, sizeof(f));
	while (qb != qe)
	{
		memcpy(f, q[qb++], sizeof(f));
		{
			forn(i, n)
			{
				e[i] = ((f[i] >> 1) & ~w[i]) | (f[i] & (w[i] << 1));
			}
			bool ok = true;
			forn(i, n)
			{
				if ((e[i] | g[i]) != g[i])
				{
					ok = false;
					break;
				}
			}
			if (ok)
			{
				i64 hh = calc_h(e);
				if (hh == fh)
				{
					ans = 1;
/*					forn(i, n)
					{
						forn(j, m)
						{
							cerr << ((f[i] >> j) & 1);
						}
						cerr << endl;
					}
					cerr << "1? " << endl;*/
					return;
				}
				if (!ss.count(hh))
				{
					ss.insert(hh);
					memcpy(q[qe++], e, sizeof(e));
				}
			}
		}
		{
			forn(i, n)
			{
				e[i] = ((f[i] << 1) & ~w[i]) | (f[i] & (w[i] >> 1));
			}
			bool ok = true;
			forn(i, n)
			{
				if ((e[i] | g[i]) != g[i])
				{
					ok = false;
					break;
				}
			}
			if (ok)
			{
				i64 hh = calc_h(e);
				if (hh == fh)
				{
					ans = 1;
/*					forn(i, n)
					{
						forn(j, m)
						{
							cerr << ((e[i] >> j) & 1);
						}
						cerr << endl;
					}
					cerr << "2? " << endl;
					forn(i, n)
					{
						forn(j, m)
						{
							cerr << ((f[i] >> j) & 1);
						}
						cerr << endl;
					}
					cerr << "2? " << endl;*/
					return;
				}
				if (!ss.count(hh))
				{
					ss.insert(hh);
					memcpy(q[qe++], e, sizeof(e));
				}
			}
		}
		{
			forn(i, n)
			{
				e[i] = (i ? ((f[i - 1]) & ~w[i]) : 0) | (f[i] & w[i + 1]);
			}
			bool ok = true;
			forn(i, n)
			{
				if ((e[i] | g[i]) != g[i])
				{
					ok = false;
					break;
				}
			}
			if (ok)
			{
				i64 hh = calc_h(e);
				if (hh == fh)
				{
					ans = 1;
/*					forn(i, n)
					{
						forn(j, m)
						{
							cerr << ((f[i] >> j) & 1);
						}
						cerr << endl;
					}
					cerr << "3? " << endl;*/
					return;
				}
				if (!ss.count(hh))
				{
					ss.insert(hh);
					memcpy(q[qe++], e, sizeof(e));
				}
			}
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
		printf("Case #%d:\n", ii+1);
		fprintf(stderr, "Case #%d:\n", ii+1);

		scanf("%d%d", &n, &m);
		k = 0;
		forn(i, n)
		{
			scanf("%s", a[i]);
			forn(j, m)
			{
				if (isdigit(a[i][j])) k = max(k, a[i][j] - '0' + 1);
			}
		}
		forn(i, k)
		{
			int cnt, ans;
			solve(i, cnt, ans);
			printf("%d: %d %s\n", i, cnt, ans ? "Lucky" : "Unlucky");
		}
		
		fflush(stdout);
	}

	return 0;
}
