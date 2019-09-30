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

const i64 INF = 0x3f3f3f3f3f3f3f3fLL;
#define x first
#define y second

int qq;
i64 l;
int n;
int a[1024];
int x[1024];
int y[1024];
int d[102400];
//int qb, qe;
//int q[20240000];
priority_queue < PII, vector <PII>, greater <PII> > q;
bool u[102400];

i64 solve(int k)
{
	int m = 0;
	int p = a[k];
	while (!q.empty()) q.pop();
	forn(i, n)
	{
		if (i != k)
		{
			y[m] = a[i] / p;
			x[m++] = a[i] % p;
		}
	}
	clr(u);
	memset(d, 0xff, sizeof(d));
//	qb = qe = 10000020;
	d[0] = 0;
	q.push(mp(d[0], 0));
//	q[qe++] = 0;
	while (!q.empty())
	{
		PII pp = q.top();
		q.pop();
		if (u[pp.y]) continue;
		u[pp.y] = true;
		int t = pp.y;//q[qb++];
		if (t >= p || t < 0)
		{
			cerr << "t = " << t << endl;
			cerr << "p = " << p << endl;
		}
		forn(i, m)
		{
			int r = t + x[i];
			int zz = y[i];
			if (r >= p) r -= p, zz--;
			if (d[r] == -1 || d[r] > pp.x + 1 + zz)
			{
				d[r] = pp.x + 1 + zz;
				q.push(mp(d[r], r));
//				if (zz == 0) q[qe++] = r;
//				else q[--qb] = r;
			}
		}
	}
	int rem = l % p;
	if (d[rem] == -1) return INF;
	return d[rem] + l / p;
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
		scanf("%I64d%d", &l, &n);
		forn(i, n)
		{
			scanf("%d", &a[i]);
		}
		i64 ans = INF;
		forn(i, n)
		{
			ans = min(ans, solve(i));
		}
		if (ans == INF)
		{
			puts("IMPOSSIBLE");
		}
		else
		{
			printf("%I64d\n", ans);
		}
		fflush(stdout);
		cerr << ".";
	}

	return 0;
}
