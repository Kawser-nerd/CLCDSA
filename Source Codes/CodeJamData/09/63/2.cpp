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

const int MOD = 10007;

int qq, n, m;
char a[12][12];
int d[2][456976];
bool cor[456976];
int p26[12];
int t[12];

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cout << setiosflags(ios::fixed) << setprecision(10);

	p26[0] = 1;
	For(i, 1, 4)
	{
		p26[i] = p26[i-1] * 26;
	}
	clr(cor);
	forn(i, 26)
	{
		forn(j, i+1)
		{
			forn(k, j+1)
			{
				forn(l, k+1)
				{
					cor[l * p26[0] + k * p26[1] + j * p26[2] + i * p26[3]] = true;
				}
			}
		}
	}

	scanf("%d", &qq);
	forn(ii, qq)
	{
		scanf("%d%d", &n, &m);
		forn(i, n)
		{
			scanf("%s", a[i]);
		}
		clr(d);
		d[0][0] = 1;
		int z = 0;

		forn(i, n)
		{
			ford(j, m)
			{
				clr(d[1 - z]);
				forn(mask, p26[m])
				{
					if (!d[z][mask]) continue;
					int x = mask;
					forn(l, m)
					{
						t[l] = x % 26;
						x /= 26;
					}
					int mi = t[j];
					int ma = 25;
					if (j > 0)
					{
						mi >?= t[j-1];
					}
					if (j < m-1)
					{
						ma <?= t[j+1];
					}
					For(c, mi, ma)
					{
						if (a[i][j] != '.' && (a[i][j] - 'a') != c) continue;
						int newmask = 0;
						ford(l, m)
						{
							if (l == j)
							{
								newmask = newmask * 26 + c;
							}
							else
							{
								newmask = newmask * 26 + t[l];
							}
						}
						d[1 - z][newmask] += d[z][mask];
						if (d[1 - z][newmask] >= MOD) d[1 - z][newmask] -= MOD;
					}
				}
				z = 1 - z;
			}
		}

		int ans = 0;

		forn(i, p26[m])
		{
			ans += d[z][i];
			if (ans >= MOD) ans -= MOD;
		}

		printf("Case #%d: %d\n", ii+1, ans);
	}

	return 0;
}
