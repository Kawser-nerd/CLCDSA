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

inline LL go(map<LL,LL>& in) {
  map<LL,LL> ret;
  LL a;
  if(in.begin()->first>=0){
    if(in[0]>1)a=0;
    else {
      auto it=in.begin();
      it++;
      a=it->first;
    }
    if(a==0){
      for(auto it=in.begin();it!=in.end();it++)ret[it->first]=it->second/2;
    }else{
      for(auto it=in.begin();it!=in.end();it++){
        if(it->second==0)continue;
        ret[it->first]=it->second;
        in[it->first+a]-=it->second;
      }
    }
  }else{
    for(auto i2=in.begin();i2!=in.end();i2++){
      if(i2->first>=0){
        fprintf(stderr,"QQ\n");
        exit(0);
      }
      map<LL,LL> pp=in;
      bool flag=true;
      a=i2->first;
      for(auto it=pp.rbegin();it!=pp.rend();it++){
        if(it->second==0)continue;
        if(pp.count(it->first+a)==0||pp[it->first+a]<it->second){
          flag=false;
          break;
        }
        pp[it->first+a]-=it->second;
      }
      if(flag){
        for(auto it=in.rbegin();it!=in.rend();it++){
          if(it->second==0)continue;
          ret[it->first]=it->second;
          in[it->first+a]-=it->second;
        }
        break;
      }
    }
  }
  in=ret;
  return a;
}

int main(){
  CASET{
    DRI(p);
    vector<pair<LL,LL>> in;
    in.resize(p);
    REP(i,p){
      scanf("%lld",&in[i].first);
    }
    REP(i,p){
      scanf("%lld",&in[i].second);
    }
    map<LL,LL> mp;
    for(auto& p:in)mp[p.first]=p.second;
    vector<LL> ans;
    while(mp.size()>1||mp[0]>1){
      ans.push_back(go(mp));
    }
    sort(ALL(ans));
    printf("Case #%d:",cas++);
    REP(i,SZ(ans))printf(" %lld",ans[i]);
    puts("");
  }
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread

