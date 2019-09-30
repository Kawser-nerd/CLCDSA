#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  long long N, x, i, ans = 0;

  scanf("%lld%lld", &N, &x);

  long long a[N];

  for(i = 0; i < N; i++){
    scanf("%lld", &a[i]);
  }

  for(i = 1; i < N; i++){
    if(a[i - 1] + a[i] <= x){
      continue;
    }else if(a[i - 1] >= x){
      ans += a[i] + a[i - 1] - x;
      a[i] = 0;
    }else{
      ans += a[i] + a[i - 1] - x;
      a[i] = x - a[i - 1];
    }
  }

  printf("%lld\n", ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &N, &x);
   ^
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &a[i]);
     ^