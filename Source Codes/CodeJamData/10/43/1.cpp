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

const int INF = 0x3f3f3f3f;

int qq;
int n;
int a[10240][4];
bool g[1024][1024];
bool u[1024];

bool check(int i, int j)
{
	if (a[i][0] > a[j][2] + 1) return false;
	if (a[i][1] > a[j][3] + 1) return false;
	if (a[j][0] > a[i][2] + 1) return false;
	if (a[j][1] > a[i][3] + 1) return false;
	if (a[i][0] <= a[j][2] && a[j][0] <= a[i][2]) return true;
	if (a[i][1] <= a[j][3] && a[j][1] <= a[i][3]) return true;
	if (a[i][0] == a[j][2] + 1 && a[i][3] + 1 == a[j][1]) return true;
	if (a[j][0] == a[i][2] + 1 && a[j][3] + 1 == a[i][1]) return true;
	return false;
}

void dfs(int k, int &xy, int &xma, int &yma)
{
	u[k] = true;
	xma = max(xma, a[k][2]);
	yma = max(yma, a[k][3]);
	xy = min(xy, a[k][0] + a[k][1]);
	forn(i, n)
	{
		if (u[i] || !g[k][i]) continue;
		dfs(i, xy, xma, yma);
	}
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	srand(45724);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		printf("Case #%d: ", ii+1);
		scanf("%d", &n);
		forn(i, n)
		{
			forn(j, 4)
			{
				scanf("%d", &a[i][j]);
			}
			swap(a[i][0], a[i][1]);
			swap(a[i][2], a[i][3]);
		}
		clr(g);
		forn(i, n)
		{
			forn(j, i)
			{
				if (check(i, j))
				{
					g[i][j] = g[j][i] = true;
				}
			}
			g[i][i] = true;
		}
		int ans = 0;
		clr(u);
		forn(i, n)
		{
			if (!u[i])
			{
				int xy = INF;
				int xma = -INF;
				int yma = -INF;
				dfs(i, xy, xma, yma);
				ans = max(ans, xma + yma - xy + 1);
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}
