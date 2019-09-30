#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  long N, M;

  scanf("%ld%ld", &N, &M);

  if(M < 2 * N || 4 * N < M){
    printf("-1 -1 -1\n");
  }else if(M <= 3 * N){
    printf("%ld %ld 0\n", 3 * N - M, M - 2 * N);
  }else{
    printf("0 %ld %ld\n", 4 * N - M, M - 3 * N);
  }
   
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld", &N, &M);
   ^