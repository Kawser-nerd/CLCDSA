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
int a[1 << 22];
int n;
int t[1 << 23];
int z;

void tadd(int x, int k)
{
	x += z;
	while (x)
	{
		t[x] += k;
		x >>= 1;
	}
}

int tmax()
{
	int x = 1;
	forn(i, 22)
	{
		if (t[x * 2 + 1]) x = x * 2 + 1;
		else x *= 2;
	}
	return x - z;
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
		int m = 1500000;
		clr(a);
		clr(t);
		scanf("%d", &n);
		forn(i, n)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			x += m;
			a[x] += y;
		}
		z = 1 << 22;
		i64 ans = 0;

		For(i, 1, 3000000)
		{
			while (a[i] > 1)
			{
				int x = tmax();
				int r = i - x;
				int k = min(a[i]-1, r);
				if (k == r)
				{
					a[i] -= k;
					a[i+1] += k;
					ans += (i64)(k+1) * k / 2;
					tadd(x, -1);
					a[i]--;
					a[x] = 1;
				}
				else //if (k < r)
				{
					a[x] = 1;
					a[x+k] = 0;
					tadd(x, -1);
					tadd(x+k, 1);
					a[i] -= k;
					a[i+1] += k;
					ans += (i64)(r + r-k+1) * (k) / 2;
				}
			}
			if (!a[i]) tadd(i, 1);
		}

		cerr << ".";
		printf("%I64d\n", ans);
	}

	return 0;
}
