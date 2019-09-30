// Ver19.03
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF (1 << 29) * 2
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

typedef struct
{
  ll node;
  ll val;
  ll index;
} sd;

int sortsd(const void *a, const void *b)
{
  return ((sd *)a)->val < ((sd *)b)->val ? -1 : ((sd *)a)->val > ((sd *)b)->val ? 1 : 0;
}

sd a[100005];
ll b[100005];
ll res[2][100005];
int main()
{
  ll n, k;
  scanf("%lld%lld", &n, &k);
  for (int i = 0; i < k; i++)
  {
    scanf("%lld%lld", &a[i].node, &a[i].val);
    a[i].index = i;
  }
  qsort(a, k, sizeof(a[0]), sortsd);
  for (int i = 0; i < k; i++)
  {
    res[0][a[i].index] = a[i].node;
    b[a[i].node]++;
    res[1][a[i].index] = b[a[i].node];
  }
  for (int i = 0; i < k; i++)
  {
    printf("%06lld%06lld\n", res[0][i], res[1][i]);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &n, &k);
   ^
./Main.c:39:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld", &a[i].node, &a[i].val);
     ^