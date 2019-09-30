#include <stdio.h>

int main(void){
  int A,B,X;
  scanf("%d%d%d",&A,&B,&X);

  if(A <= X && X <= A+B){
    printf("YES\n");
  }else{
    printf("NO\n");
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&A,&B,&X);
   ^