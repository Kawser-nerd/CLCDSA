#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int a, b;

  scanf("%d%d", &a, &b);

  if(a < b){
    if((b - a) < (10 + a - b)){
      printf("%d\n", b - a);
    }else{
      printf("%d\n", 10 + a - b);
    }
  }else{
    if((a - b) < (10 + b - a)){
      printf("%d\n", a - b);
    }else{
      printf("%d\n", 10 + b - a);
    }
  }
   
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^