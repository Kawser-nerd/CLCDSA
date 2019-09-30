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
  int n, count = 1;
  int maybe = 0, ans = 0;
  char s[110];
  scanf("%d%s", &n, s);
  while (count < n)
  {
    for (int k = 'a'; k <= 'z'; k++)
    {
      int left = 0, right = 0;
      for (int j = 0; j < count; j++)
      {
        if (s[j] == k)
        {
          left = 1;
          break;
        }
      }
      for (int j = count; j < n; j++)
      {
        if (s[j] == k)
        {
          right = 1;
          break;
        }
      }
      if (left && right)
      {
        maybe++;
      }
    }
    ans = MAX(ans, maybe);
    maybe = 0;
    count++;
  }
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%s", &n, s);
   ^