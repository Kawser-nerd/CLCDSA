#include <stdio.h>
int main(){
  int N, K, i, x, res=0;
  scanf("%d %d", &N, &K);
  for (i=0; i<N; i++) {
    scanf("%d", &x);
    if (x*2<(K-x)*2) res+=x*2;
    else res+=(K-x)*2;
  }
  printf("%d\n", res);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &K);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &x);
     ^