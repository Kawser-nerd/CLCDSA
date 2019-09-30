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

int n,k;
int sum[1010];
int ui[110],di[110];
int eds[10100][3],ec;
LL dis[110];
const LL INFLL=1234567890123456LL;
inline bool solve(int r){
  ec=0;
  REP(i,k){
    REP(j,k){
      if(i==j)continue;
      eds[ec][0]=j;
      eds[ec][1]=i;
      eds[ec][2]=r-ui[i]-di[j];
      //printf("e%d <= e%d + %d\n",eds[ec][1],eds[ec][0],eds[ec][2]);
      ec++;
    }
  }
  dis[0]=0;
  REP1(i,1,k-1)dis[i]=INFLL;
  REP(i,k){
    REP(t,ec){
      if(dis[eds[t][1]]>dis[eds[t][0]]+eds[t][2]){
        dis[eds[t][1]]=dis[eds[t][0]]+eds[t][2];
      }
    }
  }
  REP(t,ec){
    if(dis[eds[t][1]]>dis[eds[t][0]]+eds[t][2]){
      return 0;
    }
  }
  assert(dis[0]==0);
 // printf("r=%d\n",r);
  //REP(i,k)printf("dis[%d]=%d\n",i,dis[i]);
  LL maxd=0;
  REP(i,k)maxd+=dis[i];
  MS0(dis);
  dis[0]=0;
  REP1(i,1,k-1)dis[i]=-INFLL;
  REP(i,k){
    REP(t,ec){
      if(dis[eds[t][0]]<dis[eds[t][1]]-eds[t][2]){
        dis[eds[t][0]]=dis[eds[t][1]]-eds[t][2];
      }
    }
  }
  assert(dis[0]==0);
  LL mind=0;
  REP(i,k)mind+=dis[i];
  
  //printf("* r=%d\n",r);
  //REP(i,k)printf("dis[%d]=%d\n",i,dis[i]);
  if(mind>sum[0]){
    LL d=((mind-sum[0]+k-1)/k);
    mind-=k*d;
    maxd-=k*d;
  }
  if(mind+k<=sum[0]){
    LL d=(sum[0]-mind-k)/k;
    mind+=k*d;
    maxd+=k*d;
  }
  //while(mind>sum[0]){mind-=k;maxd-=k;}
  //while(mind+k<=sum[0]){mind+=k;maxd+=k;}
  return mind<=sum[0]&&maxd>=sum[0];
}
int main(){
  CASET{
    RII(n,k);
    REP(i,n-k+1)RI(sum[i]);
    int l=0,r=1000000000;
    REP(i,k){
      int u=0,d=0,c=0;
      for(int j=i;j+k<n;j+=k){
        c+=sum[j+1]-sum[j];
        u=max(u,c);
        d=min(d,c);
      }
      ui[i]=u;di[i]=-d;
      l=max(l,ui[i]+di[i]);
    }
    while(l<r){
      int m=(l+r)/2;
      if(solve(m))r=m;
      else l=m+1;
    }
    fprintf(stderr,"Case #%d: %d\n",cas,l);
    printf("Case #%d: %d\n",cas++,l);
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

