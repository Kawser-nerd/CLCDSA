#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  long N, T, i;
  long ans = 0;

  scanf("%ld%ld", &N, &T);

  long A[N];

  for(i = 0; i < N; i++){
    scanf("%ld", &A[i]);
  }

  for(i = 0; i < N - 1; i++){
    if(A[i] + T < A[i + 1]){
      ans += T;
    }else{
      ans += A[i + 1] - A[i];
    }
  }

  ans += T;

  printf("%ld\n", ans);
   
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld", &N, &T);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &A[i]);
     ^