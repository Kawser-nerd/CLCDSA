#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define M 1777777777

ll pw(ll a,ll b, ll md){
  ll r;
  if(!b) return 1;
  r = pw(a,b/2,md);
  r = (r*r)%md;
  if(b%2) r = (r*a)%md;
  return r;
}

ll arr[1000000];

int main(){
  int i, j, K;
  ll N, res;

  scanf("%lld%d\n",&N,&K);

  res = 1;
  rep(i,K){
    res = (res * ((N-i)%M)) % M;
    res = (res * pw(i+1, M-2, M)) % M;
  }

  arr[0] = 1; arr[1] = 0; arr[2] = 1; arr[3] = 2;
  REP(i,4,1000000){
    arr[i] = ((i-1) * ((arr[i-1] + arr[i-2])%M))%M;
  }

  res = (res * arr[K])%M;
  printf("%lld\n",res);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%d\n",&N,&K);
   ^