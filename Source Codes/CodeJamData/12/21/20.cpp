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

const int MaxN = 100005, MaxC = 0x3F3F3F3F, NA = -1;

int a [MaxN];
int n, s;

bool good (int i, real r)
{
 int j;
 real t;
 t = 0;
 for (j = 0; j < n; j++)
  t += max (0.0L, a[i] + r - a[j]);
 return t <= s;
}

int main (void)
{
 int test, tests;
 int i, k;
 real lo, me, hi;

 scanf (" %d ", &tests);
 for (test = 1; test <= tests; test++)
 {
  scanf (" %d", &n);
  s = 0;
  for (i = 0; i < n; i++)
  {
   scanf (" %d", &a[i]);
   s += a[i];
  }

  printf ("Case #%d:", test);
  for (i = 0; i < n; i++)
  {
   lo = 0.0;
   hi = s;
   for (k = 0; k < 100; k++)
   {
    me = (lo + hi) * 0.5;
    if (good (i, me))
     lo = me;
    else
     hi = me;
   }
   printf (" %.10lf", (double) lo / s * 100);
  }
  printf ("\n");
 }

 return 0;
}
