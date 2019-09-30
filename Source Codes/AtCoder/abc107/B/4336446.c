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
  int h, w;
  char s[101][101];
  int yoko[101];
  int tate[101];
  scanf("%d%d", &h, &w);
  for (int i = 0; i < h; i++)
  {
    scanf("%s", s[i]);
  }
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      if (s[i][j] == '#')
      {
        yoko[i] = 1;
        break;
      }
      else
        yoko[i] = 0;
    }
  }
  for (int j = 0; j < w; j++)
  {
    for (int i = 0; i < h; i++)
    {
      if (s[i][j] == '#')
      {
        tate[j] = 1;
        break;
      }
      else
        tate[j] = 0;
    }
  }
  for (int i = 0; i < h; i++)
  {
    if (yoko[i] == 1)
    {
      for (int j = 0; j < w; j++)
      {
        if (tate[j] == 1)
        {
          putchar(s[i][j]);
        }
      }
      puts("");
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &h, &w);
   ^
./Main.c:26:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s[i]);
     ^