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

int qq, n, m;
string s;
MSI d;
int a[1024];
bool b[1024][1024];
int l[1024];
int r[1024];
int col[1024];
bool u[1024];
bool u2[1024];

bool dfs(int k, int c)
{
	u[k] = true;
	col[k] = c;

	forn(i, n)
	{
		if (b[k][i])
		{
			if (!u[i])
			{
				if (dfs(i, 1 - c)) return true;
			}
			else
			{
				if (col[i] != 1 - c) return true;
			}
		}
	}

	return false;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	cin >> qq;
	forn(ii, qq)
	{
		d.clear();
		m = 0;
		cin >> n;
		memset(l, 0xff, sizeof(l));
		int ans = 0;
		int sum = 0;
		forn(i, n * 2)
		{
			cin >> s;
			if (d.find(s) == d.end()) d[s] = m++;
			a[i] = d[s];
			if (l[a[i]] == -1)
			{
				l[a[i]] = i;
				sum++;
				ans >?= sum;
			}
			else
			{
				r[a[i]] = i;
				sum--;
			}
		}

		clr(b);
		forn(i, n)
		{
			forn(j, i)
			{
				if (min(r[i], r[j]) < max(l[i], l[j])) continue;
				if (l[i] > l[j] && r[i] < r[j]) continue;
				if (l[i] < l[j] && r[i] > r[j]) continue;
				b[i][j] = b[j][i] = true;
			}
		}

		memset(col, 0xff, sizeof(col));
		clr(u);
		forn(i, n)
		{
			if (!u[i])
			{
				memcpy(u2, u, sizeof(u));
				if (dfs(i, 0))
				{
					ans = -1;
					break;
				}
//				memcpy(u, u2, sizeof(u));
				int x = 0, y = 0;
				int xm = 0, ym = 0;
				forn(j, n * 2)
				{
					if (!u2[a[j]] && u[a[j]])
					{
						if (col[a[j]])
						{
							if (l[a[j]] == j) x++;
							else x--;
							xm >?= x;
						}
						else
						{
							if (l[a[j]] == j) y++;
							else y--;
							ym >?= y;
						}
					}
				}
//				cerr << xm << " " << ym << endl;
				ans >?= xm + ym;
			}
		}

		if (ans != -1)
		{
			
		}

		printf("Case #%d: %d\n", ii+1, ans);
	}

	return 0;
}
