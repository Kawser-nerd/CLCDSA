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

int n,m;
int in[110][8];
void input() {
  RI(n,m);
  MS0(in);
  REP(i,n){
    REP(j,m)RI(in[i][j]);
  }
}

int totall[8][2];
int now[2];

inline void go(int* c,int* s){
  REP(i,m){
    c[i]+=s[i];
    c[i]=max(0,c[i]);
  }
}
inline int ss(int* c){
  int ret=0;
  REP(i,m)ret+=c[i];
  return ret;
}

int ans;

bool used[8];

inline void dfs(int np){
  if(np==8){
    ans=max(ans,ss(now));
    return;
  }
  REP(i,8){
    if(used[i])continue;
    bool flag=1;
    REP(j,3)if((i&(1<<j))&&!used[i^(1<<j)])flag=0;
    if(!flag)continue;
    int bnow[2];
    REP(j,2)bnow[j]=now[j];
    used[i]=1;
    go(now,totall[i]);
    dfs(np+1);
    used[i]=0;
    REP(j,2)now[j]=bnow[j];
  }
}

void solve() {
  //guessing
  MS0(totall);
  REP(i,n){
    int x=in[i][0],y=in[i][1];
    int c=((x>=0)<<2)+((y>=0)<<1)+(x+y>=0);
    REP(j,m)totall[c][j]+=in[i][j];
  }
  ans=0;
  MS0(now);
  MS0(used);
  dfs(0);
  printf("%d\n",ans);
  if(n<=10){
    int id[20];
    REP(i,n)id[i]=i;
    do{
      MS0(now);
      REP(i,n)go(now,in[id[i]]);
      if(ss(now)>ans){
        fprintf(stderr,"!! wrong answer ans=%d get=%d\n",ans,ss(now));
        REP(i,n)printf("%d ",id[i]);puts("");
        fprintf(stderr,"%d %d\n",n,m);
        REP(i,n){
          REP(j,m)printf("%d%c",in[i][j],SEP(j==m-1));
        }
        break;
      }
    }while(next_permutation(id,id+n));
  }
}

int main( int argc, char *argv[] ) {
  DRI(n_case);
  REP1(c,1,n_case) {
    input();
    if ( argc==2 && atoi(argv[1])!=c ) continue;
    if(argc==2){
      fprintf(stderr, "%d %d\n",n,m);
      REP(i,n){
        REP(j,m)fprintf(stderr,"%d%c",in[i][j],SEP(j==m-1));
      }
    }
    printf("Case #%d: ",c);
    solve();
    fflush(stdout);
  }
  return 0;
}

// vim: fdm=marker:commentstring=\ \"\ %s:autoread

