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

ll calc_diff_fromA(ll, ll, ll);

int main()
{
  ll n, t, a;
  ll h[1001];
  ll min_diff = INF;
  ll ans;
  scanf("%lld%lld%lld", &n, &t, &a);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld", &h[i]);
    ll maybe = calc_diff_fromA(t, h[i], a);
    if (maybe < min_diff)
    {
      min_diff = maybe;
      ans = i;
    }
  }
  printf("%lld\n", ans + 1);

  return 0;
}

ll calc_diff_fromA(ll t, ll x, ll a)
{
  return llabs(a * 1000 - (t * 1000 - x * 6));
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld", &n, &t, &a);
   ^
./Main.c:28:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &h[i]);
     ^