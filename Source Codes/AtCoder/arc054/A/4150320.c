#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  long L, X, Y, S, D;

  scanf("%ld%ld%ld%ld%ld", &L, &X, &Y, &S, &D);

  if(Y <= X){
    if(D < S){
      printf("%.6f\n", (double)(L - S + D) / (X + Y));
    }else{
      printf("%.6f\n", (double)(D - S) / (X + Y));
    }
  }else{
    if(D < S){
      if(((double)(L - S + D) / (X + Y)) < ((double)(S - D) / (Y - X))){
	printf("%.6f\n", (double)(L - S + D) / (X + Y));
      }else{
	printf("%.6f\n", (double)(S - D) / (Y - X));
      }
    }else{
      if(((double)(D - S) / (X + Y)) < ((double)(L - D + S) / (Y - X))){
	printf("%.6f\n", (double)(D - S) / (X + Y));
      }else{
	printf("%.6f\n", (double)(L - D + S) / (Y - X));
      }
    }
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld%ld%ld%ld", &L, &X, &Y, &S, &D);
   ^