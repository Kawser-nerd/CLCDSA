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

LL a[160],b[160];
inline LL rb(){
  char tmp[100];
  RS(tmp);
  LL r=0;
  REPL(i,tmp){
    r=(r*2)+tmp[i]-'0';
  }
  return r;
}
inline int cd(LL x){
  if(x==0)return 0;
  return cd(x/2)+(x%2);
}
int main(){
  CASET{
    DRII(n,l);
    int ans=1000000000;
    REP(i,n)a[i]=rb();
    REP(i,n)b[i]=rb();
    REP(i,n){
      set<LL> s1,s2;
      LL df=a[0]^b[i];
      REP(j,n){
        s1.insert(a[j]);s2.insert(b[j]^df);
      }
      if (s1 == s2)ans=min(ans,cd(df));
    }
    printf("Case #%d: ",cas++);
    if(ans==1000000000)puts("NOT POSSIBLE");
    else printf("%d\n",ans);
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

