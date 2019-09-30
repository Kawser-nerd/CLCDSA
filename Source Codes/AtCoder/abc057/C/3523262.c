#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  long N;
  long i;
  long max, rev;
  long ans = 0;

  scanf("%ld", &N);

  for(i = 1; i <= sqrt(N); i++){
    if(N % i == 0){
      max = i;
    }
  }

  rev = N / max;
  
  while(rev >= 1){
    ans++;
    rev /= 10;
  }

  printf("%ld\n", ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &N);
   ^