#include<stdio.h>
#define ll long long


ll fibmod(ll n,ll p){
  ll N;
  ll x,y,tx,ty,F0,F1,tF0,tF1,tmp;
  y=0LL;
  x=F0=F1=1LL;
  --n;
  while(n){
    if(n&1){
      tx = x%p;
      ty = y%p;
      tmp=(F1-F0)%p; if (tmp<0)tmp+=p;
      x  = (F1*tx%p+F0*ty%p)%p;
      y  = (F0*tx%p+tmp*ty%p)%p;
    }
    n>>=1;
    tF1=F1%p;
    tF0=F0%p;
    tmp=(F1-F0)%p; if (tmp<0)tmp+=p;
    F1 = (tF1 * tF1 %p + tF0 * tF0 %p)%p;
    F0 = (tF1 * tF0 %p + tF0 * tmp %p)%p;
  }
  return x%p;
}


ll main(){
  ll i,j,a,b,N;
  scanf("%lld",&N);
  for(i=3;N;i+=10){
    if(fibmod(i,i)==i-1){
    printf("%lld ",i);
    --N;
    }
  }
} ./Main.c: In function ‘main’:
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&N);
   ^