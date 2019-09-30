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
const ld EPS = 1e-5;

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

struct tp{ld x,y;};

int qq, n;
tp p[102];
ld r[102];
bool b[102];
ld aa[10240];
ld css[10240];
ld sns[10240];

inline ld dist(tp p1, tp p2)
{
	return sqrt(sqr(p1.x-p2.x) + sqr(p1.y-p2.y));
}

ld solve(tp &pp)
{
	pp.x = 0.0;
	pp.y = 0.0;

	int k = 0;
	for(ld a1 = 0.0; a1 <= 2.0 * PI; a1 += 3e-3)
	{
		css[k] = cos(a1);
		sns[k] = sin(a1);
		aa[k] = a1;
		k++;
	}

	for(ld e = 1e+3; e > 1e-8; e /= 1.3)
	{
		ld mi = 1e+100;
		ld ra = -1.0;
		forn(j, k)
		{
			ld cs = css[j];
			ld sn = sns[j];
			tp pn;
			pn.x = pp.x + e * cs;
			pn.y = pp.y + e * sn;

			ld ma = 0.0;
			forn(i, n)
			{
				if (b[i]) continue;

				ma = max(ma, dist(pn, p[i]) + r[i]);
			}

			if (ma < mi)
			{
				mi = ma;
				ra = aa[j];
			}
		}

		ld cs = cos(ra);
		ld sn = sin(ra);
		pp.x = pp.x + e * cs;
		pp.y = pp.y + e * sn;
	}

	ld ma = 0.0;
	forn(i, n)
	{
		if (b[i]) continue;

		ma = max(ma, dist(pp, p[i]) + r[i]);
	}
	return ma;
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);
	cerr << setiosflags(ios::fixed) << setprecision(5);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		scanf("%d", &n);
		forn(i, n)
		{
			double x, y, rr;
			scanf("%lf%lf%lf", &x, &y, &rr);
			p[i].x = x;
			p[i].y = y;
			r[i] = rr;
		}

		ld ans = 1e+10;

		clr(b);
		b[0] = true;
		ld rr = r[0];
		tp pp;
		rr = max(rr, solve(pp));
		ans = min(ans, rr);

		For(i, 1, n-1)
		{
			forn(k, n)
			{
				b[k] = true;
			}
			b[i] = b[0] = false;
			tp p1;
			ld r1 = solve(p1);
			forn(k, n)
			{
				if (dist(p[k], p1) + r[k] <= r1 + 1e-4)
				{
					b[k] = false;
				}
			}
/*			if (i == 3)
			{
				cerr << n << endl;
				cerr << p1.x << " " << p1.y << endl;
				cerr << r1 << endl;
				forn(k, n)
				{
					cerr << b[k] << " ";
				}
				cerr << endl;
				forn(k, n)
				{
					cerr << dist(p[k], p1) + r[k] << " ";
				}
				cerr << endl;
			}*/
			forn(k, n)
			{
				b[k] = !b[k];
			}
			ld r2 = solve(p1);
			r1 = max(r1, r2);
			ans = min(ans, r1);
		}

		For(i, 1, n-1)
		{
			For(j, 1, i-1)
			{
				forn(k, n)
				{
					b[k] = true;
				}
				b[i] = b[j] = b[0] = false;
				tp p1;
				ld r1 = solve(p1);
				forn(k, n)
				{
					if (dist(p[k], p1) + r[k] <= r1 + 1e-4)
					{
						b[k] = false;
					}
				}
				forn(k, n)
				{
					b[k] = !b[k];
				}
				ld r2 = solve(p1);
				r1 = max(r1, r2);
				ans = min(ans, r1);
			}
		}

		printf("Case #%d: %0.6lf\n", ii+1, (double)ans);
	}

	return 0;
}
