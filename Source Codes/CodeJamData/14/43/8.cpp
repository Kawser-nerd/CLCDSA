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

int w,h,n;
struct XD{
  int x0,y0,x1,y1;
  XD(int xx0=0,int yy0=0,int xx1=0,int yy1=0):x0(xx0),x1(xx1),y0(yy0),y1(yy1){}
  inline void input(){
    RII(x0,y0);
    RII(x1,y1);
  }
} bs[1010];
int dis[1010][1010];
inline bool inter(int a0,int a1,int b0,int b1){
  return min(a1,b1)>=max(a0,b0);
}
inline int calcd(XD a,XD b){
  if(inter(a.x0,a.x1,b.x0,b.x1)){
    if(a.y0>b.y1)return a.y0-b.y1-1;
    else return b.y0-a.y1-1;
  }
  if(inter(a.y0,a.y1,b.y0,b.y1)){
    if(a.x0>b.x1)return a.x0-b.x1-1;
    else return b.x0-a.x1-1;
  }
  int xd,yd;
  if(a.x0>b.x1)xd=a.x0-b.x1-1;
  else if(b.x0>a.x1)xd=b.x0-a.x1-1;
  else puts("QQ");
  if(a.y0>b.y1)yd=a.y0-b.y1-1;
  else if(b.y0>a.y1)yd=b.y0-a.y1-1;
  else puts("QQ");
  return max(xd,yd);
}
LL ans[1010];
const LL INFLL=12345678901234567LL;
int main(){
  CASET{
    RIII(w,h,n);
    REP(i,n)bs[i].input();
    bs[n]=XD(-1,0,-1,h-1);
    bs[n+1]=XD(w,0,w,h-1);
    n+=2;
    REP(i,n)REP(j,n)dis[i][j]=(i==j?0:calcd(bs[i],bs[j]));
    REP(i,n)ans[i]=INFLL;
    ans[n-2]=0;
    priority_queue<pair<LL, int> > que;
    que.push(MP(0,n-2));
    while(!que.empty()){
      pair<LL,int> t=que.top();
      que.pop();
      if(ans[t.second]!=-t.first)continue;
      int np=t.second;
      REP(i,n){
        if(ans[i]>ans[np]+dis[np][i]){
          ans[i]=ans[np]+dis[np][i];
          que.push(MP(-ans[i],i));
        }
      }
    }
    printf("Case #%d: %I64d\n",cas++,ans[n-1]);
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

