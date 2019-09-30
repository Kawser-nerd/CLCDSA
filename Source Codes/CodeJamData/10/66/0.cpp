#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cmath>

#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%Ld"
#endif

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define zero(a) memset(a, 0, sizeof(a))
#define all(a) (a).begin(), (a).end()

#define IS(a, i) (((a) >> (i)) & 1)

typedef long long ll;
typedef vector <int> vi;

const int maxn = 10;

int res;
int cc, mark[maxn][maxn], num[2], bad, good, cnt;
int w, h, u[maxn][maxn], col[maxn][maxn];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int is[2];
int tmp[maxn];

void dfs( int x, int y )
{
  int deg = 0;
  cnt++, mark[y][x] = cc;
  forn(k, 4)
  {
    int x1 = x + dx[k], y1 = y + dy[k];
	if (0 <= x1 && x1 < w && 0 <= y1 && y1 < h)
		if (u[y1][x1] && col[y1][x1] == col[y][x])
		{
		  deg++;
		  if (mark[y1][x1] != cc)
			dfs(x1, y1);
		}
		else if (!u[y1][x1])
		{
			good = 1;
			tmp[x1] = cc;
		}
  }
  if (deg > 2)
    bad = 1;
  if (deg == 1)
    is[col[y][x]] = 1;
}

void go( int x, int y )
{
  if (x >= w)
    x = 0, y++;

  num[0] = num[1] = 0;
  forn(i, h)
    forn(j, w)
	  if (u[i][j])
	    num[col[i][j]]++;
		
  cc++;
  is[0] = is[1] = 0;
  bad = 0;
  memset(mark, 0, sizeof(mark));
  memset(tmp, 0, sizeof(tmp));
  forn(i, h)
    forn(j, w)
	  if (u[i][j] && mark[i][j] != cc)
	  {
	    good = 0, cnt = 0;
	    dfs(j, i);
		if (cnt != num[col[i][j]])
		  if (!good)
		    return;
		if (bad)
		  return;
	  }
/*
  if (x == 0)
  {
    int *f = col[y - 1];
    forn(b, w)
	  forn(a, b)
	    if (!f[a] && !f[b] && tmp[a] != tmp[b])
			forab(d, a, w - 1)
			  forab(c, 0, b)
				if (f[c] && f[d] && tmp[c] != tmp[d])
					return;
  }
*/	  
  if (y >= h)
  {
    res += (is[0] && is[1]);
    return;
  }
  u[y][x] = 1;
  col[y][x] = 0, go(x + 1, y);
  col[y][x] = 1, go(x + 1, y);
  u[y][x] = 0;
}

int main() 
{
  int tn;
  scanf("%d", &tn);
  
  forab (tt, 1, tn)
  {
    scanf("%d%d", &h, &w);
	res = 0;
	go(0, 0);
	printf("%d %d %d\n", w, h, res);
	fprintf(stderr, "%d %d %d\n", w, h, res);
  }
  return 0;
}
