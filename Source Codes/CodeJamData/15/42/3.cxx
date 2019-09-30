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
const ld EPS = 1e-13;

// Types
typedef long long i64;
typedef __int128 i128;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < int > VI;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

int qq;
int n;
ld v, x;
ld a[128][2];
int idx[128];

bool check(ld q)
{
	ld mit = 0.0;
	ld mat = 0.0;
	ld vol = 0.0;
	ld temp = 0.0;
	forn(i1, n)
	{
		int i = idx[i1];
		ld vcur = a[i][0] * q;
		ld tcur = a[i][1];
		vcur = min(vcur, v - vol);
		if (vcur <= 0.0) break;
		temp = (vol * temp + vcur * tcur) / (vol + vcur);
		vol += vcur;
	}
	if (vol < v) return false;
	mit = temp;
	vol = 0.0;
	temp = 0.0;
	ford(i1, n)
	{
		int i = idx[i1];
		ld vcur = a[i][0] * q;
		ld tcur = a[i][1];
		vcur = min(vcur, v - vol);
		if (vcur <= 0.0) break;
		temp = (vol * temp + vcur * tcur) / (vol + vcur);
		vol += vcur;
	}
	if (vol < v) return false;
	mat = temp;
	return mit <= x + 1e-14 && x <= mat + 1e-14;
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
		
		double vv, xx;
		scanf("%d%lf%lf", &n, &vv, &xx);
		v = vv;
		x = xx;
		ld mit = 1e10;
		ld mat = -1e10;
		forn(i, n)
		{
			double xx, yy;
			scanf("%lf%lf", &xx, &yy);
			a[i][0] = xx;
			a[i][1] = yy;
			idx[i] = i;
			if (a[i][1] > mat) mat = a[i][1];
			if (a[i][1] < mit) mit = a[i][1];
		}
		sort(idx, idx + n, [&] (const int &l, const int &r) {
			return a[l][1] < a[r][1];
		});
		if (mit > x + EPS || mat < x - EPS)
		{
			puts("IMPOSSIBLE");
		}
		else
		{
			ld mi = 0.0;
			ld ma = 1e9;
			forn(tmp, 222)
			{
				if (ma - mi < 1e-9) break;
				ld q = (mi + ma) * 0.5;
				if (check(q)) ma = q;
				else mi = q;
			}
			printf("%0.6f\n", (double)(mi + ma) / 2.0);
		}
		
		fflush(stdout);
	}

	return 0;
}
