#include<stdio.h>

int main(void){
  int N,M;
  scanf("%d%d",&N,&M);
  printf("%d\n",(100*(N-M)+1900*M)<<M);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^