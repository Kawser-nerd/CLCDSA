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
#define For(i, st, en) for(__typeof(en) i=(st); i<=(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(__typeof(n) i=0; i<(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

typedef double ld;

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

struct tp{int x,y;};

int qq, n;
tp a[1024000];
tp b[1024000];
tp c[1024000];
ld ans;

inline i64 dist2(tp p1, tp p2)
{
	return sqr((i64)p1.x - p2.x) + sqr((i64)p1.y - p2.y);
}

inline ld dist(tp p1, tp p2)
{
	return sqrt(sqr((i64)p1.x - p2.x) + sqr((i64)p1.y - p2.y));
}

bool cmp(tp p1, tp p2)
{
	return p1.y < p2.y || p1.y == p2.y && p1.x < p2.x;
}

bool cmpx(tp p1, tp p2)
{
	return p1.x < p2.x || p1.x == p2.x && p1.y < p2.y;
}

void calc(int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int qb = 0;
	int qe = 0;

	memcpy(b + p, a + p, (r - p + 1) * sizeof(*a));
	sort(b + p, b + q + 1, cmpx);
	sort(b + q + 1, b + r + 1, cmpx);

	int yy = a[q+1].y;
	while (i <= q || j <= r)
	{
		if (i > q || j <= r && b[j].x < b[i].x)
		{
			if (b[j].y < yy + ans * 0.5) c[qe++] = b[j];
			j++;
		}
		else
		{
			if (b[i].y > yy - ans * 0.5) c[qe++] = b[i];
			i++;
		}
		while (qb < qe && c[qe-1].x - c[qb].x > ans * 0.5)
		{
			qb++;
		}
		if (qe - qb > 10)
		{
			cerr << qe - qb << endl;
		}

		For(ii, qb, qe-2)
		{
			For(jj, ii+1, qe-2)
			{
				int k = qe - 1;
				ans <?= dist(c[ii], c[jj]) + dist(c[ii], c[k]) + dist(c[jj], c[k]);
			}
		}
	}
}

void solve(int p, int r)
{
	int q = (p + r) / 2;
	if (r - p > 10)
	{
		solve(p, q);
		solve(q+1, r);
		calc(p, q, r);
	}
	else
	{
		For(i, p, r)
		{
			For(j, i+1, r)
			{
				For(k, j+1, r)
				{
					ans <?= dist(a[i], a[j]) + dist(a[i], a[k]) + dist(a[j], a[k]);
				}
			}
		}
	}
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		scanf("%d", &n);
		forn(i, n)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			a[i].x = x;
			a[i].y = y;
		}

		ans = 1e+30;
		sort(a, a+n, cmp);

		solve(0, n-1);

		printf("Case #%d: %0.10lf\n", ii+1, ans);
	}

	return 0;
}
