#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int N;

  scanf("%d", &N);

  if((N - 1) / 9 == 0){
    printf("%d\n", N);
  }else if((N - 1) / 9 == 1){
    printf("%d%d\n", (N - 1) % 9 + 1, (N - 1) % 9 + 1);
  }else if((N - 1) / 9 == 2){
    printf("%d%d%d\n", (N - 1) % 9 + 1, (N - 1) % 9 + 1, (N - 1) % 9 + 1);
  }else if((N - 1) / 9 == 3){
    printf("%d%d%d%d\n", (N - 1) % 9 + 1, (N - 1) % 9 + 1, (N - 1) % 9 + 1, (N - 1) % 9 + 1);
  }else if((N - 1) / 9 == 4){
    printf("%d%d%d%d%d\n", (N - 1) % 9 + 1, (N - 1) % 9 + 1, (N - 1) % 9 + 1, (N - 1) % 9 + 1, (N - 1) % 9 + 1);
  }else if((N - 1) / 9 == 5){
    printf("%d%d%d%d%d%d\n", (N - 1) % 9 + 1, (N - 1) % 9 + 1, (N - 1) % 9 + 1, (N - 1) % 9 + 1, (N - 1) % 9 + 1, (N - 1) % 9 + 1);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^