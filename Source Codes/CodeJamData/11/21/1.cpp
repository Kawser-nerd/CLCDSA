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
char a[128][128];
ld wp[128];
ld owp[128];
ld oowp[128];
int sums[128];
int cnts[128];

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		printf("Case #%d:\n", ii+1);
		fprintf(stderr, "Case #%d:\n", ii+1);

		scanf("%d", &n);
		forn(i, n)
		{
			scanf("%s", a[i]);
		}

		forn(i, n)
		{
			wp[i] = 0.0;
			owp[i] = 0.0;
			oowp[i] = 0.0;
		}
		forn(i, n)
		{
			int cnt = 0;
			int sum = 0;
			forn(j, n)
			{
				if (isdigit(a[i][j]))
				{
					sum += a[i][j] - '0';
					cnt++;
				}
			}
			if (cnt) wp[i] = sum * 1.0 / cnt;
			sums[i] = sum;
			cnts[i] = cnt;
		}

		forn(i, n)
		{
			ld sum = 0.0;
			int cnt = 0;
			forn(j, n)
			{
				if (isdigit(a[i][j]))
				{
					int s = sums[j] - (a[j][i] - '0');
					int c = cnts[j] - 1;
					if (c) sum += s * 1.0 / c;
					cnt++;
				}
			}
			if (cnt) owp[i] = sum / cnt;
		}

		forn(i, n)
		{
			ld sum = 0.0;
			int cnt = 0;
			forn(j, n)
			{
				if (isdigit(a[i][j]))
				{
					sum += owp[j];
					cnt++;
				}
			}
			if (cnt) oowp[i] = sum / cnt;
		}

		forn(i, n)
		{
			printf("%0.10lf\n", (double)(0.25 * wp[i] + 0.5 * owp[i] + 0.25 * oowp[i]));
		}
		
		fflush(stdout);
	}

	return 0;
}
