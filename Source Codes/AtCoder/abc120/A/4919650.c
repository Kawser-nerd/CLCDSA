#include <stdio.h>

int main(){
  int A, B, C;
  int count;
  scanf("%d %d %d",&A,&B,&C);
  
  if(A * C <= B){
    count = C;
  }else{
    count = B / A;
  }

  printf("%d",count);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&A,&B,&C);
   ^