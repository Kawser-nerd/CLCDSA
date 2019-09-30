#include <stdio.h>
int main(){
  int N, K, sum=1;
  scanf("%d%d", &N ,&K);
  for (int i=0; i<N ; i++){
    if (sum < K){
    sum *= 2;
    }
    else{
      sum += K;
    }
  }
  printf("%d", sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &N ,&K);
   ^