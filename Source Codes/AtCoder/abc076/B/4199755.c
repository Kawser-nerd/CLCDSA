#include<stdio.h>

int main(){
  int N, K, r = 1;
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++){
    if(r < K){
      r *= 2;
    } else {
      r += K;
    }
  }
  
  printf("%d\n", r);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &K);
   ^