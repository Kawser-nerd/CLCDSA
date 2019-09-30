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
int d, n;
int x[1024];

#define MAXP 1000008
int b[((MAXP+1) >> 5) + 10];
int c[MAXP + 8];

void gen_primes()
{
	memset(b, 0, sizeof(b));
	int sq = (int)(sqrt(MAXP) + 2);
	for(int j = 4; j <= MAXP; j += 2)
	{
		b[j >> 5] |= 1 << j;
		c[j] = 2;
	}
	for(int i=3; i<=sq; i+=2)
	{
		if (b[i >> 5] & (1 << i)) continue;
		int j = i * i;
		while (j <= MAXP)
		{
			b[j >> 5] |= 1 << j;
			c[j] = i;
			j += i * 2;
		}
	}
	b[1 >> 5] |= 1 << 1;
	for(int i=2; i<=MAXP; i++)
	{
		if (!(b[i >> 5] & (1 << i))) c[i] = i;
	}
}

int mypow(int a, int k, int p)
{
	if (!a) return 0;
	int ans = 1;
	int j = 1 << 30;
	while (j)
	{
		ans = (i64)ans * ans % p;
		if (j & k) ans = (i64)ans * a % p;
		j >>= 1;
	}
	return ans;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	gen_primes();

	scanf("%d", &qq);
	forn(ii, qq)
	{
		printf("Case #%d: ", ii+1);
		scanf("%d%d", &d, &n);
		forn(i, n)
		{
			scanf("%d", &x[i]);
		}
		if (n <= 1)
		{
			puts("I don't know.");
			continue;
		}
		if (n == 2)
		{
			if (x[0] != x[1])
			{
				puts("I don't know.");
				continue;
			}
		}
		int ma = 1;
		forn(i, d)
		{
			ma *= 10;
		}
		int cnt = 0;
		int ans = -1;
		For(p, 2, ma)
		{
			if (b[p >> 5] & (1 << p)) continue;
			bool ok = true;
			forn(i, n)
			{
				if (x[i] >= p) ok = false;
			}
			if (!ok) continue;
			int a = (i64)(x[2] - x[1]) * mypow(x[1] - x[0], p-2, p) % p;
			if (a < 0) a += p;
//			int s = x[0];//(i64)(x[1] - x[0]) * mypow(a, p-2, p) % p;
			int b = (i64)(x[1] - (i64)a * x[0]) % p;
			if (b < 0) b += p;

			if (n == 2)
			{
				cnt = 1;
				ans = x[0];
				break;
			}

			int z = x[0];
			bool bb = true;
/*			if (ii == 0)
			{
				cerr << "p = " << p << endl;
				cerr << "a = " << a << endl;
				cerr << "b = " << b << endl;
			}*/
			For(t, 1, n-1)
			{
				z = ((i64)z * a + b) % p;
				if (z != x[t]) bb = false;
			}
			if (bb)
			{
/*				cerr << "p = " << p << endl;
				cerr << "a = " << a << endl;
				cerr << "b = " << b << endl;*/
			
				z = ((i64)z * a + b) % p;
				if (cnt >= 1)
				{
					if (ans != z)
					{
						cnt++;
					}
				}
				else
				{
					cnt++;
					ans = z;
				}
			}
		}
		cerr << cnt << endl;

		if (cnt > 1)
		{
			puts("I don't know.");
		}
		else
		{
			printf("%d\n", ans);
		}
	}

	return 0;
}
