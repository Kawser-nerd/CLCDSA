#include <stdio.h>

int main(void){
  int A,B,C;
  scanf("%d%d%d",&A,&B,&C);

  if(A-B == C && A+B == C) printf("?");
  else if(A+B == C) printf("+");
  else if(A-B == C) printf("-");
  else printf("!");

  printf("\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&A,&B,&C);
   ^