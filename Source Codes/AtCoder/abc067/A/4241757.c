#include <stdio.h>

int main(void){
  int A,B;
  scanf("%d%d",&A,&B);

  if(A%3 == 0 || B%3 == 0 || (A+B)%3 == 0) printf("Possible\n");
  else printf("Impossible\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&A,&B);
   ^