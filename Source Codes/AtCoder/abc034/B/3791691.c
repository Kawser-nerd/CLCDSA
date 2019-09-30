#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  long n;

  scanf("%ld", &n);

  if(n % 2 == 0){
    printf("%ld\n", n - 1);
  }else{
    printf("%ld\n", n + 1);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &n);
   ^