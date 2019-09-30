#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int A, B, C, D, E;

  scanf("%d%d%d%d%d", &A, &B, &C, &D, &E);

  if(D + A > C + B){
    printf("%d\n", E + D + A);
  }else{
    printf("%d\n", E + C + B);
  }
   
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d", &A, &B, &C, &D, &E);
   ^