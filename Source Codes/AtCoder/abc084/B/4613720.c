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
  ll a, b;
  scanf("%lld%lld", &a, &b);
  char s[a + b + 2];
  scanf("%s", s);
  if (s[a] == '-')
  {
    for (int i = 0; i < a + b + 1; i++)
    {
      if (i == a)
        continue;
      if (s[i] < '0' || s[i] > '9')
      {
        puts("No");
        return 0;
      }
    }
    puts("Yes");
  }
  else
    puts("No");
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &a, &b);
   ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^