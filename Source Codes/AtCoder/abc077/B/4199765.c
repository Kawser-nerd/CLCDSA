#include<stdio.h>
#include<math.h>

int main(){
  int N;
  
  scanf("%d", &N);
  N = sqrt(N);
  
  printf("%d", N*N);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^