#include<stdio.h>

int main(){
  long long N, p = 1;
  scanf("%lld", &N);
  
  for (int i = 1; i <= N; i++){
    p *= i;
    p = p%1000000007;
  }
  
  printf("%lld\n", p);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &N);
   ^