#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
 
int main(void){

  long A, B, C;

  scanf("%ld %ld %ld", &A, &B, &C);

  if(A % 2 == 0 || B % 2 == 0 || C % 2 == 0){
    printf("0\n");
  }else{
    if((A * B < A * C) && (A * B < B * C)){
      printf("%ld\n", A * B);
    }else if((A * C < A * B) && (A * C < B * C)){
      printf("%ld\n", A * C);
    }else{
      printf("%ld\n", B * C);
    }
  }
    
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld %ld", &A, &B, &C);
   ^