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
#include<omp.h>
int n=1000;
inline LL mrand(){
  return rand()*(LL)RAND_MAX+rand();
}
void bad(vector<int>& a){
  a.resize(n);
  REP(i,n)a[i]=i;
  REP(i,n){
    int p=mrand()%n;
    swap(a[i],a[p]);
  }
}
void good(vector<int>& a){
  a.resize(n);
  REP(i,n)a[i]=i;
  random_shuffle(a.begin(),a.end());
}
inline double sq(double x){return x*x;}

int cnt[1010][1010];

int tre[1010];
inline void add(int x){
  for(;x<=n;x+=x&-x)tre[x]++;
}
inline int que(int x){
  int r=0;
  for(;x>0;x-=x&-x)r+=tre[x];
  return r;
}

inline int inv(const vector<int>& v){
  MS0(tre);
  int r=0;
  REP(i,n){
    r+=que(v[i]+1);
    add(v[i]+1);
  }
  return r;
}
inline double f(const vector<int>& v){
  double r=0;
  REP(i,SZ(v)-1){
    r+=fabs(v[i]-i);
    if(v[i]==0)continue;
    r+=(v[i]-(i+1)+(n-1))%(n-1);
  }
  return r;
}

int main(int, char*[]){
  CASET{
    RI(n);
    vector<int> v;
    REP(i,n){
      DRI(a);
      v.push_back(a);
    }
    printf("Case #%d: ",cas++);
    if(f(v)>811251)puts("GOOD");
    else puts("BAD");
  }
  /*
  int tt=100000;
  double s1=0, s2=0;
  vector<double> r1(tt), r2(tt);
#pragma omp parallel for
  REP(t,tt){
    vector<int> a,b;
    good(a);
    bad(b);
    double v1=f(a);
    double v2=f(b);
    REP(i,n){
      v1+=fabs(a[i]-i);
    }
    REP(i,n){
      v2+=fabs(b[i]-i);
    }
    r1[t]=v1;r2[t]=v2;
#pragma omp critical
    {
      s1+=v1;
      s2+=v2;
    }
  }
  sort(r1.begin(), r1.end());
  sort(r2.begin(), r2.end());
  int c1=0,c2=0;
  int cw=1000000000;
  double mth, mw, v;
  while(c1<SZ(r1)||c2<SZ(r2)){
    if(c1==SZ(r1)||(c2<SZ(r2)&&r1[c1]>r2[c2])){
      v=r2[c2];
      c2++;
    } else{
      v=r1[c1];
      c1++;
    }
    if(cw>c1+(tt-c2)){
      cw=c1+(tt-c2);
      mth=v;mw=-1;
    }
    if(cw>(tt-c1)+c2){
      cw=tt-c1+c2;
      mth=v;mw=1;
    }
  }
  printf("%f %f %f %f %d\n",s1/tt,s2/tt,cw/(double)tt, mth, (int)mw);
  */
  //  REP(i,n)printf("%d(%d) ",cnt[0][i],i);
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

