#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  long x, y, k;

  scanf("%ld%ld%ld", &x, &y, &k);

  if(k <= y){
    printf("%ld\n", x + k);
  }else{
    printf("%ld\n", x + y - (k - y));
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld%ld", &x, &y, &k);
   ^