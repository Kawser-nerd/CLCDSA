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

int n;
char in[501000];
LL f;
void input() {
  RI(n);
  int a,b;
  scanf("%d.%d",&a,&b);
  f=a*1000000+b;
  RS(in);
}

LL ai[501000];
struct XD{
  LL x,y;
  bool operator<(const XD& b)const{
    return y==b.y?x>b.x:y>b.y;
  }
  XD operator-(const XD& b)const{
    return XD{x-b.x,y-b.y};
  }
  LL operator^(const XD& b){
    return x*b.y-y*b.x;
  }
};
XD v[501000];

struct frac{//x/y   y>0
  LL x,y;
  bool operator>(const frac& b)const{
    return x*b.y>y*b.x;
  }
  bool operator==(const frac& b)const{
    return x*b.y==y*b.x;
  }
};
int stk[501000],sc;

LL area(XD& a,XD& b,XD& c){
  return (b-a)^(c-a);
}

void solve() {
  ai[0]=0;
  REP1(i,1,n){
    ai[i]=ai[i-1]+(in[i-1]=='1');
  }
  REP1(i,0,n)ai[i]=1000000LL*ai[i]-f*i;
  int mi=-1;
  frac mans;
  REP(tmt,2){
    REP1(i,0,n){
      v[i].x=i;
      v[i].y=tmt?ai[i]:-ai[i];
    }
    sort(v,v+n+1);
    sc=0;
    REP1(i,0,n){
      while(sc>0&&v[stk[sc-1]].x<v[i].x)sc--;
      while(sc>1&&area(v[i],v[stk[sc-2]],v[stk[sc-1]])>=0)sc--;
      //printf("i=%d %lld %lld %d:",i,v[i].x,v[i].y,sc);
      //REP(j,sc)printf("(%lld %lld) ",v[stk[j]].x,v[stk[j]].y);puts("");
      if(sc>0){
        //printf("i=%d sc=%d %lld %lld\n",i,sc,v[i].x,v[i].y);
        frac ans{v[stk[sc-1]].y-v[i].y,v[stk[sc-1]].x-v[i].x};
        if(mi==-1||mans>ans||(mans==ans&&mi>v[i].x)){
          mi=v[i].x;
          mans=ans;
        }
      }
      stk[sc++]=i;
    }
  }
  printf("%d\n",mi);
}

int main( int argc, char *argv[] ) {
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

