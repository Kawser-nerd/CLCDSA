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

int n;
vector<int> ed[1010];
inline int run(int np,int p){
  int c=0;
  int m1=0,m2=0;
  REP(i,SZ(ed[np])){
    int y=ed[np][i];
    if(y==p)continue;
    c++;
    int r=run(y,np);
    if(r>m1){m2=m1;m1=r;}
    else if(r>m2)m2=r;
  }
  if(c<=1)return 1;
  return 1+m1+m2;
}
inline int solve(){
  if(n==2)return 1;
  int ans=0;
  REP(i,n){
    if(ed[i].size()==1)continue;
    ans=max(ans,run(i, -1));
  }
  return n-ans;
}
int main(){
  CASET{
    RI(n);
    REP(i,n)ed[i].clear();
    REP(i,n-1){
      DRII(a,b);
      a--;b--;
      ed[a].push_back(b);
      ed[b].push_back(a);
    }
    printf("Case #%d: %d\n",cas++,solve());
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

