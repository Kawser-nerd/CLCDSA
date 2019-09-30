#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
 
int main(void){

  int N;
  int sum = 0;

  scanf("%d", &N);

  if(N == 10 || N == 100 || N == 1000 || N == 10000 || N == 100000){
    printf("10\n");
  }else{
    while(N >= 1){
      sum += N % 10;
      N = N / 10;
    }
    printf("%d\n", sum);
  }
    
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^