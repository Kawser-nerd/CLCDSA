#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
 
  long long N, i, odd = 0;

  scanf("%lld", &N);

  long long A[N];

  for(i = 0; i < N; i++){
    scanf("%lld", &A[i]);
    if(A[i] % 2 == 1){
      odd++;
    }
  }

  if(odd % 2 == 0){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &N);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &A[i]);
     ^