#include <stdio.h>

long long max(long long a,long long b){
  if(a > b){
    return a;
  }
  return b;
}

long long min(long long a,long long b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  long long N,H;
  long long A,B,C,D,E;
  scanf("%lld%lld",&N,&H);
  scanf("%lld%lld%lld%lld%lld",&A,&B,&C,&D,&E);

  long long ans = 1e18;
  for(long long i = 0;i <= N;i++){
    long long j = max((((N-i)*E-H-B*i)+D+E)/(D+E),0);
    ans = min(ans,i*A+j*C);
  }

  printf("%lld\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&N,&H);
   ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld%lld%lld",&A,&B,&C,&D,&E);
   ^