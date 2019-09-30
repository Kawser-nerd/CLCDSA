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
int n;
int a[1024];

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

		scanf("%d", &n);
		int s = 0;
		forn(i, n)
		{
			scanf("%d", &a[i]);
			s += a[i];
		}
		forn(i, n)
		{
			ld mi = 0.0;
			ld ma = 1.0;
			forn(tt, 239)
			{
				ld q = (mi + ma) * 0.5;

				ld x = a[i] + q * s;
				ld y = 0.0;
				forn(j, n)
				{
					if (i == j) continue;
					ld tmp = (x - a[j]) * 1.0 / s;
					if (tmp >= 0) y += tmp;
				}
				if (y < 1.0 - q) mi = q;
				else ma = q;
			}
			printf("%0.6lf%c", (double)ma * 100.0, " \n"[i == n - 1]);
		}
		
		fflush(stdout);
	}

	return 0;
}
