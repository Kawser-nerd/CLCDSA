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
int n, k, d;
int a[1024000];

bool check(i64 q)
{
	i64 last = (i64)(-1e+18);
	forn(i, n)
	{
		i64 z = a[i] - q;
		i64 y = last + d;
		if (z < y) z = y;
		if (a[i] + q < z) return false;
		last = z;
	}
	return true;
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

		scanf("%d%d", &k, &d);
		d *= 2;
		n = 0;
		forn(i, k)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			forn(j, y)
			{
				a[n++] = x * 2;
			}
		}
		sort(a, a+n);

		i64 mi = 0;
		i64 ma = (i64)(1e+13);

		while (ma > mi)
		{
			i64 q = (mi + ma) / 2;
			if (check(q)) ma = q;
			else mi = q + 1;
		}
		cerr << mi << endl;

		cout << mi / 2 << "." << 5 * (mi % 2) << "000000" << endl;

		fflush(stdout);
	}

	return 0;
}
