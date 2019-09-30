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

const int MedN = 2000005, MaxN = MedN << 1, MaxC = 0x3F3F3F3F, NA = -1;

int a [MaxN];
int n;

int main (void)
{
 int test, tests;
 int i, j, res;
 scanf (" %d", &tests);
 for (test = 1; test <= tests; test++)
 {
  scanf (" %d", &n);
  memset (a, 0, sizeof (a));
  for (i = 0; i < n; i++)
  {
   scanf (" %d", &j);
   scanf (" %d", &a[j + MedN]);
  }
  res = 0;
  for (i = 0; i < MaxN; i++)
   if (a[i] > 1)
   {
    res++;
    a[i] -= 2;
    a[i - 1]++;
    a[i + 1]++;
    i -= 2;
   }  
  printf ("Case #%d: %d\n", test, res);
 }
 return 0;
}

