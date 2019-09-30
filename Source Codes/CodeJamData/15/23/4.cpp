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

vector<PII> in;
struct XD{
  int c;
  LL val;
  LL base;
  bool operator<(const XD& b)const{
    return val>b.val;
  }
  bool operator==(const XD& b)const{
    return val==b.val;
  }
  void print(const char* s="")const{
    printf("%s c=%d val=%lld\n",s,c,val);
  }
};
inline int solve(){
  int n=SZ(in);
  int curm=n,curp=0;
  int ans=curm+curp;
  priority_queue<XD> p;
  REP(i,n)p.push({1,in[i].first*(LL)in[i].second,360LL*in[i].second});
  while(curp<=2*n){
    XD r=p.top();
//    r.print("r:");
    p.pop();
    XD rr=r;
    if(rr.c==1)curm--;
    else curp++;
    rr.c++;
    rr.val+=rr.base;
    p.push(rr);
    while(p.top()==r){
      XD s=p.top();
//      s.print("s:");
      p.pop();
      if(s.c==1)curm--;
      else curp++;
      s.c++;
      s.val+=s.base;
      p.push(s);
    }
    ans=min(ans,curm+curp);
  }
  return ans;
}
int main(){
  CASET{
    DRI(n);
    in.clear();
    while(n--){
      DRIII(d,h,m);
      d=360-d;
      REP(i,h)in.push_back({d,m+i});
    }
    printf("Case #%d: %d\n",cas++,solve());
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

