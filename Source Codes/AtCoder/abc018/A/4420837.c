#include <stdio.h>

int main(void){
  int A,B,C;
  scanf("%d%d%d",&A,&B,&C);

  if(A > B && A > C) printf("1\n");
  else if(A < B && A < C) printf("3\n");
  else printf("2\n");

  if(B > A && B > C) printf("1\n");
  else if(B < A && B < C) printf("3\n");
  else printf("2\n");

  if(C > B && C > A) printf("1\n");
  else if(C < B && C < A) printf("3\n");
  else printf("2\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&A,&B,&C);
   ^