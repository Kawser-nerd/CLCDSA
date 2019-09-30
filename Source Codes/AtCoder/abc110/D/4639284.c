#include <stdio.h>
#define mod 1000000007

long long calc(long long a,long long b){
  if(b == 0) return 1;
  if(b%2 == 0){
    long long d = calc(a,b/2);
    return (d*d)%mod;
  }
  return (a*calc(a,b-1))%mod;
}

long long comb(long long n,long long r){
  long long tmp = 1,ttmp = 1;
  for(int i = n;i >= n-r+1;i--) tmp = (tmp*i)%mod;
  for(int i = 1;i <= r;i++) ttmp = (ttmp*i)%mod;
  return (tmp*calc(ttmp,mod-2))%mod;
}

int main(void){
  int N,M;
  scanf("%d%d",&N,&M);

  int insu[100000];
  for(int i = 0;i < 100000;i++) insu[i] = 0;

  int cnt = 0;
  for(int i = 2;i*i <= M;i++){
    if(M%i == 0){
      while(M%i == 0){
        insu[cnt]++;
        M /= i;
      }
      cnt++;
    }
  }
  if(M > 1) insu[cnt]++;

  long long ans = 1;
  for(int i = 0;i <= cnt;i++){
    ans *= comb(insu[i]+N-1,insu[i]);
    ans %= mod;
  }

  printf("%lld\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^