#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  long long Q, H, S, D, N;
  long long mint = 1000000000, mino = 1000000000;

  scanf("%lld%lld%lld%lld%lld", &Q, &H, &S, &D, &N);

  if((8 * Q) < mint){
    mint = 8 * Q;
  }
  if((4 * H) < mint){
    mint = 4 * H;
  }
  if((2 * S) < mint){
    mint = 2 * S;
  }
  if(D < mint){
    mint = D;
  }

  if((4 * Q) < mino){
    mino = 4 * Q;
  }
  if((2 * H) < mino){
    mino = 2 * H;
  }
  if(S < mino){
    mino = S;
  }

  printf("%lld\n", mint * (N / 2) + mino * (N % 2));
	  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld%lld", &Q, &H, &S, &D, &N);
   ^