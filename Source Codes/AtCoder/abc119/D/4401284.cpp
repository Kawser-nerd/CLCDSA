/*
How to lambda
  ex) sort(ALL(cont),[](dat a,dat b){return a.l<b.l;});
lower_bound/upper_bound
  1 2 2 2 3 3 
    ^lb   ^ub */
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#define BR "\n"
#define REP(i,n) for(int (i)=0;(i)<(n);++(i))
#define ALL(cont) begin(cont),end(cont)
#define AS_MOD(a,b) ((((a) % (b) ) + (b)) % (b))
#define FEACH(it,cont) for(auto (it) = begin(cont); it!=end(cont);++it)
#define FEACHR(it,cont) for(auto (it) = rbegin(cont); it!=rend(cont);++it)
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define getll() ([](){ll s;scanf("%lld", &s);return s;})()
#define getld() ([](){ld s;scanf("%Lf", &s);return s;})()
#define prl(P) printf("%lld", P)
#define prd(P) printf("%.10Lf", P)
#define pr(P) printf(P)
#define assign_if_greater(V, T) V=max(V,T)
using namespace std;
typedef long long ll;
typedef long double ld;
int A,B,Q;
ll As[100000];
ll Bs[100000];
ll INF=(ll)1000*1000*1000*1000;
ll fastGet() {
  ll ret=0;
  char c=getchar_unlocked();
  // skipping
  while(c<'0' || c > '9') c=getchar_unlocked();
  do {
    ret *= 10;
    ret += (c-'0');
    c = getchar_unlocked();
  } while(c>='0' && c<='9');
  return ret;
}
int main() {
  A=fastGet();
  B=fastGet();
  Q=fastGet();
  REP(i,A)
    As[i]=fastGet();
  REP(i,B)
    Bs[i]=fastGet();
  REP(i,Q) {
    ll x=fastGet();
    ll* ita=lower_bound(As, As+A, x);
    ll* itb=lower_bound(Bs, Bs+B, x);
    ll ans=INF;
    ll alis[2],blis[2];
    alis[0]=ita!=As+A?*ita:INF;
    blis[0]=itb!=Bs+B?*itb:INF;
    alis[1]=ita!=As?ita[-1]:-INF;
    blis[1]=itb!=Bs?itb[-1]:-INF;
    for(ll a:alis)
      for(ll b:blis) {
        ans = min(ans,abs(a-x)+abs(b-a));
        ans = min(ans,abs(b-x)+abs(b-a));
      }
    printf("%lld\n",ans);
  }
  return 0;
}