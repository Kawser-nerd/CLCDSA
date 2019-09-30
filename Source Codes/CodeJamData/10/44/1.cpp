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
const ld EPS = 1e-7;

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

struct tp{ld x,y; tp(){x=0.0; y=0.0;}; };
struct tl{ld a,b,c;};

int qq;
int n, m;
tp a[10240];
tp b[10240];
ld r[10240];
int ind[10240];
ld xs[1024000];

inline ld dist(tp p1, tp p2)
{
	return sqrt(sqr(p1.x-p2.x) + sqr(p1.y-p2.y));
}

inline ld dist2(tp p1, tp p2)
{
	return (sqr(p1.x-p2.x) + sqr(p1.y-p2.y));
}

tl findline(tp p1, tp p2)
{
	tl l;
	l.a = p2.y - p1.y;
	l.b = p1.x - p2.x;
	l.c = -l.a * p1.x - l.b * p1.y;
	return l;
}

tl findperp(tl l, tp p)
{
	tl l1;
	l1.a = l.b;
	l1.b = -l.a;
	l1.c = -l1.a * p.x - l1.b * p.y;
	return l1;
}

ld distline(tl l, tp p)
{
	return (l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}

void norm(tl &l)
{
	ld d = sqrt(l.a * l.a + l.b * l.b);
	l.a /= d;
	l.b /= d;
	l.c /= d;
}

bool onseg(tp p, tp p1, tp p2)
{
	tl l = findline(p1, p2);
	if (fabs(distline(l, p)) > EPS) return false;
	return fabs(dist(p1, p2) - dist(p, p1) - dist(p, p2)) < EPS;
}

ld vp(tp p, tp p1, tp p2)
{
	p1.x -= p.x;
	p1.y -= p.y;
	p2.x -= p.x;
	p2.y -= p.y;
	return p1.x * p2.y - p1.y * p2.x;
}

ld sp(tp p, tp p1, tp p2)
{
	p1.x -= p.x;
	p1.y -= p.y;
	p2.x -= p.x;
	p2.y -= p.y;
	return p1.x * p2.x + p1.y * p2.y;
}

ld distseg(tp p, tp p1, tp p2)
{
	if (sp(p1, p2, p) < 0.0) return dist(p, p1);
	if (sp(p2, p1, p) < 0.0) return dist(p, p2);
	return fabs(vp(p, p1, p2)) / dist(p1, p2);
}

bool findpoint(tl l1, tl l2, tp& p)
{
	ld d = l1.a * l2.b - l1.b * l2.a;
	if (fabs(d) < EPS) return false;
	p.x = (l1.b * l2.c - l1.c * l2.b) / d;
	p.y = (l1.c * l2.a - l1.a * l2.c) / d;
	return true;
}

int findcircline(tp c, ld r, tl l, tp *ps)
{
	ld h = fabs(distline(l, c));
	if (h > r + EPS) return 0;
	tl l1 = findperp(l, c);
	tp p;
	ld d = sqrt(l.a * l.a + l.b * l.b);
	h = sqrt(fabs(r * r - h * h));
	findpoint(l, l1, p);
	ps[0].x = p.x + l1.a * h / d;
	ps[0].y = p.y + l1.b * h / d;
	ps[1].x = p.x - l1.a * h / d;
	ps[1].y = p.y - l1.b * h / d;
	return (dist(ps[0], ps[1]) > EPS) + 1;
}

int findcirccirc(tp c1, ld r1, tp c2, ld r2, tp *ps)
{
	tl l;
	l.a = 2.0 * (c2.x - c1.x);
	l.b = 2.0 * (c2.y - c1.y);
	l.c = c1.x * c1.x + c1.y * c1.y - c2.x * c2.x - c2.y * c2.y + r2 * r2 - r1 * r1;
	norm(l);
	return findcircline(c1, r1, l, ps);
}

tp shift(tp p1, tp p2, ld d)
{
	tp p;
	ld h = dist(p1, p2);
	p.x = p1.x + (p2.x - p1.x) / h * d;
	p.y = p1.y + (p2.y - p1.y) / h * d;
	return p;
}

bool cmp(int p1, int p2)
{
	return r[p1] < r[p2];
}

ld calc2(tp a1, ld r1, tp a2, ld r2, tp pp, ld ang1, ld ang2)
{
	ld ans = r1 * r1 * PI;
/*	cerr << a1.x << " " << a1.y << endl;
	cerr << r1 << endl;
	cerr << a2.x << " " << a2.y << endl;
	cerr << r2 << endl;
	cerr << pp.x << " " << pp.y << endl;
	cerr << ang1 << " " << ang2 << endl;
	cerr << endl;
*/
	ans -= ang1 * r1 * r1;
	ans += ang2 * r2 * r2;
	ans -= fabs(vp(a2, a1, pp));

	return ans;
}

ld solve(tp p)
{
	ld ans = 0.0;
	forn(i, n)
	{
		r[i] = dist(a[i], p);
		ind[i] = i;
	}
	sort(ind, ind+n, cmp);

/*	ld xmi = 1e+10, ymi = 1e+10, xma = -1e+10, yma = -1e+10;
	forn(i, n)
	{
		xma = max(xma, a[i].x - r[i]);
		xmi = min(xmi, a[i].x + r[i]);
		yma = max(yma, a[i].y - r[i]);
		ymi = min(ymi, a[i].y + r[i]);
	}
	if (xma >= xmi || yma >= ymi) return 0.0;
*/
	if (n == 2)
	{
		tp ps[4];
		int t = findcirccirc(a[ind[0]], r[ind[0]], a[ind[1]], r[ind[1]], ps);
		if (t < 2) cerr << "t = " << t << endl;
//		if (t == 1) ps[1] = ps[0];
		ld d = dist(a[0], a[1]);
		if (d + r[ind[0]] <= r[ind[1]] + EPS)
		{
			return PI * sqr(r[ind[0]]);
		}
		if (d >= r[ind[0]] + r[ind[1]] - EPS)
		{
			return 0.0;
		}
		ld a1 = fabs(atan2(vp(a[ind[0]], a[ind[1]], ps[0]), sp(a[ind[0]], a[ind[1]], ps[0])));
		ld a2 = fabs(atan2(vp(a[ind[1]], a[ind[0]], ps[0]), sp(a[ind[1]], a[ind[0]], ps[0])));
		if (d >= max(r[ind[0]], r[ind[1]]))
		{
			ans = 0.0;
			ans += a1 * sqr(r[ind[0]]) - fabs(vp(a[ind[0]], ps[0], ps[1])) * 0.5;
			ans += a2 * sqr(r[ind[1]]) - fabs(vp(a[ind[1]], ps[0], ps[1])) * 0.5;
		}
		else
		{
			a1 = PI - fabs(atan2(vp(a[ind[0]], a[ind[1]], ps[0]), sp(a[ind[0]], a[ind[1]], ps[0])));
			a2 = fabs(atan2(vp(a[ind[1]], a[ind[0]], ps[0]), sp(a[ind[1]], a[ind[0]], ps[0])));
			ans = calc2(a[ind[0]], r[ind[0]], a[ind[1]], r[ind[1]], ps[0], a1, a2);
		}
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
		scanf("%d%d", &n, &m);
		forn(i, n)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			a[i].x = x;
			a[i].y = y;
		}
		forn(i, m)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			b[i].x = x;
			b[i].y = y;
		}

		forn(i, m)
		{
			double ans = solve(b[i]);
			if (i) putchar(' ');
			printf("%0.7lf", ans);
		}
		puts("");
	}

	return 0;
}
