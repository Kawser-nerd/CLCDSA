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
  char a[11], b[11], c[11];
  scanf("%s%s%s", a, b, c);
  for (int i = 0; i < 11; i++)
  {
    if (a[i] == '\0')
    {
      if (a[i - 1] == b[0])
      {
        for (int j = 0; j < 11; j++)
        {
          if (b[j] == '\0')
          {
            if (b[j - 1] == c[0])
            {
              puts("YES");
              return 0;
            }
          }
        }
      }
    }
  }
  puts("NO");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s%s", a, b, c);
   ^