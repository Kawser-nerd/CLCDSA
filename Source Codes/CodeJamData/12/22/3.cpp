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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int qq;
int n, m, h;
int f[128][128];
int c[128][128];
int qb, qe;
int q[128 * 128][2];
bool u[128][128];
int d[128][128];

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		printf("Case #%d: ", ii+1);
		fprintf(stderr, "Case #%d:\n", ii+1);

		scanf("%d%d%d", &h, &n, &m);
		forn(i, n)
		{
			forn(j, m)
			{
				scanf("%d", &c[i][j]);
			}
		}
		forn(i, n)
		{
			forn(j, m)
			{
				scanf("%d", &f[i][j]);
			}
		}
		qb = qe = 0;

		clr(u);
		u[0][0] = true;
		q[qe][0] = 0;
		q[qe][1] = 0;
		qe++;
		while (qb != qe)
		{
			int x = q[qb][0];
			int y = q[qb][1];
			qb++;
			forn(l, 4)
			{
				int xn = x + dx[l];
				int yn = y + dy[l];
				if (xn < 0 || xn >= n || yn < 0 || yn >= m || u[xn][yn]) continue;
				int ll = max(f[x][y], f[xn][yn]);
				ll = max(ll, h);
				int rr = min(c[x][y], c[xn][yn]);
				if (rr - ll >= 50)
				{
					u[xn][yn] = true;
					q[qe][0] = xn;
					q[qe][1] = yn;
					qe++;
				}
			}
		}

		memset(d, 0x3f, sizeof(d));
		forn(i, n)
		{
			forn(j, m)
			{
				if (u[i][j])
				{
					d[i][j] = 0;
				}
			}
		}

		clr(u);
		forn(ii, n * m)
		{
			int mi = 0x3f3f3f3f;
			int x = -1, y = -1;

			forn(i, n)
			{
				forn(j, m)
				{
					if (!u[i][j] && d[i][j] < mi)
					{
						mi = d[i][j];
						x = i;
						y = j;
					}
				}
			}
			if (x == -1) break;
			u[x][y] = true;
			int dd = h - d[x][y];
			forn(l, 4)
			{
				int xn = x + dx[l];
				int yn = y + dy[l];
				if (xn < 0 || xn >= n || yn < 0 || yn >= m || u[xn][yn]) continue;
				
				int ll = max(f[x][y], f[xn][yn]);
				int rr = min(c[x][y], c[xn][yn]);
				if (rr - ll >= 50)
				{
					int tt = 0;
					if (rr - dd < 50)
					{
						tt = dd - (rr - 50);
					}
					int v = ((dd - tt) - f[x][y] >= 20) ? 10 : 100;
//					cerr << x << " " << y << " " << xn << " " << yn << " " << dd << " " << tt << " " << ll << " " << rr << " " << v << endl;
//					cerr << tt << endl;
					if (d[xn][yn] > d[x][y] + tt + v)
					{
						d[xn][yn] = d[x][y] + tt + v;
					}
				}
			}
		}

		printf("%0.6lf\n", d[n-1][m-1] * 0.1);
		
		fflush(stdout);
	}

	return 0;
}
