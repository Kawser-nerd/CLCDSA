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

int r,c,n;

inline int solve(int t,int c2,int c3,int c4){
  int ret=0;
  c4=min(c4,t);
  ret+=4*c4;t-=c4;
  c3=min(c3,t);
  ret+=3*c3;t-=c3;
  c2=min(c2,t);
  ret+=2*c2;t-=c2;
  assert(t==0);
  return ret;
}

inline int solve(){
  if(r>c)swap(r,c);
  int h=(r*c+1)/2;
  if(n<=h)return 0;
  int tot=r*(c-1)+c*(r-1);
  int todel=r*c-n;
  if(r==1){
    return tot-todel*2;
  }
  if(r%2==1&&c%2==1){
    int ans;
    int c2,c3,c4;
    c2=4;
    c4=((r-2)*(c-2)+1)/2;
    c3=(r*c+1)/2-c2-c4;
    ans=tot-solve(todel,c2,c3,c4);
    c2=0;
    c4=((r-2)*(c-2))/2;
    c3=(r*c)/2-c2-c4;
    ans=min(ans,tot-solve(todel,c2,c3,c4));
    return ans;
  }else{
    int c2,c3,c4;
    c2=2;
    c4=((r-2)*(c-2))/2;
    c3=(r*c)/2-c2-c4;
    return tot-solve(todel,c2,c3,c4);
  }
}

int main(){
  CASET{
    RIII(r,c,n);
    printf("Case #%d: %d\n",cas++,solve());
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

