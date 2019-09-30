#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(void){
  
  long long N;
  long long i;
  long long c = 0;

  scanf("%lld", &N);

  long long a[N];

  for(i = 0; i < N; i++){
    scanf("%lld", &a[i]);
    while(a[i] % 2 == 0){
      a[i] /= 2;
      c++;
    }
  }

  printf("%lld\n", c);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &N);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &a[i]);
     ^