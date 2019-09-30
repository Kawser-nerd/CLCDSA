// @author peter50216
// #includes {{{
#include <bits/stdc++.h>
using namespace std;
// }}}
// #defines {{{
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define REPL(i,x) for(int i=0;x[i];i++)
#define PER(i,n) for(int i=(n)-1;i>=0;i--)
#define PER1(i,a,b) for(int i=(a);i>=(b);i--)
#define DRI(...) int __VA_ARGS__;RI(__VA_ARGS__)
#define RS(x) scanf("%s",x)
#define PI(x) printf("%d\n",x)
#define PIS(x) printf("%d ",x)
#define CASET int ___T,cas=1;scanf("%d ",&___T);while(___T--)
#define CASEN0(n) int cas=1;while(scanf("%d",&n)!=EOF&&n)
#define CASEN(n) int cas=1;while(scanf("%d",&n)!=EOF)
#define MP make_pair
#define PB push_back
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
#define F first
#define S second
#ifdef ONLINE_JUDGE
#define FILEIO(x) freopen(#x ".in","r",stdin);freopen(#x ".out","w",stdout);
#define FILEIOS freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#else
#define FILEIO(x) ;
#define FILEIOS ;
#endif
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

void RI() {}

template<typename... T>
void RI( int& head, T&... tail ) {
  scanf("%d",&head);
  RI(tail...);
}

template<typename T>
void _dump( const char* s, T&& head ) { cerr<<s<<"="<<head<<endl; }

template<typename T, typename... Args>
void _dump( const char* s, T&& head, Args&&... tail ) {
  int c=0;
  while ( *s!=',' || c!=0 ) {
    if ( *s=='(' || *s=='[' || *s=='{' ) c++;
    if ( *s==')' || *s==']' || *s=='}' ) c--;
    cerr<<*s++;
  }
  cerr<<"="<<head<<", ";
  _dump(s+1,tail...);
}

#define dump(...) do { \
  fprintf(stderr, "%s:%d - ", __PRETTY_FUNCTION__, __LINE__); \
  _dump(#__VA_ARGS__, __VA_ARGS__); \
} while (0);

template<typename Iter>
ostream& _out( ostream &s, Iter b, Iter e ) {
  s<<"[";
  for ( auto it=b; it!=e; it++ ) s<<(it==b?"":" ")<<*it;
  s<<"]";
  return s;
}

template<typename A, typename B>
ostream& operator <<( ostream &s, const pair<A,B> &p ) { return s<<"("<<p.first<<","<<p.second<<")"; }
template<typename T>
ostream& operator <<( ostream &s, const vector<T> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
// }}}

int n,x;

void input() {
  RI(n,x);
}
const int mod=1000000007;
int fac[1010000];
int rfac[1010000];
inline int add(int a,int b){
  a+=b;
  if(a>=mod)a-=mod;
  return a;
}
inline int mul(int a,int b){
  return (a*(LL)b)%mod;
}
inline int rev(int a,int b){
  if(a==1)return 1;
  LL z=rev(b%a,a);
  LL ret=((1-z*b)/a)%b;
  if(ret<0)ret+=b;
  return ret;
}
inline int bin(int a,int b){  //C(a,b)
  if(b<0||b>a)return 0;
  return mul(fac[a],mul(rfac[b],rfac[a-b]));
}
int dp[1010000];
int dp2[1010000];

void solve() {
  int ans=0;
  REP1(i,x,n){
    ans=add(ans,mul(mul(bin(n,i),bin(n,i)),mul(dp2[n-i],fac[i])));
//    printf("n=%d x=%d i=%d %d\n",n,x,i,ans);
  }
  printf("%d\n",ans);
}

int main( int argc, char *argv[] ) {
  fac[0]=1;
  rfac[0]=1;
  REP1(i,1,1000000){
    fac[i]=mul(fac[i-1],i);
    rfac[i]=rev(fac[i],mod);
  }
  dp[0]=1;
  dp[1]=0;
  REP1(i,2,1000000){
    dp[i]=add(mul(i-1,dp[i-2]),mul(i-1,dp[i-1]));
  }
  REP1(i,0,1000000){
    dp2[i]=mul(dp[i],fac[i]);
  }
  DRI(n_case);
  REP1(i,1,n_case) {
    input();
    if ( argc==2 && atoi(argv[1])!=i ) continue;
    printf("Case #%d: ",i);
    solve();
    fflush(stdout);
  }
  return 0;
}

// vim: fdm=marker:commentstring=\ \"\ %s:autoread

