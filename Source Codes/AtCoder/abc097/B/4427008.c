// Ver19.02
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 1 << 29
#define LLINF 4545454545454545454
#define MOD 1000000007
#define ll long long
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int upll(const void *a, const void *b) { return *(ll *)a < *(ll *)b ? -1 : *(ll *)a > *(ll *)b ? 1 : 0; }
int downll(const void *a, const void *b) { return *(ll *)a < *(ll *)b ? 1 : *(ll *)a > *(ll *)b ? -1 : 0; }
void sortup(ll *a, int n) { qsort(a, n, sizeof(ll), upll); }
void sortdown(ll *a, int n) { qsort(a, n, sizeof(ll), downll); }

int main()
{
  ll x, maybe, ans = INF;
  scanf("%lld", &x);
  if (x == 1)
  {
    printf("%d\n", 1);
    return 0;
  }
  for (int i = 2; i < 40; i++)
  {
    for (int j = 2;; j++)
    {
      maybe = pow(i, j);
      if (maybe > x)
      {
        ll diff = fabs(pow(i, j - 1) - x) - llabs(ans - x);
        if (diff <= 0 && j >= 3)
        {
          ans = pow(i, j - 1);
        }
        break;
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &x);
   ^