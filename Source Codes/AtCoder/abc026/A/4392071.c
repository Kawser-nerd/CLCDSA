#include <stdio.h>

int main(void){
  int A;
  scanf("%d",&A);
  printf("%d\n",A*A/4);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&A);
   ^