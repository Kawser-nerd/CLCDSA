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

int char_upll(const void *a, const void *b) { return *(char *)a < *(char *)b ? -1 : *(char *)a > *(char *)b ? 1 : 0; }
int char_downll(const void *a, const void *b) { return *(char *)a < *(char *)b ? 1 : *(char *)a > *(char *)b ? -1 : 0; }
void char_sortup(char *a, int n) { qsort(a, n, sizeof(char), char_upll); }
void char_sortdown(char *a, int n) { qsort(a, n, sizeof(char), char_downll); }
char s[110], t[110];
int main()
{
  scanf("%s%s", s, t);
  char_sortup(s, strlen(s));
  char_sortdown(t, strlen(t));
  puts(strcmp(s, t) < 0 ? "Yes" : "No");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s", s, t);
   ^