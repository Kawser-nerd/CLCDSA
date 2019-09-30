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
int n, l;
int a[10240];
int b[10240];
int d[10240];

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
		a[0] = 0;
		forn(i, n)
		{
			scanf("%d%d", &a[i + 1], &b[i + 1]);
		}
		scanf("%d", &l);
		n++;
		a[n] = l;
		b[n] = l;
		b[0] = a[1];

		clr(d);
		bool ans = false;

		d[0] = a[1];
		forn(i, n)
		{
			if (!d[i]) continue;
			For(j, i+1, n)
			{
				if (a[j] > d[i]) break;
				int z = min(b[j], a[j] - a[i]);
//				if (b[j])
				d[j] = max(d[j], a[j] + z);
				if (d[j] >= l)
				{
					ans = true;
					break;
				}
			}
			if (ans) break;
		}
/*		forn(i, n + 1)
		{
			cerr << a[i] << " ";
		}
		cerr << endl;
		forn(i, n + 1)
		{
			cerr << b[i] << " ";
		}
		cerr << endl;
		forn(i, n + 1)
		{
			cerr << d[i] << " ";
		}
		cerr << endl;
*/
		puts(ans ? "YES" : "NO");
		
		fflush(stdout);
	}

	return 0;
}
