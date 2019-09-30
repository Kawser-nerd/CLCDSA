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

char s[110], t[110], tmp[10];
int main()
{
  scanf("%s%s", s, t);
  for (int j = 0; j < strlen(s) - 1; j++)
  {
    for (int i = 0; i < strlen(s) - 1; i++)
    {
      if (s[i] > s[i + 1])
      {
        tmp[0] = s[i];
        s[i] = s[i + 1];
        s[i + 1] = tmp[0];
      }
    }
  }
  for (int j = 0; j < strlen(t) - 1; j++)
  {
    for (int i = 0; i < strlen(t) - 1; i++)
    {
      if (t[i] < t[i + 1])
      {
        tmp[0] = t[i];
        t[i] = t[i + 1];
        t[i + 1] = tmp[0];
      }
    }
  }
  puts(strcmp(s, t) < 0 ? "Yes" : "No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s", s, t);
   ^