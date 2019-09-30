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

char in[1010000];
void input() {
  RS(in);
}

int n;
int val[1010000];
int far[200][1010000];
int lastn[1010000][10];
inline int dpf(int np,int h){
  int &d=far[h][np];
  if(d!=-1)return d;
  if(np==n){
    // printf("%d %d case 1\n",np,h);
    d=n;
  }else if(h<val[np]){
    // printf("%d %d case 2\n",np,h);
    d=np-1;
  }else{
    // printf("%d %d case 3\n",np,h);
    int mf=np;
    REP1(dd,1,9){
      if(dd>h)break;
      int r=dpf(np,h-dd);
      int s=lastn[min(r+1,n)][dd];
//      printf("   np=%d h=%d dd=%d r=%d s=%d\n",np,h,dd,r,s);
      if(s<np)continue;
      mf=max(mf,dpf(s+1,h-dd));
    }
    d=mf;
  }
  // printf("dpf np=%d h=%d %d\n",np,h,d);
  return d;
}
void solve() {
  n=strlen(in);
  REP(i,n)val[i]=in[i]-'0';
  REP1(i,1,9)lastn[0][i]=-1;
  REP1(i,0,n-1){
    lastn[i][val[i]]=i;
    REP1(j,1,9)lastn[i+1][j]=lastn[i][j];
  }
  MS1(far);
  REP1(i,1,200){
    if(dpf(0,i)>=n){
      printf("%d\n",i);
      return;
    }
  }
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

