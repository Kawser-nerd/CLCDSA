#include<stdio.h>

int main(){
  int N, K, i, r;
  
  scanf("%d %d", &N, &K);
  
  r = K;
  for (i = 1; i < N; i++){
    r *= K - 1;
  }
  printf("%d\n", r);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &K);
   ^