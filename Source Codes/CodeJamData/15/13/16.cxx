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

struct tp{int x, y;};

int qq;
int n;
tp a[10240];
tp b[10240];

int vp(tp p1, tp p2)
{
	i64 d = p1.x * (i64)p2.y - p1.y * (i64)p2.x;
	if (d > 0) return 1;
	if (d < 0) return -1;
	return 0;
}

bool operator < (tp p1, tp p2)
{
	bool up1 = p1.y > 0 || (p1.y == 0 && p1.x > 0);
	bool up2 = p2.y > 0 || (p2.y == 0 && p2.x > 0);
	if (up1 != up2) return up1;
	return vp(p1, p2) > 0;
}

int solve(int n)
{
	int ans = n;
	sort(b, b + n);
	forn(i, n)
	{
		b[i + n] = b[i];
	}
	int j = 0;
	forn(i, n)
	{
		if (j < i) j = i;
		while (j < i + n && vp(b[i], b[j]) >= 0) j++;
		int cur = n - (j - i);
		if (cur < ans) ans = cur;
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
		printf("Case #%d:\n", ii+1);
		fprintf(stderr, "Case #%d:\n", ii+1);
		
		scanf("%d", &n);
		forn(i, n)
		{
			scanf("%d%d", &a[i].x, &a[i].y);
		}
		forn(i, n)
		{
			int m = 0;
			forn(j, n)
			{
				if (a[i].x == a[j].x && a[i].y == a[j].y) continue;
				b[m].x = a[j].x - a[i].x;
				b[m].y = a[j].y - a[i].y;
				m++;
			}
			int ans = solve(m);
			printf("%d\n", ans);
		}
		
		fflush(stdout);
	}

	return 0;
}
