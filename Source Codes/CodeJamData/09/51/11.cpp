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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

int qq, n, h, w, m, k, t;
char b[16][16];
map < i64, int > d;
set < i64 > z;
bool u[12][12];
bool f[12][12];

i64 xy2z(int *x, int *y)
{
	int r[6];
	forn(i, k)
	{
		r[i] = x[i] * 12 + y[i];
	}
	sort(r, r+k);
	i64 z = 0;
	forn(i, k)
	{
		z = z * 144 + r[i];
	}
	return z;
}

void dfs(int x, int y)
{
	u[x][y] = true;
	forn(l, 4)
	{
		int xn = x + dx[l];
		int yn = y + dy[l];
		if (xn < 0 || xn >= h || yn < 0 || yn >= w || !f[xn][yn] || u[xn][yn]) continue;
		dfs(xn, yn);
	}
}

bool check(int *x, int *y)
{
	clr(f);
	forn(i, k)
	{
		f[x[i]][y[i]] = true;
	}
	forn(i, h)
	{
		forn(j, w)
		{
			if (f[i][j])
			{
				clr(u);
				dfs(i, j);
				forn(i1, h)
				{
					forn(j1, w)
					{
						if (f[i1][j1] && !u[i1][j1]) return false;
					}
				}
				return true;
			}
		}
	}
	return false;
}

void move2(int *xs, int *ys, int dd, int i)
{
	bool a[12][12];
	clr(a);
	forn(l, k)
	{
		a[xs[l]][ys[l]] = true;
	}
	int xx[6];
	int yy[6];
	forn(i, k)
	{
		forn(l, 4)
		{
			int xn = xs[i] + dx[l];
			int yn = ys[i] + dy[l];
			int xn2 = xs[i] - dx[l];
			int yn2 = ys[i] - dy[l];
			if (xn < 0 || xn >= h || yn < 0 || yn >= w || b[xn][yn] == '#' || a[xn][yn]) continue;
			if (xn2 < 0 || xn2 >= h || yn2 < 0 || yn2 >= w || b[xn2][yn2] == '#' || a[xn2][yn2]) continue;
			memcpy(xx, xs, sizeof(xx));
			memcpy(yy, ys, sizeof(yy));
			xx[i] = xn;
			yy[i] = yn;
			if (check(xx, yy))
			{
				i64 t = xy2z(xx, yy);
				if (d.find(t) == d.end()) d[t] = 0x3f3f3f3f;
				if (d[t] > dd + 2)
				{
					d[t] = dd + 2;
				}
			}
		}
	}
}

void move1(i64 v, int dd)
{
	bool a[12][12];
	clr(a);
	int xs[6];
	int ys[6];
	ford(l, k)
	{
		int t = v % 144;
		xs[l] = t / 12;
		ys[l] = t % 12;
		a[xs[l]][ys[l]] = true;
		v /= 144;
	}
	int xx[6];
	int yy[6];
	forn(i, k)
	{
		forn(l, 4)
		{
			int xn = xs[i] + dx[l];
			int yn = ys[i] + dy[l];
			int xn2 = xs[i] - dx[l];
			int yn2 = ys[i] - dy[l];
			if (xn < 0 || xn >= h || yn < 0 || yn >= w || b[xn][yn] == '#' || a[xn][yn]) continue;
			if (xn2 < 0 || xn2 >= h || yn2 < 0 || yn2 >= w || b[xn2][yn2] == '#' || a[xn2][yn2]) continue;
			memcpy(xx, xs, sizeof(xs));
			memcpy(yy, ys, sizeof(ys));
			xx[i] = xn;
			yy[i] = yn;
			i64 t = xy2z(xx, yy);
			if (check(xx, yy))
			{
				if (d.find(t) == d.end()) d[t] = 0x3f3f3f3f;
				if (d[t] > dd + 1)
				{
					d[t] = dd + 1;
				}
			}
			else
			{
				move2(xx, yy, dd, i);
			}
		}
	}
}

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
		scanf("%d%d", &h, &w);
		forn(i, h)
		{
			scanf("%s", b[i]);
		}
		k = 0;
		i64 st = 0, en = 0;
		forn(i, h)
		{
			forn(j, w)
			{
				if (b[i][j] == 'o' || b[i][j] == 'w')
				{
					k++;
					st = st * 144 + i * 12 + j;
				}
				if (b[i][j] == 'x' || b[i][j] == 'w')
				{
					en = en * 144 + i * 12 + j;
				}
			}
		}
		d.clear();
		z.clear();
		d[st] = 0;

		for(;;)
		{
			int mi = 1000000000;
			i64 v = -1;
			fori(it, d)
			{
				i64 p = it->first;
				if (z.find(p) == z.end() && it->second < mi)
				{
					mi = it->second;
					v = it->first;
				}
			}
			if (v == -1) break;
			z.insert(v);

			move1(v, mi);
		}
		if (d.find(en) == d.end()) d[en] = -1;
		
		printf("Case #%d: %d\n", ii+1, d[en]);
	}

	return 0;
}
