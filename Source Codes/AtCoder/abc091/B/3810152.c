#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int max(int a, int b) { return a >= b ? a : b; }
int min(int a, int b) { return a <= b ? a : b; }
int dsum(int x) { int r=0; while(x){ r+=(x%10); x/=10; } return r;}
int gcd(int a, int b) { int i; for(i=a; i>0; i--) { if(a%i == 0 && b%i == 0) { break; } } return i; }
int lcm(int a, int b) { return (a*b)/gcd(a,b); }
void swap(int *a, int *b) { int tmp; tmp = *a; *a = *b; *b = tmp; return; }

int main(void) {
  int n,m,ans=0,cnt=0;
  char s[110][15],t[110][15];
  scanf("%d",&n);
  for(int i=0; i<n; i++) {
    scanf("%s",s[i]);
  }
  scanf("%d",&m);
  for(int i=0; i<m; i++) {
    scanf("%s",t[i]);
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(strcmp(s[i],s[j]) == 0) cnt++;
    }
    for(int j=0; j<m; j++) {
      if(strcmp(s[i],t[j]) == 0) cnt--;
    }
    ans = max(ans,cnt);
    cnt = 0;
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s[i]);
     ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&m);
   ^
./Main.c:26:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",t[i]);
     ^