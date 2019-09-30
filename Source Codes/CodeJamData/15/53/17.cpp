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

int y;
int n;
double pi[30],si[30],vi[30];
double* dp[25];
int lg2[40000000];
vector<PII> que;
const double INF=1e40;
int main(int argc,char* argv[]){
  REP(i,25)lg2[1<<i]=i;
  int t;
  scanf("%d",&t);

  int casl,casr;
  if(argc==1){
    casl=1;casr=t;
  }else{
    casl=atoi(argv[1]);
    casr=atoi(argv[2]);
  }
  for(int cas=1;cas<=t;cas++){
    RI(y);
    RI(n);
    REP(i,n)scanf("%lf",&pi[i]);
    REP(i,n){
      scanf("%lf",&si[i]);
      vi[i]=pi[i]<0?-si[i]:si[i];
    }
    if(!(cas>=casl&&cas<=casr))continue;
    REP(i,n){
      dp[i]=new double[1<<n];
      REP(j,1<<n)dp[i][j]=INF;
    }
    que.clear();
    que.push_back({0,-1});

    int qs=0;
    while(qs<SZ(que)){
      PII p=que[qs++];
      int st=p.first;
      double pos,t;
      if(p.second==-1){
        pos=0;
        t=0;
      }else{
        t=dp[p.second][st];
        pos=pi[p.second]+vi[p.second]*t;
      }
      double lp=INF,rp=INF;
      int lid=-1,rid=-1;
      REP(i,n){
        if(st&(1<<i))continue;
        double dp=(pi[i]+vi[i]*t);
        if(dp>=pos){
          double dt=(dp-pos)/(y-si[i]);
          if(dt<rp){
            rp=dt;
            rid=i;
          }
        }else{
          double dt=(pos-dp)/(y-si[i]);
          if(dt<lp){
            lp=dt;
            lid=i;
          }
        }
      }
      if(lid!=-1){
        int nst=st|(1<<lid);
        if(dp[lid][nst]>t+lp){
          if(dp[lid][nst]==INF){
            que.push_back({nst,lid});
          }
          dp[lid][nst]=t+lp;
        }
      }
      if(rid!=-1){
        int nst=st|(1<<rid);
        if(dp[rid][nst]>t+rp){
          if(dp[rid][nst]==INF){
            que.push_back({nst,rid});
          }
          dp[rid][nst]=t+rp;
        }
      }
    }
    double ans=INF;
    REP(i,n)ans=min(ans,dp[i][(1<<n)-1]);

    fprintf(stderr,"Case #%d: %.10f\n",cas,ans);
    printf("Case #%d: %.10f\n",cas,ans);
    REP(i,n)delete[] dp[i];
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread


