#include<stdio.h>
#define MIN(a,b) ((a)>(b)?(b):(a))
int main(){
  long long q,h,s,d,n;
  scanf("%lld%lld%lld%lld%lld",&q,&h,&s,&d,&n);
  s=MIN(s,MIN(h*2,q*4));
  d=MIN(d,s*2);
  printf("%lld",(n/2)*d+(n%2)*s);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld%lld",&q,&h,&s,&d,&n);
   ^