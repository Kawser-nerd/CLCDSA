#include<stdio.h>
int N, A;
int main(){
  scanf("%d%d", &N, &A);
  printf("%d\n", N*N-A);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &N, &A);
   ^