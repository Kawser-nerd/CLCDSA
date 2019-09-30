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

int qq;
int n, k;
VI a[2024];
int a1[2024];
int a2[2024];
int c[2024];
bool g[2024][2024];
bool u[2024][2024];
int q[4024000][2];
int qb, qe;
int cols[2024];
bool uc[2024];

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

		scanf("%d%d", &n, &k);
		forn(i, k)
		{
			scanf("%d", &a1[i]);
		}
		forn(i, k)
		{
			scanf("%d", &a2[i]);
		}
		clr(g);
		forn(i, k)
		{
			a[a1[i]-1].pb(a2[i]-1);
			a[a2[i]-1].pb(a1[i]-1);
			g[a1[i]-1][a2[i]-1] = true;
			g[a2[i]-1][a1[i]-1] = true;
		}
		forn(i, n)
		{
			int j = (i + 1) % n;
			g[i][j] = g[j][i] = true;
		}

		int ans = n + 1;
		forn(i, n)
		{
			sort(a[i].begin(), a[i].end());
		}

		clr(u);
		forn(i, n)
		{
			forn(j, n)
			{
				if (u[i][j]) continue;
				if (!g[i][j]) continue;
				int x = i;
				int y = j;
				int cnt = 0;
				while (!u[x][y])
				{
					u[x][y] = true;
//					cerr << x << " " << y << "  ";
					cnt++;

					int xn = y;
					int yn = x-1;
					if (yn < 0) yn += n;

					while (!g[xn][yn])
					{
						yn--;
						if (yn < 0) yn += n;
					}

					x = xn;
					y = yn;
				}
//				cerr << endl;
				ans = min(ans, cnt);
			}
		}

		clr(u);
		qb = qe = 0;
		q[qe][0] = 0;
		q[qe][1] = 1;
		qe++;
		memset(c, 0xff, sizeof(c));
		c[0] = 0;
		c[1] = 1;
		forn(i, n)
		{
			u[(i+1)%n][i] = true;
		}

		while (qb != qe)
		{
			int v1 = q[qb][0];
			int v2 = q[qb][1];
			qb++;
			
			int x = v1;
			int y = v2;
			memset(uc, 0, ans * sizeof(uc[0]));
			cols[0] = c[v1];
			cols[1] = c[v2];
			uc[cols[0]] = true;
			uc[cols[1]] = true;
			int t = 0;
			For(i, 2, ans-1)
			{
				while (uc[t]) t++;
				cols[i] = t;
				uc[t] = true;
			}
			int z = 0;
			while (!u[x][y])
			{
				c[x] = cols[z++];
				if (z >= ans) z -= 2;
				u[x][y] = true;
				if (!u[y][x])
				{
					q[qe][0] = y;
					q[qe][1] = x;
					qe++;
				}

				int xn = y;
				int yn = x-1;
				if (yn < 0) yn += n;

				while (!g[xn][yn])
				{
					yn--;
					if (yn < 0) yn += n;
				}

				x = xn;
				y = yn;
			}
		}

		forn(i, n)
		{
			a[i].clear();
		}

		printf("%d\n", ans);
		forn(i, n)
		{
			if (i) putchar(' ');
			printf("%d", c[i] + 1);
		}
		puts("");
		
		fflush(stdout);
	}

	return 0;
}
