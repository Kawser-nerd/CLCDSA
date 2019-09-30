#include <stdio.h>

long min(long a,long b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  long N,K;
  scanf("%ld%ld",&N,&K);

  long a;
  long sum[N+1];
  long long ans = 0;
  sum[0] = 0;
  for(long i = 1;i <= N;i++){
    scanf("%ld",&a);
    if(i != 1)
      sum[i] = sum[i-1]+a;
    else
      sum[i] = a;
  }
  for(int i = 0;i < N-K+1;i++){
    ans += sum[i+K]-sum[i];
  }

  printf("%lld\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld",&N,&K);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&a);
     ^