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

const int INF = 0x3f3f3f3f;
const int dy[2] = {1, -1};

int n, m, f, qq;
bool a[64][64];
char s[64];
bool b[64];
int d[64][64][64][64];

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	cout << setiosflags(ios::fixed) << setprecision(10);

	scanf("%d", &qq);
	forn(ii, qq)
	{
		scanf("%d%d%d", &n, &m, &f);
		forn(i, n)
		{
			scanf("%s", s);
			forn(j, m)
			{
				a[i][j] = (s[j] == '.');
			}
		}
		memset(d, 0x3f, sizeof(d));
		d[0][0][0][0] = 0;
		int ans = INF;

		forn(x, n-1)
		{
			forn(y, m)
			{
				forn(l, m)
				{
					For(r, l, m-1)
					{
						if (d[x][y][l][r] == INF) continue;

						forn(i, m)
						{
							b[i] = a[x][i];
						}
						For(i, l, r)
						{
							b[i] = true;
						}
					
						int ll = y;
						int rr = y;
						while (ll - 1 >= 0 && b[ll - 1] && !a[x+1][ll - 1]) ll--;
						while (rr + 1 < m && b[rr + 1] && !a[x+1][rr + 1]) rr++;

						if (ll > 0 && b[ll-1] && a[x+1][ll-1])
						{
							int xx = x + 1;
							int zz = 1;
							while (xx + 1 < n && a[xx + 1][ll-1]) xx++, zz++;
							if (zz <= f)
							{
								if (d[xx][ll-1][ll-1][ll-1] > d[x][y][l][r])
								{
									d[xx][ll-1][ll-1][ll-1] = d[x][y][l][r];
								}
							}
						}

						if (rr < m-1 && b[rr+1] && a[x+1][rr+1])
						{
							int xx = x + 1;
							int zz = 1;
							while (xx + 1 < n && a[xx + 1][rr+1]) xx++, zz++;
							if (zz <= f)
							{
								if (d[xx][rr+1][rr+1][rr+1] > d[x][y][l][r])
								{
									d[xx][rr+1][rr+1][rr+1] = d[x][y][l][r];
								}
							}
						}

						For(l1, ll, rr)
						{
							For(r1, l1, rr)
							{
								if (l1 == ll && r1 == rr) continue;
								if (l1 > ll)
								{
									int xx = x + 1;
									int zz = 1;
									while (xx + 1 < n && a[xx + 1][l1]) xx++, zz++;
									if (zz == 1)
									{
										if (d[xx][l1][l1][r1] > d[x][y][l][r] + r1-l1+1)
										{
											d[xx][l1][l1][r1] = d[x][y][l][r] + r1-l1+1;
										}
									}
									else if (zz <= f)
									{
										if (d[xx][l1][l1][l1] > d[x][y][l][r] + r1-l1+1)
										{
											d[xx][l1][l1][l1] = d[x][y][l][r] + r1-l1+1;
										}
									}
								}
								if (r1 < rr)
								{
									int xx = x + 1;
									int zz = 1;
									while (xx + 1 < n && a[xx + 1][r1]) xx++, zz++;
									if (zz == 1)
									{
										if (d[xx][r1][l1][r1] > d[x][y][l][r] + r1-l1+1)
										{
											d[xx][r1][l1][r1] = d[x][y][l][r] + r1-l1+1;
										}
									}
									else if (zz <= f)
									{
										if (d[xx][r1][r1][r1] > d[x][y][l][r] + r1-l1+1)
										{
											d[xx][r1][r1][r1] = d[x][y][l][r] + r1-l1+1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		forn(y, m)
		{
			forn(l, m)
			{
				For(r, l, m-1)
				{
					ans = min(ans, d[n-1][y][l][r]);
				}
			}
		}

		printf("Case #%d: %s", ii+1, (ans == INF) ? "No" : "Yes");
		if (ans == INF) puts("");
		else printf(" %d\n", ans);
	}

	return 0;
}
