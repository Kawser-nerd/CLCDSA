#include <stdio.h>

int main(void){
  int A,B,C,K;
  int S,T;
  scanf("%d%d%d%d",&A,&B,&C,&K);
  scanf("%d%d",&S,&T);

  int money = A*S+T*B;
  if(S+T >= K) money -= C*(S+T);

  printf("%d\n",money);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&A,&B,&C,&K);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&S,&T);
   ^