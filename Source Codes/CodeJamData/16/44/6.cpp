// @author peter50216
// lots of default code (especially dump/R/W) borrowed from shik, thanks!
// #includes {{{
#include <bits/stdc++.h>
using namespace std;
// }}}
// {{{ custom namespace, to avoid name collision.
// stupid macro so that vim doesn't get one more indent...
#define MYSPACE namespace zone_of_peter50216{
#define MYSPACE_END }

MYSPACE
// }}}
// #defines & template magics {{{
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define REP(i,n) for (int i=0; i<(n); i++ )
#define REP1(i,a,b) for (int i=(a); i<=(b); i++ )
#define PER(i,n) for (int i=(n)-1; i>=0; i--)
#define PER1(i,a,b) for (int i=(a); i>=(b); i--)
#define FOR(it,c) for (auto it=(c).begin(); it!=(c).end(); it++)
#define MS0(x) memset(x,0,sizeof(x))
#define MS1(x) memset(x,-1,sizeof(x))
#define SEP(x) ((x)?'\n':' ')
using namespace std;
typedef int64_t LL;
typedef uint64_t ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;

#ifdef SHIK
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
} while (0)

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
template<typename T, size_t N>
ostream& operator <<( ostream &s, const array<T,N> &c ) { return _out(s,ALL(c)); }
template<typename T>
ostream& operator <<( ostream &s, const set<T> &c ) { return _out(s,ALL(c)); }
template<typename A, typename B>
ostream& operator <<( ostream &s, const map<A,B> &c ) { return _out(s,ALL(c)); }
#else
#define dump(...)
#endif

template<typename T>
void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
void _R( int64_t &x ) { scanf("%" PRId64,&x); }
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }

void R() {}
template<typename T, typename... U>
void R( T& head, U&... tail ) {
  _R(head);
  R(tail...);
}

#define DRI(...) int __VA_ARGS__; R(__VA_ARGS__)
#define CASET DRI(t);for(int cas=1;cas<=t;cas++)

template<typename T>
void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
template<typename T>
void _W( const vector<T> &x ) {
  for ( auto i=x.cbegin(); i!=x.cend(); i++ ) {
    if ( i!=x.cbegin() ) putchar(' ');
    _W(*i);
  }
}

void W() {}
template<typename T, typename... U>
void W( const T& head, const U&... tail ) {
  _W(head);
  putchar(sizeof...(tail)?' ':'\n');
  W(tail...);
}

inline string ssprintf(const char* format, ...) {
  static char buf[1000000]; // who cares about buffer overflow :P
  va_list args;
  va_start(args, format);
  vsprintf(buf, format, args);
  va_end(args);
  return buf;
}

// }}}
//
int in[30];
int n;
int getl(){
  char s[30];
  R(s);
  int r=0;
  int l=strlen(s);
  REP(i,l){
    r=r*2+s[i]-'0';
  }
  return r;
}
int pre[30];
bool vis[30];
int cur[30],cc;
void dfs(int np){
  if(vis[np])return;
  vis[np]=1;
  cur[cc++]=np;
  REP(i,n){
    if(in[i]&in[np])dfs(i);
  }
}
PII vv[30];
inline void operator+=(PII& a,const PII& b){
  a.first+=b.first;
  a.second+=b.second;
}
PII ps[70000];
const int INF=1000000000;
int dp[26][26][70000];
inline int p2(int x){return x*x;}
inline int dpf(int c0,int c1,int st){
  int &d=dp[c0][c1][st];
  if(d!=-1)return d;
  if(st==0){
    assert(c0==c1);
    d=c0;
  }else{
    d=INF;
    int sst;
    for(sst=st;sst;sst=(sst-1)&st){
      PII v=ps[sst];
      int cc0=c0,cc1=c1;
      if(v.first<v.second)cc0-=v.second-v.first;
      else cc1-=v.first-v.second;
      if(cc0<0||cc1<0)continue;
      d=min(d,dpf(cc0,cc1,st-sst)+p2(max(v.first,v.second)));
    }
  }
  return d;
}
int main() {
  CASET{
    R(n);
    REP(i,n)in[i]=getl();
    MS0(vis);
    int c0=0,c1=0;
    int vc=0;
    int shik=0;
    REP(i,n)shik|=in[i];
    c1=n-__builtin_popcount(shik);
    int cv=0;
    int ans=0;
    REP(i,n){
      if(vis[i])continue;
      cc=0;dfs(i);
      int v=0;
      REP(j,cc)v|=in[cur[j]];
      int bc=__builtin_popcount(v);
      if(bc==0)c0++;
      else{
        REP(j,cc)ans+=bc-__builtin_popcount(in[cur[j]]);
        if(cc!=bc){
          cv+=bc*cc;
          vv[vc++]={cc,bc};
        }
      }
    }
    MS1(dp);
    REP(i,(1<<vc))ps[i]={0,0};
    REP(i,n)REP(j,(1<<vc))if(j&(1<<i))ps[j]+=vv[i];
    dump(ans,cv,c0,c1,vector<PII>(vv,vv+vc));
    printf("Case #%d: %d\n",cas,ans+dpf(c0,c1,(1<<vc)-1)-cv);
  }
  return 0;
}

// {{{ END
MYSPACE_END
int main() { return zone_of_peter50216::main(); }
// }}}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

