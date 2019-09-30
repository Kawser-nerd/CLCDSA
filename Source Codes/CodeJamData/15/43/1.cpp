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
#define RI(x) scanf("%d",&x)
#define DRI(x) int x;RI(x)
#define RII(x,y) scanf("%d%d",&x,&y)
#define DRII(x,y) int x,y;RII(x,y)
#define RIII(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define DRIII(x,y,z) int x,y,z;RIII(x,y,z)
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
// }}}


#define MAXVN 5000 // define as needed: # of nodes in graph
const int dist_inf = 5000;
const int flow_inf = 1000000000;
typedef pair<int,int> pii;
// dist_inf has to be appropriately initialized: at least MAXVN for example
// flow_inf has to be appropriately initialized: at least 10^8 for example
 
class Arc {
   public:
      int to,revind;
      int flow,cap;
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
            for(int i=0;i<adj[v].size();i++) {
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
         for(int &i=iter[v];i<adj[v].size();i++) {
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
      vector<pii> mincut() {
         // must run maxflow() first
         // will return the mincut "closest" to src
         bfs_layer();
         vector<pii> cut;
         for(int v=0;v<vn;v++) {
            for(int i=0;i<adj[v].size();i++) {
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

map<string,int> mp;
char tmp[101000];

inline int getid(const string& s){
  if(mp.count(s)==0){
    int ii=mp.size();
    mp[s]=ii;
    return ii;
  }
  return mp[s];
}

inline vector<int> read(){
  gets(tmp);
  stringstream ss;
  ss<<tmp;
  string s;
  vector<int> ret;
  while(ss >> s){
    ret.push_back(getid(s));
  }
  return ret;
}

vector<int> in[210];
int n;
int ans;

int main(){
  CASET{
    mp.clear();
    RI(n);gets(tmp);
    REP(i,n)in[i]=read();
    int w=mp.size();
    set<int> s1,s2;
    for(int x:in[0])s1.insert(x);
    for(int x:in[1])s2.insert(x);
    DinicFlow df(2*w+2,0,2*w+1);
    int c1=0,c2=0;
    REP1(i,1,w){
      if(s1.count(i-1)==0){
        df.append(0,i,1);
      }else c1++;
      if(s2.count(i-1)==0){
        df.append(i+w,2*w+1,1);
      }else c2++;
      df.append(i,i+w,10000000);
    }
    REP1(i,2,n-1){
      for(int x:in[i]){
        for(int y:in[i]){
          if(x==y)continue;
          df.append(x+1,y+w+1,10000000);
        }
      }
    }
    printf("Case #%d: %d\n",cas++,df.maxflow()+c1+c2-w);
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

