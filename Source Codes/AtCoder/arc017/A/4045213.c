#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  long N, i;
  long t = 0;

  scanf("%ld", &N);

  for(i = 2; i <= sqrt(N); i++){
    if(N % i == 0){
      t = 1;
      break;
    }
  }

  if(t == 1){
    printf("NO\n");
  }else{
    printf("YES\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &N);
   ^