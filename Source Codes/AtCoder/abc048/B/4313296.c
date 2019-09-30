#include <stdio.h>

int main(void){
  long long  a,b,x;
  long long ans = 0;
  scanf("%lld%lld%lld",&a,&b,&x);

  ans += b/x+1;
  if(a != 0) ans -= (a-1)/x+1;

  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&a,&b,&x);
   ^