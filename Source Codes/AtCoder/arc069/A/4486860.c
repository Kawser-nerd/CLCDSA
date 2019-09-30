#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  long long N, M;

  scanf("%lld%lld", &N, &M);

  if(M >= 2 * N){
    printf("%lld\n", N + (M - 2 * N) / 4);
  }else{
    printf("%lld\n", M / 2);
  }
	
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &N, &M);
   ^