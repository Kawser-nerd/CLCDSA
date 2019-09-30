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
int n, xx, yy;
int r[1024];
int ans[1024][2];
int ind[1024];
int xs[10240];

bool cmp(int p1, int p2)
{
	return r[p1] > r[p2];
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		printf("Case #%d:", ii+1);
		fprintf(stderr, "Case #%d:\n", ii+1);

		scanf("%d%d%d", &n, &xx, &yy);
		forn(i, n)
		{
			scanf("%d", &r[i]);
			ind[i] = i;
//			cerr << r[i] << endl;
		}
		stable_sort(ind, ind + n, cmp);

		int ss = -1000000000;
		forn(i1, n)
		{
			int i = ind[i1];
			int mi = ss;
			int ma = yy - 1;
			while (mi < ma)
			{
				int q = mi + ((i64)ma - mi) / 2;
				int k = 0;
				forn(j1, i1)
				{
					int j = ind[j1];
					if (ans[j][1] + r[j] <= q) continue;
					int x1 = ans[j][0] - r[j];
					int x2 = ans[j][0] + r[j];
					xs[k++] = x1;
					xs[k++] = x2;
				}
				sort(xs, xs + k);
				xs[k++] = -r[i];
				if (xs[k - 1] > xs[0]) xs[k - 1] = xs[0];
				xs[k++] = xx + r[i];
				if (xs[k - 1] < xs[k - 3]) xs[k - 1] = xs[k - 3];
				sort(xs, xs + k);
				bool bb = false;
				forn(j, k - 1)
				{
					if (!(j & 1) && xs[j + 1] - xs[j] >= r[i] * 2)
					{
						bb = true;
						break;
					}
				}
				if (bb) ma = q;
				else mi = q + 1;
			}
			int q = mi;
			int k = 0;
			forn(j1, i1)
			{
				int j = ind[j1];
				if (ans[j][1] + r[j] <= q) continue;
				int x1 = ans[j][0] - r[j];
				int x2 = ans[j][0] + r[j];
				xs[k++] = x1;
				xs[k++] = x2;
			}
			sort(xs, xs + k);
			xs[k++] = -r[i];
			if (xs[k - 1] > xs[0]) xs[k - 1] = xs[0];
			xs[k++] = xx + r[i];
			if (xs[k - 1] < xs[k - 3]) xs[k - 1] = xs[k - 3];
			sort(xs, xs + k);
			bool bb = false;
			forn(j, k - 1)
			{
				if (!(j & 1) && xs[j + 1] - xs[j] >= r[i] * 2)
				{
					ans[i][0] = xs[j] + r[i];
					ans[i][1] = q + r[i];
//					cerr << "q = " << q << endl;
					if (ans[i][1] < 0) ans[i][1] = 0;
					if (ss < ans[i][1] - r[i]) ss = ans[i][1] - r[i];
					bb = true;
					break;
				}
			}
//			cerr << ss << endl;
			if (!bb)
			{
				cerr << "Botwa !!!   i = " << i << endl;
			}
		}

		forn(i, n)
		{
			printf(" %d %d", ans[i][0], ans[i][1]);
		}
		puts("");
		
		fflush(stdout);
	}

	return 0;
}
