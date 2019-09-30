#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  long N, M, i;

  scanf("%ld%ld", &N, &M);

  long a[M];
  long b[N + 1];

  for(i = 0; i < M; i++){
    scanf("%ld", &a[i]);
  }

  for(i = 1; i <= N; i++){
    b[i] = 0;
  }

  for(i = M - 1; i >= 0; i--){
    if(b[a[i]] == 0){
      printf("%ld\n", a[i]);
      b[a[i]] = 1;
    }
  }
  for(i = 1; i <= N; i++){
    if(b[i] == 0){
      printf("%ld\n", i);
    }
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld", &N, &M);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &a[i]);
     ^