#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

const int mod=1777777777;

int *iFact;
void init(int k){
  int fact=1;
  int i;
  for(i=2;i<=k;i++) fact=(int64)fact*i%mod;
  int t=1;
  int a=fact;
  while(a>1){
    t=(int64)t*(mod-mod/a)%mod;
    a=mod%a;
  }
  iFact=(int *)calloc(k+1,sizeof(int));
  iFact[k]=t;
  for(i=k-1;i>=0;i--) iFact[i]=(int64)iFact[i+1]*(i+1)%mod;
}

int64 comb(int64 n,int k){
  int64 res=1;
  for(int i=1;i<=k;i++) res=(n+1-i)%mod*res%mod;
  return res*iFact[k]%mod;
}

int64 way(int k){
  int64 prob=1;
  int i;
  for(i=1;i<=k;i++) prob=(prob+mod+(i&1?-1:1)*iFact[i])%mod;
  for(i=1;i<=k;i++) prob=prob*i%mod;
  return prob;
}

void run(void){
  int64 n;
  int k;
  scanf("%lld%d",&n,&k);
  init(k);
  int64 ans=comb(n,k)*way(k)%mod;
  printf("%lld\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%d",&n,&k);
   ^