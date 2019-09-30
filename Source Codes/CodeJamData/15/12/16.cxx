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
int n, k;
int a[10240];

i64 f(i64 t)
{
	if (t < 0) return 0;
	i64 ans = 0;
	forn(i, n)
	{
		ans += t / a[i] + 1;
	}
	return ans;
}

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
		forn(i, n)
		{
			scanf("%d", &a[i]);
		}
		i64 mi = 0;
		i64 ma = 1e15;
		while (mi < ma)
		{
			i64 q = (mi + ma) / 2;
			if (f(q) < k) mi = q + 1;
			else ma = q;
		}
		int r = k - f(mi - 1);
		int ans = -1;
		forn(i, n)
		{
			if (mi % a[i] == 0)
			{
				if (!--r)
				{
					ans = i + 1;
					break;
				}
			}
		}
		cerr << mi << endl;
		printf("%d\n", ans);
		
		fflush(stdout);
	}

	return 0;
}
