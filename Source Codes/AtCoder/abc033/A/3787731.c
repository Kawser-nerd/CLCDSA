#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  char N[4];

  scanf("%s", N);

  if((N[0] == N[1]) && (N[1] == N[2]) && (N[2] == N[3])){
    printf("SAME\n");
  }else{
    printf("DIFFERENT\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", N);
   ^