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

const int MOD = 1000000007;

int qq;
int n, m;
int d[1024][2];

int mypow(int a, int k)
{
	if (!k) return 1;
	int ans = mypow(a, k / 2);
	ans = ans * (i64)ans % MOD;
	if (k & 1) ans = ans * (i64)a % MOD;
	return ans;
}

inline void add(int &a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
}

int calc(int n, int m)
{
	clr(d);
	d[0][0] = 1;
	d[0][1] = 1;

	forn(i, n)
	{
		add(d[i + 2][0], d[i][1]);
		add(d[i + 1][1], d[i][0]);
		if (m % 3 == 0) add(d[i + 2][1], d[i][0] * 3LL % MOD);
		if (m % 6 == 0) add(d[i + 2][1], d[i][0] * 6LL % MOD);
		if (m % 4 == 0) add(d[i + 3][1], d[i][0] * 4LL % MOD);
	}
	
	int ans = (d[n][0] + d[n][1]) % MOD;
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
		
		scanf("%d%d", &n, &m);
		int ans = 0;
		forn(i, m)
		{
			int k = __gcd(i, m);
			int z = calc(n, k);
			add(ans, z);
		}
		ans = ans * (i64)mypow(m, MOD - 2) % MOD;
		printf("%d\n", ans);
		
		fflush(stdout);
	}

	return 0;
}
