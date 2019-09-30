#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  long A, B;

  scanf("%ld%ld", &A, &B);

  if(A * B < 0){
    printf("%ld\n", B - A - 1);
  }else{
    printf("%ld\n", B - A);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld", &A, &B);
   ^