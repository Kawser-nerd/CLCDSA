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

char in[110][110];
char cs[5]="<^>v";
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int n,m;
inline int find(char c){
  REP(i,4)if(c==cs[i])return i;
  while(1)puts("QQ find");
}
inline bool goout(int x,int y,int k){
  x+=dx[k];
  y+=dy[k];
  while(x>=0&&x<n&&y>=0&&y<m){
    if(in[x][y]!='.')return 0;
    x+=dx[k];y+=dy[k];
  }
  return 1;
}
inline int solve(){
  int ans=0;
  REP(i,n){
    REP(j,m){
      if(in[i][j]=='.')continue;
      int k=find(in[i][j]);
      if(goout(i,j,k)){
        bool f=1;
        REP(z,4){
          if(!goout(i,j,z)){
            f=0;break;
          }
        }
        if(f)return -1;
        ans++;
      }
    }
  }
  return ans;
}
int main(){
  CASET{
    RII(n,m);
    REP(i,n)RS(in[i]);
    int r=solve();
    printf("Case #%d: ",cas++);
    if(r==-1)puts("IMPOSSIBLE");
    else PI(r);
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

