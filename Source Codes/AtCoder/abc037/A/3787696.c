#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  long A, B, C;

  scanf("%ld%ld%ld", &A, &B, &C);

  if(A < B){
    printf("%ld\n", C / A);
  }else{
    printf("%ld\n", C / B);
  }
   
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld%ld", &A, &B, &C);
   ^