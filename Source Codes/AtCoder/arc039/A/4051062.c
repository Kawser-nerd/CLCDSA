#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int A, B;

  scanf("%d%d", &A, &B);

  if((A / 100 != 9) || (B / 100 != 1)){
    if((9 - A / 100) > (B / 100 - 1)){
      printf("%d\n", A - B + (9 - A / 100) * 100);
    }else{
      printf("%d\n", A - B + (B / 100 - 1) * 100);
    }
  }else if((((A % 100) / 10) != 9) || (((B % 100) / 10) != 0)){
    if((9 - ((A % 100) / 10)) > ((B % 100) / 10)){
      printf("%d\n", A - B + (9 - ((A % 100) / 10)) * 10);
    }else{
      printf("%d\n", A - B + ((B % 100) / 10) * 10);
    }
  }else{
    if((9 - (A % 10)) > (B % 10)){
      printf("%d\n", A - B + (9 - (A % 10)));
    }else{
      printf("%d\n", A - B + (B % 10));
    }
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &A, &B);
   ^