#include <stdio.h>
#include <stdlib.h>
#define mod 1000000007

long long min(long long a,long long b){
  if(a < b){
    return a;
  }
  return b;
}

long long calc(long long a,long long b){
  if(b == 0) return 1;
  if(b%2 == 0){
    long long d = calc(a,b/2);
    return (d*d)%mod;
  }else{
    return (a*calc(a,b-1))%mod;
  }
}


int main(void){
  long long A,B,C;
  scanf("%lld%lld%lld",&A,&B,&C);

  long long bunbo = (A*C)%mod-(B*C)%mod+(A*B)%mod;
  long long c = (B*C)%mod-(A*B)%mod;
  long long r = (B*C)%mod-(A*C)%mod;
  bunbo = llabs(bunbo);
  c = llabs(c);
  r = llabs(r);

  c *= calc(bunbo,mod-2);
  r *= calc(bunbo,mod-2);

  c = c%mod;
  r = r%mod;
  c = min(c,mod-c);
  r = min(r,mod-r);
  printf("%lld %lld\n",r,c);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&A,&B,&C);
   ^