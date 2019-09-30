#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  long H, W;

  scanf("%ld%ld", &W, &H);

  if((W * 3) == (H * 4)){
    printf("4:3\n");
  }else{
    printf("16:9\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld", &W, &H);
   ^