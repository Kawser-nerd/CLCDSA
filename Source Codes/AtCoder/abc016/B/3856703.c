#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int A, B, C;

  scanf("%d%d%d", &A, &B, &C);

  if(A + B == C && A - B == C){
    printf("?\n");
  }else if(A + B == C){
    printf("+\n");
  }else if(A - B == C){
    printf("-\n");
  }else{
    printf("!\n");
  }
   
  return 0;
} ./Main.c: In function �main�:
./Main.c:11:3: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &A, &B, &C);
   ^