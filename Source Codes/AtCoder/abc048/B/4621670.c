#include <stdio.h>

int main(){
  long long int a,b,x;
  scanf("%lld%lld%lld", &a, &b, &x);
  long long int ans = ((b + x) / x) - ((a - 1 + x) / x);
  printf("%lld\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld", &a, &b, &x);
   ^