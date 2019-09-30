#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long

int main(){
  ll i,j,k,l,m,n,r,add,st;
  ll in[2000], tm[2000], now[2000];
  ll res;
  ll interval, gain, skip;
  int size,count;

  scanf("%d",&size);
  while(size--){
    scanf("%lld%lld%lld",&r,&k,&n);
    rep(i,n) scanf("%lld",in+i);
    rep(i,n) tm[i]=-1; res=0;

    st=0;
    rep(m,r){
      if(tm[st]>=0){
        interval = m-tm[st]; gain = res-now[st];
        skip = (r-m-1)/interval;
        if(skip>1){
          m += interval*skip;
          res += gain*skip;
        }
      }
      tm[st]=m; now[st]=res;
      add=0;
      rep(i,n){
        if(add+in[st]>k) break;
        add+=in[st]; st=(st+1)%n;
      }
      res+=add;
    }
    printf("Case #%d: %lld\n",++count,res);
  }

  return 0;
}
