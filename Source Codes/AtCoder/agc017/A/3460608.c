#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
 
int main(void){

  long N, P;
  long i;
  long k = 0, n = 0;
  long e = 1, o = 1;
  long x;

  scanf("%ld %ld", &N, &P);

  long A[N];

  for(i = 0; i < N; i++){
    scanf("%ld", &A[i]);
  }

  for(i = 0; i< N; i++){
    if(A[i] % 2 == 0){
      k++;
    }else{
      n++;
    }
  }

  x = k + n - 1;

  if(n == 0){
    while(k > 0){
      e = 2 * e;
      k--;
    }
  }else{
    while(x > 0){
      e = 2 * e;
      x--;
    }
  }

  while(N > 0){
    o = 2 * o;
    N--;
  }

  if(P == 0){
    printf("%ld\n", e);
  }else{
    printf("%ld\n", o - e);
  }
    
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld", &N, &P);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &A[i]);
     ^