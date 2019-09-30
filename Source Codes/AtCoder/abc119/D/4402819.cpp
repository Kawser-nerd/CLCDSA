/*
How to lambda
  ex) sort(ALL(cont),[](dat a,dat b){return a.l<b.l;});
lower_bound/upper_bound of 2
  1 2 2 2 3 3 
    ^lb   ^ub */
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
using namespace std;
typedef long long ll;
typedef long double ld;
int A,B,Q;
ll As[100000+10];
ll Bs[100000+10];
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
char buf[1<<25];
int p=0;
inline char my_get_char() {
  return buf[p++];
}
#define getchar_unlocked my_get_char
ll fastGet() {
  ll ret=0;
  char c=getchar_unlocked();
  // skipping
  while(c<'0' || c > '9') c=getchar_unlocked();
  do {
    ret = (ret<<3)+(ret<<1);
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
  fread(buf,1,sizeof(buf),stdin);
  A=fastGet();
  B=fastGet();
  Q=fastGet();
  As[0]=-INF;
  Bs[0]=-INF;
  As[A+1]=INF;
  Bs[B+1]=INF;
  REP(i,A)
    As[i+1]=fastGet();
  REP(i,B)
    Bs[i+1]=fastGet();
  REP(i,Q) {
    ll x=fastGet();
    ll* ita=lower_bound(As, As+A, x);
    ll* itb=lower_bound(Bs, Bs+B, x);
    ll ans=INF;
    ll alis[2],blis[2];
    alis[0]=*ita;
    blis[0]=*itb;
    alis[1]=ita[-1];
    blis[1]=itb[-1];
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