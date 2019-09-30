#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <sstream>

using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)

typedef long long int64;
typedef pair <int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const int64 inf64 = ((int64)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";

template <class T> T sqr (T x) {return x * x;}

int n, m, f, d[50][50][50][50][2];
bool g[50][50];

int go (int x, int y, int l, int r, int tp)
{
	if (l > r)
		return inf;
	if (x == n-1)
		return 0;
	if (d[x][y][l][r][tp] != -1)
		return d[x][y][l][r][tp];
       	int p, w;
       	int res = inf;
	if (tp == 0)
	{
		pii t = mp (l, r);
		while (l > 0 && g[x][l-1])
			l --;
		while (r < m-1 && g[x][r+1])
			r ++;
		for (int i = y; i <= r; i ++)
			if (g[x+1][i])
			{
				p = i;
				w = x + 1;	
				while (w < n-1 && g[w+1][p])
					w ++;
				if (w - x <= f)
					res = min (res, go (w, p, p, p, 0));
				r = i-1;
				break;
			}
		for (int i = y; i >= l; i --)
			if (g[x+1][i])
			{
				p = i;
				w = x + 1;	
				while (w < n-1 && g[w+1][p])
					w ++;
				if (w - x <= f)
					res = min (res, go (w, p, p, p, 0));
				l = i+1;
				break;
			}
		return d[x][y][t.fs][t.sc][tp] = min (res, go (x, y, l, r, 1));
	}
	res = min (go (x, l, l, r-1, 1), go (x, r, l+1, r, 1));
	int ds = r - l;
	if (ds > 0)
	{
		p = x+1;
		while (p < n-1 && g[p+1][l+1])
			p ++;
		if (p > x + 1 && p-x <= f)
			res = min (res, ds + go (p, l+1, l+1, l+1, 0));
		else
		if (p == x + 1)
			res = min (res, ds + go (p, l+1, l+1, r, 0));
		p = x + 1;
		while (p < n-1 && g[p+1][r-1])
			p ++;
		if (p > x + 1 && p-x <= f)
			res = min (res, ds + go (p, r-1, r-1, r-1, 0));
		else
		if (p == x + 1)
			res = min (res, ds + go (p, r-1, l, r-1, 0));
	}
	return d[x][y][l][r][tp] = res;
}

int main ()
{
        int tt;
        scanf ("%d", &tt);
        forn (ii, tt)
        {
        	printf ("Case #%d: ", ii+1);
        	scanf ("%d%d%d", &n, &m, &f);
        	forn (i, n)
        		forn (j, m)
        		{
        			char ch;
        			scanf (" %c", &ch);
        			if (ch == '.')
        				g[i][j] = 1;
        			else
        				g[i][j] = 0;	
        		}
        	seta (d, 255);
        	int res = go (0, 0, 0, 0, 0);
        	if (res >= inf)
        		printf ("No\n");
        	else
        		printf ("Yes %d\n", res);
        }

	return 0;
}
