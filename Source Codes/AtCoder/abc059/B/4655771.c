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

char s[3][110];
int main()
{
  scanf("%s", s[0]);
  scanf("%s", s[1]);
  ll n = strlen(s[0]), m = strlen(s[1]);
  int flag;
  if(n>m) flag=1;
  else if(n<m) flag=-1;
  else flag = strcmp(s[0], s[1]);
  puts(flag > 0 ? "GREATER" : flag < 0 ? "LESS" : "EQUAL");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s[0]);
   ^
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s[1]);
   ^