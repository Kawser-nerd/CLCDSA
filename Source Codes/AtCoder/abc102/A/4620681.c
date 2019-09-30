#include<stdio.h>
int main(void){
  int N;
  scanf("%d",&N);
  if(N%2!=0){
    printf("%d\n",2*N);
  }else{
    printf("%d\n",N);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^