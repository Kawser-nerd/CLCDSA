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
int a[1024];
int b[1024];
int s[128][128];
int d[128][128];

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
		scanf("%d%d", &m, &n);
		a[0] = 0;
		forn(i, n)
		{
			scanf("%d", &a[i+1]);
		}
		a[n+1] = m+1;
		forn(i, n+1)
		{
			b[i] = a[i+1] - a[i] - 1;
		}

		memset(d, 0x3f, sizeof(d));
		clr(s);
		forn(i, n+1)
		{
			s[i][i] = b[i];
			For(j, i+1, n)
			{
				s[i][j] = s[i][j-1] + b[j];
				if (j > i+1) s[i][j]++;
			}
		}

		forn(i, n+1)
		{
			d[i][i] = 0;
		}

		ford(i, n)
		{
			For(j, i+1, n)
			{
				For(l, i+1, j)
				{
					d[i][j] <?= d[i][l-1] + d[l][j] + s[i][j];
				}
			}
		}

		int ans = d[0][n];
		printf("Case #%d: %d\n", ii+1, ans);
	}

	return 0;
}
