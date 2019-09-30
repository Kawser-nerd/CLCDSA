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

ll collatz(ll x)
{
  if (x % 2 == 0)
  {
    return x / 2;
  }
  else
  {
    return 3 * x + 1;
  }
}

int main()
{
  int n, a;
  scanf("%d%d", &n, &a);
  puts(n % 500 <= a ? "Yes" : "No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &n, &a);
   ^