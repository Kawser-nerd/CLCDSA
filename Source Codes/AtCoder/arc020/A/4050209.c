#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int A, B;

  scanf("%d%d", &A, &B);

  if(abs(A) == abs(B)){
    printf("Draw\n");
  }else if(abs(A) < abs(B)){
    printf("Ant\n");
  }else{
    printf("Bug\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &A, &B);
   ^