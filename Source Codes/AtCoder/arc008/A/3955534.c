#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int N;

  scanf("%d", &N);

  if(N % 10 < 7){
    printf("%d\n", (15 * (N % 10)) + 100 * (N / 10));
  }else{
    printf("%d\n", 100 * ((N / 10) + 1));
  }
	  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^