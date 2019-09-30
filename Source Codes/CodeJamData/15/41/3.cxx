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

char const *w = "^>v<";
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int qq;
int n, m;
char a[128][128];

bool check(int x, int y, int dir)
{
	for(;;)
	{
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= n || y < 0 || y >= m) return false;
		if (strchr(w, a[x][y])) return true;
	}
	return false;
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
		
		scanf("%d%d", &n, &m);
		forn(i, n)
		{
			scanf("%s", a[i]);
		}
		int ans = 0;
		forn(i, n)
		{
			forn(j, m)
			{
				if (char *t = strchr(w, a[i][j]))
				{
					int dir = t - w;
					if (check(i, j, dir)) continue;
					bool ok = false;
					forn(l, 4)
					{
						if (l == dir) continue;
						if (check(i, j, l))
						{
							ok = true;
							break;
						}
					}
					if (ok) ans++;
					else
					{
						ans = -1;
						goto l1;
					}
				}
			}
		}
		l1:;
		if (ans >= 0) printf("%d\n", ans);
		else puts("IMPOSSIBLE");
		
		fflush(stdout);
	}

	return 0;
}
