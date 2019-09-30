#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

int n,q,a,b;
int x[252521];
const ll INF = 1e18;

const int MAX = 1<<18;
ll dpa[2*MAX];
ll dpb[2*MAX];
void init(){
  REP(i,2*MAX)dpa[i] = INF;
  REP(i,2*MAX)dpb[i] = INF;
}
void set(int x,ll v){
  int p = x+MAX-1;
  dpa[p] = v+x;
  dpb[p] = v-x;
  while(p>0){
    p = (p-1)/2;
    dpa[p] = min(dpa[2*p+1], dpa[2*p+2]);
    dpb[p] = min(dpb[2*p+1], dpb[2*p+2]);
  }
}
ll get(int x){
  return dpa[x+MAX-1]-x;
}
ll qmin(ll data[2*MAX], int l,int r,int a,int b,int k){
  if(b<=l || r<=a)return INF;
  if(l<=a && b<=r)return data[k];
  int m = (a+b)/2;
  return min(qmin(data,l,r,a,m,2*k+1), qmin(data,l,r,m,b,2*k+2));
}

int main(){
  scanf("%d%d%d%d",&n,&q,&a,&b);
  --a;--b;
  x[0] = b;
  REP(i,q)scanf("%d",x+1+i);
  REP(i,q)x[i+1]--;
  init();
  set(a,0);
  ll addall = 0;
  REP(i,q){
    ll diff = x[i+1] - x[i];
    diff = max(diff,-diff);
    ll mn = get(x[i]);
    CHMIN(mn, qmin(dpb,0,x[i+1],0,MAX,0) + x[i+1]-diff);
    CHMIN(mn, qmin(dpa,x[i+1],n,0,MAX,0) - x[i+1]-diff);
    set(x[i],mn);
    addall += diff;
    // DEBUG(mn);
    // REP(i,n)DEBUG(dpa[i+MAX-1]-i);
    // puts("");
  }
  ll ans = INF;
  REP(i,n)CHMIN(ans,get(i));
  printf("%lld\n",ans+addall);
  return 0;
}