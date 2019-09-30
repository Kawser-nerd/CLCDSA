#include <stdio.h>

int main(void){
  char A[3],B[3],C[3];

  scanf("%s%s%s",A,B,C);

  printf("%c%c%c\n",A[0],B[1],C[2]);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s%s",A,B,C);
   ^