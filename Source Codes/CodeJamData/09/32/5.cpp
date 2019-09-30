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

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-9;

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

struct tp{ld x,y,z;};

int qq, n;
tp a[1024];
tp v[1024];
tp an[1024];
tp p0;

inline ld dist(tp p1, tp p2)
{
	return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y)+sqr(p1.z-p2.z));
}

inline ld dist2(tp p1, tp p2)
{
	return (sqr(p1.x-p2.x)+sqr(p1.y-p2.y)+sqr(p1.z-p2.z));
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	p0.x = p0.y = p0.z = 0.0;
	scanf("%d", &qq);
	forn(ii, qq)
	{
		scanf("%d", &n);
		tp p, pn, vv;
		p.x = p.y = p.z = 0.0;
		pn.x = pn.y = pn.z = 0.0;
		forn(i, n)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			a[i].x = x;
			a[i].y = y;
			a[i].z = z;
			scanf("%d%d%d", &x, &y, &z);
			v[i].x = x;
			v[i].y = y;
			v[i].z = z;
			an[i].x = a[i].x + v[i].x;
			an[i].y = a[i].y + v[i].y;
			an[i].z = a[i].z + v[i].z;
			p.x += a[i].x;
			p.y += a[i].y;
			p.z += a[i].z;
			pn.x += an[i].x;
			pn.y += an[i].y;
			pn.z += an[i].z;
		}
		p.x /= n;
		p.y /= n;
		p.z /= n;
		pn.x /= n;
		pn.y /= n;
		pn.z /= n;
		vv.x = pn.x - p.x;
		vv.y = pn.y - p.y;
		vv.z = pn.z - p.z;

		ld ans, anst;

		if (dist(p0, vv) < EPS)
		{
			ans = dist(p0, p);
			anst = 0.0;
		}
		else
		{
			ld mi = 0.0;
			ld ma = 1e+9;
			forn(tt, 277)
			{
				ld q1 = mi + (ma - mi) / 3.0;
				ld q2 = mi + (ma - mi) * 2.0 / 3.0;

				tp p1, p2;
				p1.x = p.x + vv.x * q1;
				p1.y = p.y + vv.y * q1;
				p1.z = p.z + vv.z * q1;

				p2.x = p.x + vv.x * q2;
				p2.y = p.y + vv.y * q2;
				p2.z = p.z + vv.z * q2;

				ld d1 = dist2(p0, p1);
				ld d2 = dist2(p0, p2);

				if (d1 < d2)
				{
					ma = q2;
				}
				else
				{
					mi = q1;
				}
			}

			anst = mi;
			tp p1;
			p1.x = p.x + vv.x * anst;
			p1.y = p.y + vv.y * anst;
			p1.z = p.z + vv.z * anst;

			ans = dist(p0, p1);
		}

		printf("Case #%d: %0.10lf %0.10lf\n", ii+1, (double)ans, (double)anst);
	}

	return 0;
}
