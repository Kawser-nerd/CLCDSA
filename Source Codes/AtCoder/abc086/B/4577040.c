// Ver19.03
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

int main()
{
  ll a, b, b_digit = 0, tmp;
  scanf("%lld%lld", &a, &b);
  ll bb = b;
  while (1)
  {
    bb /= 10;
    b_digit++;
    if (bb == 0)
      break;
  }
  tmp = a * pow(10, b_digit) + b;
  for (int i = 1; i <= sqrt(100100); i++)
  {
    if (i * i == tmp)
    {
      puts("Yes");
      return 0;
    }
  }
  puts("No");
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &a, &b);
   ^