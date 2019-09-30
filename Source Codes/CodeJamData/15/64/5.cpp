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

const int MAXN=310;
#define MAXVN (MAXN+2) // define as needed: # of nodes in graph
const int dist_inf=1000000000;
const int flow_inf=1000000000;
// dist_inf has to be appropriately initialized: at least MAXVN for example
// flow_inf has to be appropriately initialized: at least 10^8 for example

class Arc {
  public:
    int to,revind;
    int cap,flow;
    Arc(int _to,int _revind,int _cap):to(_to),revind(_revind),cap(_cap),flow(0) {}
};

class DinicFlow {
  public:
    /* initialize the following using constructor and append */
    int vn,src,sink;
    vector<Arc> adj[MAXVN];
    /* helper variables */
    int dist[MAXVN];
    int ql,qr,que[MAXVN];
    int iter[MAXVN];
    /* primary functions */
    DinicFlow(int _vn,int _src,int _sink):vn(_vn),src(_src),sink(_sink) {}
    void append(int v,int u,int c) {
      int vid=adj[v].size(),uid=adj[u].size();
      adj[v].push_back(Arc(u,uid,c));
      adj[u].push_back(Arc(v,vid,0));
    }
    void bfs_layer() {
      ql=qr=0;
      for(int i=0;i<vn;i++)
        dist[i]=dist_inf;
      que[qr++]=src;
      dist[src]=0;
      while(ql<qr) {
        int v=que[ql++];
        for(int i=0;i<(int)adj[v].size();i++) {
          int u=adj[v][i].to;
          int res=adj[v][i].cap-adj[v][i].flow;
          if(dist[u]<dist_inf) continue;
          if(!res) continue;
          que[qr++]=u;
          dist[u]=dist[v]+1;
        }
      }
    }
    int dfs_push(int v,int a) {
      if(v==sink) return a;
      int pushed=0;
      for(int &i=iter[v];i<(int)adj[v].size();i++) {
        int u=adj[v][i].to;
        int res=adj[v][i].cap-adj[v][i].flow;
        if(dist[u]!=dist[v]+1) continue;
        if(!res) continue;
        int ri=adj[v][i].revind;
        int pf=dfs_push(u,min(a-pushed,res));
        adj[v][i].flow+=pf;
        adj[u][ri].flow-=pf;
        pushed+=pf;
        if(pushed==a) break;
      }
      return pushed;
    }
    int push_flow() {
      bfs_layer();
      for(int i=0;i<vn;i++)
        iter[i]=0;
      return dfs_push(src,flow_inf);
    }
    int maxflow() {
      // O(mn^2) in general graph
      // good complexity in bipartite / unit-capcity graph
      int f=0;
      while(1) {
        int pf=push_flow();
        if(!pf) break;
        f+=pf;
      }
      return f;
    }
    /* selective functions */
    vector<PII> mincut() {
      // must run maxflow() first
      // will return the mincut "closest" to src
      bfs_layer();
      vector<PII> cut;
      for(int v=0;v<vn;v++) {
        for(int i=0;i<(int)adj[v].size();i++) {
          int u=adj[v][i].to;
          if(dist[v]<dist_inf&&dist[u]==dist_inf) cut.push_back(make_pair(v,u));
        }
      }
      return cut;
    }
    vector<int> srccut() {
      bfs_layer();
      vector<int> vs;
      for(int v=0;v<vn;v++)
        if(dist[v]<dist_inf) vs.push_back(v);
      return vs;
    }
    vector<int> sinkcut() {
      bfs_layer();
      vector<int> vs;
      for(int v=0;v<vn;v++)
        if(dist[v]==dist_inf) vs.push_back(v);
      return vs;
    }
    bool mincut_is_isolated_sink() {
      // return whether cut is {sink} -- {V\sink}
      // useful for handling binary search problems where you don't
      // want the sink to be the only node at one side of the cut
      return sinkcut().size()==1;
    }
};


int n,m,k;
vector<int> ed[110];
void input() {
  RI(n,m,k);
  REP(i,n)ed[i].clear();
  REP(i,m){
    DRI(x,y);
    ed[x].push_back(y);
    ed[y].push_back(x);
  }
}

#define LEFT(i) (i)
#define RIGHT(i) ((i)+n)

int dis[110];
int que[110],qs,qe;
inline int bfs(){
  MS1(dis);
  qs=qe=0;
  que[qe++]=0;
  dis[0]=0;
  while(qs<qe){
    int np=que[qs++];
    for(int y:ed[np]){
      if(dis[y]==-1){
        dis[y]=dis[np]+1;
        que[qe++]=y;
      }
    }
  }
  return dis[n-1];
}

void solve() {
  DinicFlow df(n*2,RIGHT(0),LEFT(n-1));
  int ans=bfs();
  REP(i,n){
    if(i!=0)df.append(LEFT(i),RIGHT(i),1);
    for(int y:ed[i])if(dis[y]==dis[i]+1){
      df.append(RIGHT(i),LEFT(y),100000);
    }
  }
  k--;
  int mf=df.maxflow();
//  printf("bfs=%d mf=%d k=%d\n",ans,mf,k);
  ans+=mf>k?1:2;
  printf("%d\n",ans);
}

int main( int argc, char *argv[] ) {
  DRI(n_case);
  REP1(i,1,n_case) {
    input();
    if ( argc==2 && atoi(argv[1])!=i ) continue;
    // if(argc==2){
    // printf("%d %d %d\n",n,m,k);
    // REP(x,n){
    // for(int y:ed[x])if(y>x)printf("%d %d\n",x,y);
    // }
    // }
    printf("Case #%d: ",i);
    solve();
    fflush(stdout);
  }
  return 0;
}

// vim: fdm=marker:commentstring=\ \"\ %s:autoread

