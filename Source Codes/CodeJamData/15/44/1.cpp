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

const int mod=1000000007;

inline int add(int a,int b){
  a+=b;
  if(a>=mod)a-=mod;
  return a;
}
inline int mul(int a,int b){
  return (a*(LL)b)%mod;
}
inline int inv(int a,int b){
  if(a==1)return 1;
  LL x=((1-b*(LL)inv(b%a,a))/a)%b;
  if(x<0)x+=b;
  return x;
}
inline int divm(int a,int b){
  return mul(a,inv(b,mod));
}
inline int lcm(int a,int b){
  return a*b/__gcd(a,b);
}

int dp[110][110][2][13];
inline int dpf(int m,int n,int last3,int rotdeg){
  int &d=dp[m][n][last3][rotdeg];
  if(d!=-1)return d;
  if(n==0){
    if(rotdeg!=1)return d=0;
    return d=1;
  }
  if(last3){
    if(n<2)return d=0;
    return d=dpf(m,n-2,0,rotdeg);
  }
  d=dpf(m,n-1,1,rotdeg);
  if(n>=2&&m%3==0){
    REP1(r,1,12){
      if(lcm(r,3)==rotdeg)d=add(d,mul(dpf(m,n-2,1,r),3));
    }
  }
  if(n>=2&&m%6==0){
    REP1(r,1,12){
      if(lcm(r,6)==rotdeg)d=add(d,mul(dpf(m,n-2,1,r),6));
    }
  }
  if(n>=3&&m%4==0){
    REP1(r,1,12){
      if(lcm(r,4)==rotdeg)d=add(d,mul(dpf(m,n-3,1,r),4));
    }
  }
  return d;
}

inline int solve(int m,int n){
  int ans=0;
  REP(l,2){
    REP1(r,1,12){
      ans=add(ans,divm(dpf(m,n,l,r),r));
    }
  }
  return ans;
}

int main(){
  MS1(dp);
  CASET{
    DRII(n,m);
    printf("Case #%d: %d\n",cas++,solve(m,n));
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

