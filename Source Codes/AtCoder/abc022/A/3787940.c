#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  long N, S, T, W;
  long i;
  long ans = 0;

  scanf("%ld%ld%ld%ld", &N, &S, &T, &W);

  if((S <= W) && (W <= T)){
    ans++;
  }

  long A[N];

  for(i = 0; i < N - 1; i++){
    scanf("%ld", &A[i]);
    W += A[i];
    if((S <= W) && (W <= T)){
      ans++;
    }
  }

  printf("%ld\n", ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld%ld%ld", &N, &S, &T, &W);
   ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &A[i]);
     ^