#include<stdio.h>
#define min(a,b) ((a)>(b)?(b):(a))

int main(){
  long long a,b,c;
  scanf("%lld%lld%lld",&a,&b,&c);
  printf("%lld",min((a%2)*b*c,min(a*(b%2)*c,a*b*(c%2))));
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&a,&b,&c);
   ^