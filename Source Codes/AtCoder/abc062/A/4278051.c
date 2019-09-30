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
  int a[] = {1, 3, 5, 7, 8, 10, 12};
  int b[] = {4, 6, 9, 11};
  int x, y;
  scanf("%d%d", &x, &y);
  if (x == 2 || y == 2)
  {
    puts("No");
    return 0;
  }
  for (int i = 0; i < sizeof(a) / sizeof(int); i++)
  {
    if (x == a[i])
    {
      if (y == 4 || y == 6 || y == 9 || y == 11)
      {
        puts("No");
        return 0;
      }
      else
      {
        puts("Yes");
        return 0;
      }
    }
  }
  if (y == 4 || y == 6 || y == 9 || y == 11)
    puts("Yes");
  else
    puts("No");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &x, &y);
   ^