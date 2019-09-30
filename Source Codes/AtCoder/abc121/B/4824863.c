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

int b[30];
int main()
{
  int n, m, c, a, ans = 0;
  scanf("%d%d%d", &n, &m, &c);
  for (int i = 0; i < m; i++)
  {
    scanf("%d", &b[i]);
  }
  while (n)
  {
    int tmp = 0;
    for (int i = 0; i < m; i++)
    {
      scanf("%d", &a);
      tmp += a * b[i];
    }
    if (tmp + c > 0)
      ans++;
    n--;
  }
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &n, &m, &c);
   ^
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &b[i]);
     ^
./Main.c:32:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", &a);
       ^