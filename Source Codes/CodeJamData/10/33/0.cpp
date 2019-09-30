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

int qq;
int n, m;
bool a[520][520];
bool d[520][520][520];
int t[520][520];
char s[1024];
int c[1024][2];

void tadd(int x, int y)
{
	x++;
	y++;
	for(int i = x; i <= 512; i += i & -i)
	{
		for(int j = y; j <= 512; j += j & -j)
		{
			t[i][j]++;
		}
	}
}

int tsum(int x, int y)
{
	x++;
	y++;
	int ans = 0;
	for(int i = x; i; i -= i & -i)
	{
		for(int j = y; j; j -= j & -j)
		{
			ans += t[i][j];
		}
	}
	return ans;
}

bool check(int x1, int y1, int x2, int y2)
{
	if (x1 > x2) swap(x1, x2);
	if (y1 > y2) swap(y1, y2);
	int s = tsum(x2, y2) - tsum(x1-1, y2) - tsum(x2, y1-1) + tsum(x1-1, y1-1);
	return !s;
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

		clr(t);
		scanf("%d%d", &n, &m);
		forn(i, n)
		{
			scanf("%s", s);
			forn(j, m/4)
			{
				int x = isdigit(s[j]) ? s[j] - '0' : s[j] - 'A' + 10;
				forn(l, 4)
				{
					a[i][j * 4 + 3 - l] = x & (1 << l);
				}
			}
		}

		clr(d);
		forn(i, n)
		{
			forn(j, m)
			{
				d[1][i][j] = true;
			}
		}
		forn(i, n-1)
		{
			forn(j, m-1)
			{
				d[2][i][j] = (a[i][j] == a[i+1][j+1]) && (a[i][j] != a[i][j+1]) && (a[i][j] != a[i+1][j]);
			}
		}
		int ma = min(n, m);
		For(t, 3, ma)
		{
			forn(i, n-t+1)
			{
				forn(j, m-t+1)
				{
					d[t][i][j] = d[t-1][i][j] && d[t-1][i+1][j] && d[t-1][i][j+1] && d[t-1][i+1][j+1];
				}
			}
		}

		int ans = 0;

		Ford(t, ma, 1)
		{
			c[ans][0] = c[ans][1] = 0;
			forn(i, n)
			{
				forn(j, m)
				{
					if (d[t][i][j])
					{
						if (check(i, j, i+t-1, j+t-1))
						{
							c[ans][0] = t;
							c[ans][1]++;
							For(x, i, i+t-1)
							{
								For(y, j, j+t-1)
								{
									tadd(x, y);
								}
							}
						}
					}
				}
			}
			if (c[ans][0]) ans++;
		}
		cerr << ii+1 << endl << flush;

		printf("%d\n", ans);
		forn(i, ans)
		{
			printf("%d %d\n", c[i][0], c[i][1]);
		}
	}

	return 0;
}
