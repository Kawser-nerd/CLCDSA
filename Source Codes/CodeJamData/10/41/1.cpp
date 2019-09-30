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
int n;
char a[128][128];
char s[1024];

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	gets(s);
	sscanf(s, "%d", &qq);
	forn(ii, qq)
	{
		printf("Case #%d: ", ii+1);
		gets(s);
		sscanf(s, "%d", &n);
		clr(a);
		forn(i, n*2-1)
		{
			gets(a[i]);
		}
		forn(i, n * 2 - 1)
		{
			forn(j, n * 2 - 1)
			{
				if (!a[i][j]) a[i][j] = ' ';
//				fprintf(stderr, "%c", a[i][j]);
			}
//			fprintf(stderr, "\n");
		}
		int xmi = n, ymi = n;
		forn(i1, n)
		{
			for(int di = -1; di <= 1; di += 2)
			{
				int dx = n - 1 + i1 * di;
				bool ok = true;
				forn(i, n)
				{
					if (dx + i >= 2 * n - 1 || dx - i < 0) break;
					forn(j, n * 2 - 1)
					{
						if (a[dx + i][j] == ' ' || a[dx - i][j] == ' ') continue;
						if (a[dx + i][j] != a[dx - i][j])
						{
							ok = false;
							break;
						}
					}
				}
				if (ok)
				{
					xmi = i1;
					break;
				}
			}
			if (xmi < n) break;
		}
		forn(j1, n)
		{
			for(int dj = -1; dj <= 1; dj += 2)
			{
				int dy = n - 1 + j1 * dj;
				bool ok = true;
				forn(j, n)
				{
					if (dy + j >= 2 * n - 1 || dy - j < 0) break;
					forn(i, n * 2 - 1)
					{
						if (a[i][dy + j] == ' ' || a[i][dy - j] == ' ') continue;
						if (a[i][dy + j] != a[i][dy - j])
						{
							ok = false;
							break;
						}
					}
					if (!ok) break;
				}
				if (ok)
				{
					ymi = j1;
					break;
				}
			}
			if (ymi < n) break;
		}
		cerr << "xmi = " << xmi << " ymi = " << ymi << endl;

//		int ans = max(xmi, ymi);
		int ans = xmi + ymi;
		ans = (n + ans) * (n + ans) - n * n;
		printf("%d\n", ans);
	}

	return 0;
}
