#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
int n;
typedef __int128_t int128;
int128 M,F;
typedef pair<int128,int128> p2;
p2 t[210];
void solve(){
  int64 a,b;
  scanf("%lld %lld %d",&a,&b,&n);
  M=a;F=b;
  FOR(i,n){
    scanf("%lld %lld",&a,&b);
    t[i].second=a;
    t[i].first=b;
  }
  sort(t,t+n);
  vector<p2> s;
  FOR(i,n){
    while(!s.empty()&&s.back().second>=t[i].second)s.pop_back();
    if(s.empty()||s.back().first<t[i].first)s.push_back(t[i]);
  }
//  FOR(i,s.size())printf("%lld %lld\n",s[i].first,s[i].second);
  int128 ans=0,cost=F,days=0;
  for(int j=0;j<=s.size();j++){
    int128 next_days=j<s.size()?s[j].first+1:days,diff=next_days-days,cnt=1;
    if(j==s.size()){
      cnt=M/cost;
      ans=max(ans,cnt*days);
      break;
    }
    vector<int128> c;
    c.push_back(1);
    c.push_back(M/cost);
    c.push_back(M/(diff*s[j].second+cost));
    c.push_back(M/(diff*s[j].second+cost)+1);
    for(int z=-10000;z<=10000;z++)c.push_back(M/(diff*s[j].second+cost)+z);
    for(int i=0;i<c.size();i++){
      cnt=c[i];
      int128 left=M-cnt*cost;
      if(left<0||cnt<1)continue;
      //printf("%lld %lld %lld\n",cnt,cnt*days,j<s.size()?min(left/s[j].second,diff):0);
      ans=max(ans,cnt*days+min(left/s[j].second,diff*cnt)); 
      ++cnt;
    }
    cost+=s[j].second*(next_days-days);
    days=next_days;
  }
  printf("%lld\n",(int64)ans);
}
main(){
  char in[100],out[100],*pos;
  strcpy(in,__FILE__);
  strcpy(out,__FILE__);
  pos=in;
  while(*pos!='.')pos++;
  strcpy(pos,".in");
  pos=out;
  while(*pos!='.')pos++;
  strcpy(pos,".out");
  freopen(in,"r",stdin);
  freopen(out,"w",stdout);
  int t;
  scanf("%d",&t);
  for(int tt=1;tt<=t;tt++){
    fprintf(stderr,"processing case %d\n",tt);
    printf("Case #%d: ",tt);
    solve();
    fflush(stdout);
  }
  freopen(out,"r",stdin);
  char c;while((c=getc(stdin))!=EOF)putc(c,stderr);
}

