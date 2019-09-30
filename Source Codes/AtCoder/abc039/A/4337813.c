#include <stdio.h>

int main(void){
  int A,B,C;
  scanf("%d%d%d",&A,&B,&C);
  printf("%d\n",2*(A*B+B*C+C*A));

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&A,&B,&C);
   ^