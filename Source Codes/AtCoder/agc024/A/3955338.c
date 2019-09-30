#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  long long A, B, C;

  scanf("%lld%lld%lld", &A, &B, &C);

  long long K;

  scanf("%lld", &K);

  if(K % 2 == 0){
    printf("%lld\n", A - B);
  }else{
    printf("%lld\n", B - A);
  }
	  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld", &A, &B, &C);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &K);
   ^