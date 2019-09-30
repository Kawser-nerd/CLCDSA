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
typedef long long i64;
typedef __int128 i128;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

int qq;
int n;
int a[10240];

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
		forn(i, n)
		{
			scanf("%d", &a[i]);
		}
		int ans1 = 0;
		forn(i, n - 1)
		{
			if (a[i + 1] < a[i]) ans1 += a[i] - a[i + 1];
		}
		i64 ans2 = 1e18;
		For(s, 0, 10000)
		{
			bool ok = true;
			i64 cur = 0;
			forn(i, n - 1)
			{
				int z = min(a[i], s);
				cur += z;
				int x = a[i] - z;
				if (x > a[i + 1])
				{
					ok = false;
					break;
				}
			}
			if (ok && cur < ans2) ans2 = cur;
		}
		printf("%d %lld\n", ans1, ans2);
		
		fflush(stdout);
	}

	return 0;
}
