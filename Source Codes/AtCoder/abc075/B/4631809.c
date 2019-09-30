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

char a[99][99];
int main()
{
  int h, w;
  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; i++)
  {
    scanf("%s", a[i + 10] + 10);
  }
  for (int i = 0 + 10; i < h + 10; i++)
  {
    for (int j = 0 + 10; j < w + 10; j++)
    {
      if (a[i][j] == '#')
      {
        putchar('#');
      }
      else
      {
        int count = 0;
        for (int k = -1; k <= 1; k++)
        {
          for (int l = -1; l <= 1; l++)
          {
            if (k != 0 || l != 0)
            {
              if (a[i + k][j + l] == '#')
              {
                count++;
              }
            }
          }
        }
        printf("%d", count);
      }
    }
    puts("");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &h, &w);
   ^
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", a[i + 10] + 10);
     ^