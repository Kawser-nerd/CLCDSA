#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

#define INF 1e9
#define LLINF 1e18
#define PI 3.1415926535897932384
#define MOD 1000000007

typedef long long ll;
typedef long double ld;

int max(int a, int b) { return a >= b ? a : b; }
int min(int a, int b) { return a <= b ? a : b; }
int dsum(int x) { int r=0; while(x){ r+=(x%10); x/=10; } return r;}
int gcd(int a, int b) { int i; for(i=a; i>0; i--) { if(a%i == 0 && b%i == 0) { break; } } return i; }
int lcm(int a, int b) { return (a*b)/gcd(a,b); }
int asc(const void *a, const void *b) { if(*(int *)a > *(int *)b) { return 1;} if(*(int *)a == *(int *)b) { return 0;} return -1;}
int des(const void *a, const void *b) { if(*(int *)a < *(int *)b) { return 1;} if(*(int *)a == *(int *)b) { return 0;} return -1;}
int llasc(const void *a, const void *b) { if(*(long long *)a > *(long long *)b) {return 1;} if(*(long long *)a == *(long long *)b) {return 0;} return -1;}
int lldes(const void *a, const void *b) { if(*(long long *)a < *(long long *)b) {return 1;} if(*(long long *)a == *(long long *)b) {return 0;} return -1;}
int flasc(const void *a, const void *b) { if(*(float *)a > *(float *)b) {return 1;} if(*(float *)a == *(float *)b) {return 0;} return -1;}
int fldes(const void *a, const void *b) { if(*(float *)a < *(float *)b) {return 1;} if(*(float *)a == *(float *)b) {return 0;} return -1;}
int dbasc(const void *a, const void *b) { if(*(double *)a > *(double *)b) {return 1;} if(*(double *)a == *(double *)b) {return 0;} return -1;}
int dbdes(const void *a, const void *b) { if(*(double *)a < *(double *)b) {return 1;} if(*(double *)a == *(double *)b) {return 0;} return -1;}
int chasc(const void *a, const void *b) { if(*(char *)a > *(char *)b) {return 1;} if(*(char *)a == *(char *)b) {return 0;} return -1;}
int chdes(const void *a, const void *b) { if(*(char *)a < *(char *)b) {return 1;} if(*(char *)a == *(char *)b) {return 0;} return -1;}
int strasc(const void *a, const void *b) { return(strcmp(*(char **)a, *(char **)b)); }
int strdes(const void *a, const void *b) { return(strcmp(*(char **)b, *(char **)a)); }
void swap(int *a, int *b) { int tmp; tmp = *a; *a = *b; *b = tmp; return; }

int main(void) {
  int i, j, k, len, n, res = 0, flag;
  char s[330];
  scanf("%s%d", s, &n);
  len = strlen(s);
  if(n > len) {
    printf("0\n");
    return 0;
  }
  for(i = 0; i <= len - n; ++i) {
    flag = 0;
    for(j = i + 1; j <= len-n; ++j) {
      for(k = 0; k < n; ++k) {
        if(s[i + k] != s[j + k]) break;
        if(k == n - 1) ++flag;
      }
    }
    if(flag == 0) ++res;
  }
  printf("%d\n", res);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:38:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%d", s, &n);
   ^