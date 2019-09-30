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
int n,m;
string s[1010];
char tmp[110];
const int mod=1000000007;
inline int add(int a,int b){
  a+=b;
  if(a>=mod)a-=mod;
  return a;
}
inline int sub(int a,int b){
  a-=b;
  if(a<0)a+=mod;
  return a;
}
inline int mul(int a,int b){
  return (a*(LL)b)%mod;
}
int bin[1010][1010];
int dh[1010];
inline void update(PII& a,const PII& b,const PII& c,int mp){
  if(a.first>b.first+c.first){
    a.first=b.first+c.first;
    a.second=mul(mp,mul(b.second,c.second));
  }else if(a.first==b.first+c.first){
    a.second=add(a.second,mul(mp,mul(b.second,c.second)));
  }
}
const int INF=1000000000;
int que[10100];
int qs,qe;
vector<PII> solve(int l,int r){
  vector<PII> ret(m+1);
  REP1(i,1,m)ret[i].first=INF;
  if(l==r){
    ret[1]=MP(0,1);
  }else{
    int mi=INF,mm=0;
    REP1(i,l,r-1){
      if(dh[i]<mi){
        mi=dh[i];mm=i;
      }
    }
    vector<PII> d1=solve(l,mm);
    vector<PII> d2=solve(mm+1,r);
    REP1(i,1,m){
      d1[i].first+=i*mi;
      d2[i].first+=i*mi;
    }
    REP1(k,1,m){
      qs=qe=0;
      PER1(j,m,m-k){
        if(j==0)continue;
        while(qs<qe){
          if(d2[j].first<d2[que[qe-1]].first){
            qe--;
          }else break;
        }
        que[qe++]=j;
      }
      //printf("k=%d np=%d:",k,m);REP1(i,qs,qe-1)printf(" %d",que[i]);puts("");
      PII shik(d2[que[qs]].first,0);
      for(int i=qs;i<qe&&d2[que[i]].first==d2[que[qs]].first;i++){
        shik.second=add(shik.second,mul(d2[que[i]].second,bin[k][m-que[i]]));
      }
      update(ret[m],d1[k],shik,bin[m][k]);
      PER1(np,m-1,k){
        if(que[qs]==np+1)qs++;
        if(np-k>0){
          int j=np-k;
          PII tp(d2[j].first,mul(d2[j].second,bin[k][k+j-m]));
          while(qs<qe){
            if(d2[j].first<d2[que[qe-1]].first){
              qe--;
            }else break;
          }
          que[qe++]=j;
        }
        //printf("k=%d np=%d:",k,np);REP1(i,qs,qe-1)printf(" %d",que[i]);puts("");
        PII shik(d2[que[qs]].first,0);
        for(int i=qs;i<qe&&d2[que[i]].first==d2[que[qs]].first;i++){
          shik.second=add(shik.second,mul(d2[que[i]].second,bin[k][np-que[i]]));
        }
        update(ret[np],d1[k],shik,bin[np][k]);
      }
    }
    REP1(i,1,m){
      ret[i].first-=i*mi;
      if(ret[i].first>INF/2)ret[i].first=INF;
    }
  }
  //printf("=== (%d,%d) ===\n",l,r);
  //REP1(i,1,m)printf("(%d,%d) ",ret[i].first,ret[i].second);
  //puts("");
  return ret;
}
int main(){
  bin[0][0]=1;
  REP1(i,1,1005){
    bin[i][0]=bin[i][i]=1;
    REP1(j,1,i-1)bin[i][j]=add(bin[i-1][j],bin[i-1][j-1]);
  }
  CASET{
    fprintf(stderr,"%d\n",cas);
    RII(n,m);
    REP(i,n){
      RS(tmp);
      s[i]=tmp;
    }
    sort(s,s+n);
    int as=0;
    REP(i,n)as+=s[i].length()+1;
    REP(i,n-1){
      int j=0;
      while(j<(int)s[i].length() && j<(int)s[i+1].length()&&s[i][j]==s[i+1][j])j++;
      dh[i]=j+1;
    }
    vector<PII> vals=solve(0,n-1);
    printf("Case #%d: %d %d\n",cas++,as-vals.back().first,vals.back().second);
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

