#include<stdio.h>
int main() {
  int N;
  int p[10];
  int i; /* index */
  scanf("%d",&N);
  for (i = 0;i < N;++i) {
    scanf("%d",&p[i]);
  }
  int max = p[0];
  for (i = 0;i < N;++i) {
    if (max < p[i]) {
      max = p[i];
    }
  }
  int ans = 0;
  for (i = 0;i < N;++i) {
    ans	+= p[i];
  }
  ans =	ans - max + max	/ 2;
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&p[i]);
     ^