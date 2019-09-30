#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

#ifdef WIN32
#define INT64 "%I64d"
#define UINT64 "%I64u"
#else
#define INT64 "%lld"
#define UINT64 "%llu"
#endif

#ifdef DEBUG
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#else
#define eprintf(...) assert (true)
#endif

const int MaxN = 103, MaxD = 4, MaxC = 0x3F3F3F3F, NA = -1;
const int dx [MaxD] = {-1,  0, +1,  0},
          dy [MaxD] = { 0, -1,  0, +1};

int f [MaxN] [MaxN];
int c [MaxN] [MaxN];
int d [MaxN] [MaxN];
int h, n, m;

int main (void)
{
 int test, tests;
 int e, i, j;

 scanf (" %d ", &tests);
 for (test = 1; test <= tests; test++)
 {
  scanf (" %d %d %d", &h, &n, &m);
  memset (c, 0, sizeof (c));
  for (i = 1; i <= n; i++)
   for (j = 1; j <= m; j++)
    scanf (" %d", &c[i][j]);
  memset (f, 0, sizeof (f));
  for (i = 1; i <= n; i++)
   for (j = 1; j <= m; j++)
    scanf (" %d", &f[i][j]);
  memset (d, MaxC, sizeof (d));
  d[1][1] = 0;
  priority_queue <pair <int, pair <int, int> >,
   vector <pair <int, pair <int, int> > >,
   greater <pair <int, pair <int, int> > > > q;
  q.push (make_pair (d[1][1], make_pair (1, 1)));
  eprintf ("start\n");
  while (!q.empty ())
  {
   pair <int, pair <int, int> > cur;
   int x, y, z;

   cur = q.top ();
   q.pop ();
   z = cur.first;
   x = cur.second.first;
   y = cur.second.second;
   if (d[x][y] != z)
    continue;
/*
   if (x == n && y == m)
    break;
*/

   for (e = 0; e < MaxD; e++)
   {
    int ch, cx, cy, cz;
    cx = x + dx[e];
    cy = y + dy[e];
    if (f[x][y] + 50 > c[cx][cy])
     continue;
    if (f[cx][cy] + 50 > c[cx][cy])
     continue;
    if (f[cx][cy] + 50 > c[x][y])
     continue;
    ch = min (h, c[cx][cy] - 50);
    ch = min (ch, h - z);
    cz = h - ch;
    ch = max (ch, 0);
    if (cz > 0)
    {
     if (ch - f[x][y] >= 20)
      cz += 10;
     else
      cz += 100;
    }
    if (d[cx][cy] > cz)
    {
     d[cx][cy] = cz;
     eprintf ("%d %d: %d\n", cx, cy, cz);
     q.push (make_pair (cz, make_pair (cx, cy)));
    }
   }

//   d[x][y] = -MaxC;
  }

  printf ("Case #%d: %.1lf\n", test, d[n][m] * 0.1);
 }

 return 0;
}
