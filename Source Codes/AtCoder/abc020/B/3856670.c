#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int A, B;

  scanf("%d%d", &A, &B);

  if(B < 10){
    printf("%d\n", (A * 10 + B) * 2);
  }else if(B < 100){
    printf("%d\n", (A * 100 + B) * 2);
  }else{
    printf("%d\n", (A * 1000 + B) * 2);
  }
   
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &A, &B);
   ^