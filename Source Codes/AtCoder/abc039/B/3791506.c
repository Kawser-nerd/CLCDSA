#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  long N;

  scanf("%ld", &N);

  printf("%.0f\n", sqrt(sqrt(N)));
  
  return 0;
} ./Main.c: In function �main�:
./Main.c:11:3: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &N);
   ^