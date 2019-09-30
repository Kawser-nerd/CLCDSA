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

#include <sys/resource.h>
 
void increase_stack_size() {
   const rlim_t kStackSize = 512 * 1024 * 1024;  // min stack size = 32 MB
   struct rlimit rl;
   int result;
   result = getrlimit(RLIMIT_STACK, &rl);
   if (result == 0)
   {
      if (rl.rlim_cur < kStackSize)
      {
         rl.rlim_cur = kStackSize;
         result = setrlimit(RLIMIT_STACK, &rl);
         if (result != 0)
         {
            fprintf(stderr, "setrlimit returned result = %d\n", result);
         }
      }
   }
}

int n,d;
int si[1010000];
int mi[1010000];
int pre[1010000];
int cnt[1010000];
inline int find(int x){return pre[x]==x?x:pre[x]=find(pre[x]);}
inline void uni(int x,int y){
  x=find(x);y=find(y);
  if(x==y)return;
  pre[x]=y;
  cnt[y]+=cnt[x];
}
bool isin[1010000];
vector<int> ch[1010000];
inline void add(int x){
  //printf("add %d\n",x);
  if(isin[mi[x]])uni(x,mi[x]);
  for(int v:ch[x])if(isin[v])uni(v,x);
  isin[x]=1;
}
int cc;
inline void dfs(int np){
  if(!isin[np])return;
  cc++;
  isin[np]=0;pre[np]=np;
  for(int v:ch[np])dfs(v);
}
inline void del(int x){
  //printf("del %d\n",x);
  int xx=find(x);
  cc=0;
  dfs(x);
  cnt[xx]-=cc;
}
int main(){
  increase_stack_size();
  CASET{
    RII(n,d);
    DRII(s0,as);DRII(cs,rs);
    DRII(m0,am);DRII(cm,rm);
    si[0]=s0;
    mi[0]=m0;
    REP1(i,1,n-1){
      si[i]=(si[i-1]*(LL)as+cs)%rs;
      mi[i]=(mi[i-1]*(LL)am+cm)%rm;
    }
    REP1(i,1,n-1)mi[i]%=i;
   // REP(i,n)printf("mi[%d]=%d %d\n",i,mi[i],si[i]);

    REP(i,n)ch[i].clear();
    REP1(i,1,n-1)ch[mi[i]].push_back(i);
    REP(i,n){pre[i]=i;cnt[i]=1;}
    MS0(isin);
    isin[0]=1;
    vector<PII> small,large;
    REP1(i,1,n-1){
      if(si[i]<=si[0]&&si[i]>=si[0]-d){
        add(i);
        small.push_back({si[i],i});
      }else if(si[i]>si[0]&&si[i]<=si[0]+d){
        large.push_back({si[i],i});
      }
    }
    int ans=cnt[0];
    sort(ALL(small));
    sort(ALL(large));
    small.push_back({si[0],0});
    int j=0;
    REP(i,SZ(small)){
      //puts("===");
      while(j<SZ(large)&&large[j].first<=small[i].first+d){
        add(large[j].second);
        j++;
      }
      ans=max(ans,cnt[0]);
      if(small[i].second)del(small[i].second);
    }
    printf("Case #%d: %d\n",cas++,ans);
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

