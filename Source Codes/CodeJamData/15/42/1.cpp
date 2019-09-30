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

struct XD{
  double r,c;
  void get(){
    scanf("%lf%lf",&r,&c);
  }
  bool operator<(const XD& b)const{
    return c<b.c;
  }
}in[110];
int n;
double v,x;
inline bool solve(double t){
  //printf("t=%f\n",t);
  double mi=0,ma=0;
  double ss;
  ss=v;
  REP(i,n){
    double tt=0;
    if(ss>in[i].r*t){
      tt=t;
      ss-=in[i].r*tt;
      mi+=in[i].r*in[i].c*tt;
    }else{
      tt=ss/in[i].r;
      ss=0;
      mi+=in[i].r*in[i].c*tt;
    }
  }
  if(ss>1e-16)return 0;
  ss=v;
  PER(i,n){
    double tt=0;
    if(ss>in[i].r*t){
      tt=t;
      ss-=in[i].r*tt;
      ma+=in[i].r*in[i].c*tt;
    }else{
      tt=ss/in[i].r;
      ss=0;
      ma+=in[i].r*in[i].c*tt;
    }
  }
  if(ss>1e-16)return 0;
  //printf("mi=%f ma=%f\n",mi,ma);
  return mi<=v*x*(1+1e-14)&&ma>=v*x*(1-1e-14);
}

int main(){
  CASET{
    RI(n);
    scanf("%lf%lf",&v,&x);
    REP(i,n)in[i].get();
    sort(in,in+n);
    double l=0,r=v*20000;
    REP(k,100){
      double m=(l+r)/2;
      if(solve(m))r=m;
      else l=m;
    }
    printf("Case #%d: ",cas++);
    if(solve(r+1))printf("%.10f\n",r);
    else puts("IMPOSSIBLE");
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

