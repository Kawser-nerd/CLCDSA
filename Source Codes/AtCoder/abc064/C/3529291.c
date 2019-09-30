#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  int N;
  int k;

  scanf("%d", &N);

  int a;
  int b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0;

  for(k = 0; k < N; k++){
    scanf("%d", &a);
    if(a <= 399){
      b = 1;
    }else if(a <= 799){
      c = 1;
    }else if(a <= 1199){
      d = 1;
    }else if(a <= 1599){
      e = 1;
    }else if(a <= 1999){
      f = 1;
    }else if(a <= 2399){
      g = 1;
    }else if(a <= 2799){
      h = 1;
    }else if(a <= 3199){
      i = 1;
    }else{
      j++;
    }
  }

  if(j == 0){
    printf("%d %d\n", b + c + d + e + f + g + h + i, b + c + d + e + f + g + h + i);
  }else if((b + c + d + e + f + g + h + i) == 0){
    
    printf("1 %d\n", j);
  }else{
    printf("%d %d\n", b + c + d + e + f + g + h + i, b + c + d + e + f + g + h + i + j);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a);
     ^