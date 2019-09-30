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

ll n_x[55], m_x[55], n_y[55], m_y[55];
int main()
{
  ll n, m;
  int j;
  scanf("%lld%lld", &n, &m);
  for (int i = 0; i < n; i++)
  {
    scanf("%lld%lld", &n_x[i], &n_y[i]);
  }
  for (int i = 0; i < m; i++)
  {
    scanf("%lld%lld", &m_x[i], &m_y[i]);
  }
  for (int i = 0; i < n; i++)
  {
    ll tmp = INF, ans;
    for (j = 0; j < m; j++)
    {
      ll Manhattan = llabs(n_x[i] - m_x[j]) + llabs(n_y[i] - m_y[j]);
      if (tmp > Manhattan)
      {
        tmp = Manhattan;
        ans = j + 1;
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &n, &m);
   ^
./Main.c:26:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld", &n_x[i], &n_y[i]);
     ^
./Main.c:30:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld", &m_x[i], &m_y[i]);
     ^