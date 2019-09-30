#include <cstdio>
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
#define prl(P) printf("%lld", P)
#define prd(P) printf("%.10Lf", P)
#define pr(P) printf(P)
#define assign_if_greater(V, T) V=max(V,T)
typedef long long ll;
typedef long double ld;
int A,B,Q;
ll As[100000];
ll Bs[100000];
ll INF=(ll)1000*1000*1000*1000;
ll min(ll a, ll b) {
  return a>b? b:a;
}
ll abs(ll a) {
  return a>0?a:-a;
}
ll* lower_bound(ll* a, ll* b, ll v){
  while(b>a+1) {
    ll* m=a+(b-a)/2;
    if(*m >= v) {
      b=m;
    } else {
      a=m;
    }
  }
  return b;
}
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
void fastPut(ll v) {
  char s[256];
  int p=0;
  do {
    s[p++]=(v%10)+'0';
    v/=10;
  } while(v>0);
  while(p--)
    putchar_unlocked(s[p]);
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
    REP(j,2)
      REP(k,2){
        ll a=alis[j],b=blis[k];
        ans = min(ans,abs(a-x)+abs(b-a));
        ans = min(ans,abs(b-x)+abs(b-a));
      }
    fastPut(ans);
    putchar_unlocked('\n');
  }
  return 0;
}