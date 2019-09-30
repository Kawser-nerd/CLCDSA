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

const int MaxD = 12, MaxN = 102, MaxC = 0x3F3F3F3F, NA = -1;

bool u [MaxN] [MaxD];
int b, n;

bool mark (int k)
{
 int i, j;
 for (i = k, j = 0; i > 0; i /= b, j++)
  if (u[j][i % b])
   break;
 if (i > 0)
  return false;
 for (i = k, j = 0; i > 0; i /= b, j++)
  u[j][i % b] = true;
 return true;
}

void unmark (int k)
{
 int i, j;
 for (i = k, j = 0; i > 0; i /= b, j++)
  u[j][i % b] = false;
}

int recur (int lim, int sum)
{
 if (sum == 0)
  return 1;
 int i, res = 0;
 for (i = lim; i <= sum; i++)
 {
  if (mark (i))
  {
   res += recur (i + 1, sum - i);
   unmark (i);
  }
 }
 return res;
}

int main (void)
{
 int test, tests;
 scanf (" %d", &tests);
 for (test = 1; test <= tests; test++)
 {
  scanf (" %d %d", &n, &b);
  memset (u, 0, sizeof (u));
  printf ("Case #%d: %d\n", test, recur (1, n));
 }
 return 0;
}

