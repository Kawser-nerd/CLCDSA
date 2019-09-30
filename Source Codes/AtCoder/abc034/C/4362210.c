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
  int H,W;
  scanf("%d%d",&H,&W);
  H--; W--;
  printf("%lld\n",comb(W+H,W));

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&H,&W);
   ^