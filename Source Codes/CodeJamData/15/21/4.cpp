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

LL p10[20];

char tmp[1000];

LL solve(LL n, int l) {
  int ll=l/2+1;
  LL ret=0;
  if(n<=p10[l]+p10[ll]){
    ret+=n-p10[l]+1;
  }else{
    if(n%10==0){
      n--;ret++;
    }
    sprintf(tmp,"%lld",n);
    for(int i=0,j=l;i<j;i++,j--){
      tmp[j]=tmp[i];
      if(i)tmp[i]='0';
      else tmp[i]='1';
    }
    LL x;
    sscanf(tmp,"%lld",&x);
    ret+=x-p10[l]+1;
    reverse(tmp,tmp+l+1);
    sscanf(tmp,"%lld",&x);
    ret+=n-x+1;
  }
  return ret;
}
LL solve(LL n){
  LL ret=0;
  int l=0;
  while(p10[l+1]<=n){
    ret+=solve(p10[l+1]-1,l);
    l++;
  }
  ret+=solve(n,l);
  return ret;
}

int main(){
  p10[0]=1;
  REP1(i,1,19)p10[i]=p10[i-1]*10;
  CASET{
    LL n;
    scanf("%lld",&n);
    printf("Case #%d: %lld\n",cas++,solve(n));
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

