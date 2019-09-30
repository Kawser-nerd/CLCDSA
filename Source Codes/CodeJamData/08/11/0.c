
#include <stdio.h>
#include <stdlib.h>

static int x[1024];
static int y[1024];

int cmp_int (const void *ptr1, const void *ptr2)
{
  int *i1 = (int *) ptr1;
  int *i2 = (int *) ptr2;
  return (*i1) - (*i2);
}

int main (int argc, char **argv)
{
  int T, n, test;
  int i;
  scanf ("%d", &T);
  for (test = 1; test <= T; test++) {
    long long result;
    scanf ("%d", &n);
    for (i = 0; i < n; i++)
      scanf ("%d", &x[i]);
    for (i = 0; i < n; i++)
      scanf ("%d", &y[i]);
    qsort (x, n, sizeof (int), &cmp_int);
    qsort (y, n, sizeof (int), &cmp_int);
    result = 0;
    for (i = 0; i < n; i++) {
      long long p = x[i];
      p *= (long long) y[n - 1 - i];
      result += p;
    }
    printf ("Case #%d: %lld\n", test, result);
  }

  return 0;
}
