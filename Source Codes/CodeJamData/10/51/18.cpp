#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;

const int MaxK = 7, MaxN = 1000006, MaxC = 0x3F3F3F3F, NA = -1;

bool s [MaxN];
int a [MaxN];
int p [MaxN];
int lim [MaxK] = {1, 10, 100, 1000, 10000, 100000, 1000000};
int n, d, k;

int64 powmod (int64 a, int64 b, int64 c)
{
 int64 i, res;
 res = 1;
 for (i = 1; i <= b; i <<= 1)
 {
  if (i & b)
   res = (res * a) % c;
  a = (a * a) % c;
 }
 return res;
}

int main (void)
{
 int test, tests;
 int i, j, u;
 memset (s, 1, sizeof (s));
 s[0] = s[1] = false;
 for (i = 2; i * i < MaxN; i++)
  if (s[i])
   for (j = i * i; j < MaxN; j += i)
    s[j] = false;
 n = 0;
 for (i = 0; i < MaxN; i++)
  if (s[i])
   p[n++] = i;
// printf ("%d\n", n);
 scanf (" %d", &tests);
 for (test = 1; test <= tests; test++)
 {
  int ok, res;
  scanf (" %d %d", &d, &k);
  for (u = 0; u < k; u++)
   scanf (" %d", &a[u]);
  if (k == 1)
  {
   ok = 2;
   res = NA;
  }
  else if (k == 2)
  {
   if (a[0] == a[1])
   {
    ok = 1;
    res = a[0];
   }
   else
   {
    // A = 1, B = a[0] - a[1] != 0, res = a[1] + B != a[1]
    // OR A = 0, B = a[1], res = a[1]
    ok = 2;
    res = NA;
   }
  }
  else
  {
   ok = 0;
   res = NA;
   for (i = 0; p[i] <= lim[d] && ok <= 1; i++)
   {
    for (u = 0; u < k; u++)
     if (p[i] <= a[u])
      break;
    if (u < k)
     continue;
//    a[1] == (a[0] * x + y) % p;
//    a[2] == (a[1] * x + y) % p;

//  a1 = a0 * x + y
//  a2 = a1 * x + y

//  y = a1 - a0 * x
//  a2 = a1 * x + a1 - a0 * x
//  a2 - a1 = (a1 - a0) * x
//  x = (a2 - a1) / (a1 - a0)
    int64 x, y;
    if (a[0] == a[1])
    {
     x = 1;
     y = 0;
    }
    else
    {
     x = (a[2] - a[1] + p[i]) % p[i];
     x = (x * powmod ((a[1] - a[0] + p[i]) % p[i], p[i] - 2, p[i])) % p[i];
     y = ((((int64) a[1] - a[0] * x) % p[i]) + p[i]) % p[i];
    }
//    printf ("%d %d\n", (int) x, (int) y);
    for (u = 3; u < k; u++)
     if (a[u] != ((int64) a[u - 1] * x + y) % p[i])
      break;
    if (u >= k)
    {
     ok++;
     int cur = ((int64) a[u - 1] * x + y) % p[i];
//     printf ("%d %d %d: %d\n", j, r, p[i], cur);
     if (ok == 1)
      res = cur;
     else if (res == cur)
      ok--;
    }
   }
  }
  printf ("Case #%d: ", test);
  assert (ok > 0);
  if (ok > 1)
   printf ("I don't know.\n");
  else
   printf ("%d\n", res);
 }
 return 0;
}

