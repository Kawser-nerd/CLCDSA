#include<stdio.h>
int X, N;
int main(){
  scanf("%d", &X);
  while(N*N*N*N != X){
    N++;
  }
  printf("%d\n", N);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &X);
   ^