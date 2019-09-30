#include <stdio.h>

int main(void){
  int A;
  scanf("%d",&A);

  if(A%1111 == 0) printf("SAME\n");
  else printf("DIFFERENT\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&A);
   ^