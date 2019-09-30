#include<stdio.h>

int main(){
  
  int N,A;
  
  scanf("%d",&N);
  scanf("%d",&A);
  
  printf("%d",N * N - A);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&A);
   ^