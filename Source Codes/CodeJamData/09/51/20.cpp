#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef vector <pii> vpii;

const int maxn = 15;

int h, w;
char s[maxn][maxn];

const int maxq = (int)1e5;

map <vpii, int> d;

int qst = 0, qen = 0, qsize = 0;
vpii end, q[maxq]; 

void cor( vpii &v )
{
  sort(v.begin(), v.end());
}

int cc, n, u[5];

#define X first
#define Y second

void dfs( int v, vpii &p )
{
  u[v] = 1, cc++;
  forn(i, n)
    if (!u[i] && abs(p[i].X - p[v].X) + abs(p[i].Y - p[v].Y) <= 1)
      dfs(i, p);
}

int isConnected( vpii &v )
{
  memset(u, 0, sizeof(u));
  n = sz(v);
  cc = 0;
  dfs(0, v);
  return cc == n;
}

int isFree( int x, int y, vpii &v )
{
  if (!(0 <= x && x < w && 0 <= y && y < h))
    return 0;
  if (s[y][x] == '#')
    return 0;
  int n = sz(v);
  forn(i, n)
    if (v[i] == mp(x, y))
      return 0;
  return 1;
}

void add( vpii &a, int x )
{
  cor(a);
  if (d.count(a))
    return;
  d[a] = x;
  assert(++qsize < maxq);
  q[qen++] = a;
  if (qen == maxq)
    qen = 0;
}

int main()
{
  int tn;
  scanf("%d", &tn);
  for (int tt = 1; tt <= tn; tt++)
  {
    fprintf(stderr, "%d\n", tt);
    scanf("%d%d", &h, &w);
    forn(i, h)
      scanf("%s", s[i]);

    qst = qen = 0;
    d.clear();
    vpii a, b;
    forn(i, h)
      forn(j, w)
      {
        if (s[i][j] == 'o' || s[i][j] == 'w')
          a.pb(mp(j, i));
        if (s[i][j] == 'x' || s[i][j] == 'w')
          b.pb(mp(j, i));
      }
    cor(a), cor(b);
    assert(sz(a) == sz(b));
    assert(sz(a) <= 5);

//    puts("!");

    end = b;
    d[a] = 0;
    q[qen++] = a, qsize++;
    while (qst != qen && !d.count(end))
    {
      a = q[qst++], qsize--;
      if (qst == maxq)
        qst = 0;

/*
      printf("a = ");
      forn(i, sz(a))
        printf("(%d,%d) ", a[i].X, a[i].Y);
      puts("");
*/

      int is1 = isConnected(a);
      int dx[] = {1, 0};
      int dy[] = {0, 1};
      int n = sz(a);
      int curd = d[a];

      forn(i, n)
        forn(j, 2)
        {
//          printf("i=%d j=%d\n", i, j);

          int x = a[i].X;
          int y = a[i].Y;
          if (isFree(x + dx[j], y + dy[j], a) && isFree(x - dx[j], y - dy[j], a))
            for (int t = -1; t <= 1; t += 2)
            {
              forn(k, n)
                b[k] = a[k];
              b[i] = mp(x + t * dx[j], y + t * dy[j]);
              if (!isConnected(b) && !is1)
                continue;
              add(b, curd + 1);
            }
        }
    }

    printf("Case #%d: %d\n", tt, d.count(end) ? d[end] : -1);
  }
  return 0;
}
