#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  int n, x;

  scanf("%d %d", &n, &x);

  if((n - x) < (x - 1)){
    printf("%d\n", n - x);
  }else{
    printf("%d\n", x - 1);
  }
   
  return 0;
} ./Main.c: In function �main�:
./Main.c:11:3: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &x);
   ^