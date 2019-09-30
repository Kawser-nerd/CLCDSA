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

const int MaxN = 6012, MaxL = MaxN * MaxN, MaxC = 0x3F3F3F3F, NA = -1;
const int MedD = 3, MaxD = MedD << 1;
const int dx [MaxD] = {-1, -1,  0, +1, +1,  0},
          dy [MaxD] = {-1,  0, +1, +1,  0, -1};
const char NAME [8] [32] = {"none", "bridge", "fork", "bridge-fork",
 "ring", "bridge-ring", "fork-ring", "bridge-fork-ring"};
enum {BRIDGE = 1, FORK = 2, RING = 4};

int px [MaxN] [MaxN], py [MaxN] [MaxN];
int c [MaxN] [MaxN];
int d [MaxN] [MaxN];
int e [MaxN] [MaxN];
int k, l, m, res, s;

void root (int & x, int & y)
{
 if (px[x][y] == x && py[x][y] == y)
  return;
 int cx = x, cy = y;
 x = px[cx][cy];
 y = py[cx][cy];
 root (x, y);
 px[cx][cy] = x;
 py[cx][cy] = y;
}

void unite (int x1, int y1, int x2, int y2)
{
 root (x1, y1);
 root (x2, y2);
 if (x1 == x2 && y1 == y2)
  return;
 px[x2][y2] = x1;
 py[x2][y2] = y1;
 c[x1][y1] |= c[x2][y2];
 e[x1][y1] |= e[x2][y2];
}

int go (int x, int y, int b, int tx, int ty, int tb, bool first)
{
 int e, k, nx, ny, res;

 eprintf ("go     %d %d %d\n", x, y, b);

 e = b;
 k = 0;
 do
 {
  if (!first && x == tx && y == ty && e == tb)
   return k;
  nx = x + dx[e];
  ny = y + dy[e];
  if (d[nx][ny] == 0)
   return NA;
  if (d[nx][ny] == 1)
   break;
  e = (e + 1) % MaxD;
  k++;
 }
 while (e != b);

 if (first)
  if (e == b)
   return MaxD;

 res = go (nx, ny, (e + 4) % MaxD, tx, ty, tb, false);
 if (res == NA)
  return NA;
 eprintf ("res + k - 2 = %d\n", res + k - 2);
 return res + k - 2;
}

void put (int x, int y)
{
 int b, nx, ny;

 eprintf ("put    %d %d\n", x, y);
 assert (d[x][y] == 1);
 d[x][y] = 2;

 for (b = 0; b < MaxD; b++)
 {
  nx = x + dx[b];
  ny = y + dy[b];
  if (d[nx][ny] == 1)
   if (go (nx, ny, (b + MedD) % MaxD, 
           nx, ny, (b + MedD) % MaxD, true) == MaxD)
   {
    eprintf ("!\n");
    res |= RING;
    k = l;
   }
  if (d[nx][ny] == 2)
   unite (x, y, nx, ny);
 }

 if (__builtin_popcount (c[x][y]) >= 2)
 {
  res |= BRIDGE;
  k = l;
 }

 if (__builtin_popcount (e[x][y]) >= 3)
 {
  res |= FORK;
  k = l;
 }
}

int main (void)
{
 int test, tests;
 int i, j;

 scanf (" %d ", &tests);
 for (test = 1; test <= tests; test++)
 {
  scanf (" %d %d", &s, &m);

  memset (c, 0, sizeof (c));
  memset (d, 0, sizeof (d));
  memset (e, 0, sizeof (e));

  for (i = 1; i <= s + s - 1; i++)
   for (j = 1; j <= s + s - 1; j++)
    if (abs (i - j) < s)
    {
     eprintf ("cell  %d %d\n", i, j);
     d[i][j]  = 1;
     px[i][j] = i;
     py[i][j] = j;
     if (i == 1)
      e[i][j] |= 1 << 0;
     if (j - i == s - 1)
      e[i][j] |= 1 << 1;
     if (j == s + s - 1)
      e[i][j] |= 1 << 2;
     if (i == s + s - 1)
      e[i][j] |= 1 << 3;
     if (i - j == s - 1)
      e[i][j] |= 1 << 4;
     if (j == 1)
      e[i][j] |= 1 << 5;
    }

  e[1][1] = 0;
  c[1][1] |= 1 << 0;
  e[1][s] = 0;
  c[1][s] |= 1 << 1;
  e[s][s + s - 1] = 0;
  c[s][s + s - 1] |= 1 << 2;
  e[s + s - 1][s + s - 1] = 0;
  c[s + s - 1][s + s - 1] |= 1 << 3;
  e[s + s - 1][s] = 0;
  c[s + s - 1][s] |= 1 << 4;
  e[s][1] = 0;
  c[s][1] |= 1 << 5;

  res = 0;
  k = -1;
  for (l = 1; l <= m; l++)
  {
   scanf (" %d %d", &i, &j);
   if (!res)
    put (i, j);
  }

  printf ("Case #%d: ", test);
  printf ("%s", NAME[res]);
  if (res)
   printf (" in move %d", k);
  printf ("\n");
 }

 return 0;
}
