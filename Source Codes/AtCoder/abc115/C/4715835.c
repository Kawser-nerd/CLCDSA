#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define inf 1072114514

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 1 << 29
#define LLINF 4545454545454545454
#define MOD 1000000007
#define ll long long
#define ull unsigned long long
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int upll(const void *a, const void *b) { return *(ll *)a < *(ll *)b ? -1 : *(ll *)a > *(ll *)b ? 1 : 0; }
int downll(const void *a, const void *b) { return *(ll *)a < *(ll *)b ? 1 : *(ll *)a > *(ll *)b ? -1 : 0; }
void sortup(ll *a, int n) { qsort(a, n, sizeof(ll), upll); }
void sortdown(ll *a, int n) { qsort(a, n, sizeof(ll), downll); }

int min(int a, int b)
{
  if (a < b)
  {
    return a;
  }
  return b;
}

int sortfncsj(const void *a, const void *b)
{
  if (*(int *)a > *(int *)b)
  {
    return 1;
  }
  if (*(int *)a == *(int *)b)
  {
    return 0;
  }
  return -1;
}

int main(void)
{
  int i, n, k, a[524288], r = inf;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  qsort(a, n, sizeof(int), sortfncsj);
  for (i = k - 1; i < n; i++)
  {
    r = min(r, a[i] - a[i - k + 1]);
  }
  printf("%d\n", r);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:47:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &n, &k);
   ^
./Main.c:50:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^