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

int qq;
int r, k, n;
int a[10240];
int b[10240];
i64 c[10240];

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		scanf("%d%d%d", &r, &k, &n);
		forn(i, n)
		{
			scanf("%d", &a[i]);
		}

		memset(c, 0xff, sizeof(c));
		int x = 0;
		i64 w = 0;
		bool fl = false;
		while (r > 0)
		{
			i64 t = 0;
			int x0 = x;
			int ttt = 0;
			while (ttt < n && t + a[x] <= k)
			{
				t += a[x];
				x++;
				if (x == n) x = 0;
				ttt++;
			}
			w += t;
			if (!fl)
			{
				if (c[x0] == -1)
				{
					c[x0] = w;
					b[x0] = r;
					r--;
				}
				else
				{
					int per = b[x0] - r;
					r--;
					i64 cnt = r / per;
					r %= per;
					w += (w - c[x0]) * cnt;
					fl = true;
				}
			}
			else
			{
				r--;
			}
		}

		i64 ans = w;
		printf("Case #%d: %I64d\n", ii+1, ans);
	}

	return 0;
}
