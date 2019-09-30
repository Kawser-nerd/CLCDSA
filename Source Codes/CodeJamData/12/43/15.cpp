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

struct tp{i64 x,y;};
struct tl{i64 a,b,c;};

int qq;
int n;
int a[10240];
int ans[10240];

tl findline(tp p1, tp p2)
{
	tl l;
	l.a = p2.y - p1.y;
	l.b = p1.x - p2.x;
	l.c = -l.a * p1.x - l.b * p1.y;
	return l;
}

bool solve(int p, int r, tl l)
{
	if (r == p) return true;
	int q = -1;
	For(i, p, r - 1)
	{
		if (a[i] == r)
		{
			q = i;
			break;
		}
	}
	if (q < 0) return false;
	For(i, p, r - 1)
	{
		if (a[i] > r)
		{
			return false;
		}
	}
	int x = q;
	int y = (-l.a * x - l.c) / l.b;
	while (l.a * x + l.b * y + l.c <= 0) y--;
	ans[q] = y;
	tp p1, p2;
	p1.x = q;
	p1.y = ans[q];
	p2.x = r;
	p2.y = ans[r];
	tl ll = findline(p1, p2);
	return solve(p, q, ll) && solve(q + 1, r, ll);
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

		scanf("%d", &n);
		forn(i, n - 1)
		{
			scanf("%d", &a[i]);
			a[i]--;
		}

		tl l;
		tp p1, p2;
		p1.x = 0;
		p1.y = 200000000;
		p2.x = n - 1;
		p2.y = 200000000;
		l = findline(p1, p2);
		ans[0] = p1.y;
		ans[n-1] = p2.y;
		if (solve(0, n-1, l))
		{
			forn(i, n)
			{
				printf(" %d", ans[i]);
			}
			puts("");
		}
		else
		{
			puts(" Impossible");
		}
		
		fflush(stdout);
	}

	return 0;
}
