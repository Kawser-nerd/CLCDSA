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
void swap(int *a, int *b) { int tmp; tmp = *a; *a = *b; *b = tmp; return; }

int N, M;
char board[60][60];
char pattern[60][60];

int match(int x, int y) {
  int i, j;
  for(i = 0; i < M; ++i) {
    for(j = 0; j < M; ++j) {
      if(board[x+i][y+j] != pattern[i][j])
        return 0;
    }
  }
  return 1;
}



int main(void) {
  scanf("%d %d",&N,&M);
  int i, j;
  for(i = 0; i < N; ++i) scanf("%s", board[i]);
  for(i = 0; i < M; ++i) scanf("%s", pattern[i]);

  int flag = 0;
  for(i = 0; i <=N-M; ++i) {
    for(j = 0; j <=N-M; ++j) {
      if(match(i,j)) flag = 1;
    }
  }
  if(flag) puts("Yes");
  else puts("No");  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:51:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&M);
   ^
./Main.c:53:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i = 0; i < N; ++i) scanf("%s", board[i]);
                          ^
./Main.c:54:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i = 0; i < M; ++i) scanf("%s", pattern[i]);
                          ^