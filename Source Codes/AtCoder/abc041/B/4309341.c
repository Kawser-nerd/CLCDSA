#include<stdio.h>
int main(){
  long long a,b,c,d=1000000007;
  scanf("%lld%lld%lld",&a,&b,&c);
  printf("%lld",a%d*b%d*c%d);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&a,&b,&c);
   ^