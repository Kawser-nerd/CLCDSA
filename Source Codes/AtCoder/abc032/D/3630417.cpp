#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;
lint N,W;
lint v[200],w[200];
lint dp[200*1000+1]={0};

lint w_sum=0;
lint v_sum=0;
lint a=0;


void dfs(int depth){
  if(depth==N){
    a=max(a,v_sum);
  }else{
    v_sum+=v[depth];
    w_sum+=w[depth];
    if(w_sum<=W)dfs(depth+1);
    v_sum-=v[depth];
    w_sum-=w[depth];
    dfs(depth+1);
  }
}

lint solve_edakari(){
  vector<pair<lint,lint> > vec;
  REP(i,N)vec.push_back(make_pair(w[i],v[i]));
  sort(ALL(vec),greater<pair<lint,lint> >());
  REP(i,N){
    w[i]=vec[i].first;
    v[i]=vec[i].second;
  }
  // REP(i,N)cerr<<w[i]<<" "<<v[i]<<endl;
  dfs(0);
  return a;
}


lint solve_case1(){
  map<lint,lint> mA;
  map<lint,lint> mB;
  int h=N/2;
  REP(i,1<<h){
    lint v_sum=0;
    lint w_sum=0;
    REP(j,h){
      if((i>>j)%2==0)continue;
      v_sum+=v[j];
      w_sum+=w[j];
    }
    mA[w_sum]=max(mA[w_sum],v_sum);
  }
  REP(i,1<<(N-h)){
    lint v_sum=0;
    lint w_sum=0;
    FOR(j,h,N){
      if((i>>(j-h))%2==0)continue;
      v_sum+=v[j];
      w_sum+=w[j];
    }
    mB[w_sum]=max(mB[w_sum],v_sum);
  }
  lint temp=-1;
  auto itr=mA.begin();
  while(itr!=mA.end()){
    if(itr->second<=temp){
      mA.erase(itr++);
    }else{
      temp=itr->second;
      ++itr;
    }
  }
  // for(auto e:mA)cerr<<e.second<<"  "<<e.first<<endl;
  lint ans=0;
  for(auto e:mB){
    if(e.first>W)break;
    auto itr=mA.upper_bound(W-e.first);
    itr--;
    ans=max(ans,e.second+itr->second);
    // cerr<<e.first<<" match "<<itr->first<<endl;
  }
  return ans;
}

lint solve_case2(){
  REP(i,N){
    for(int j=W;j>w[i];j--){
      if(dp[j-w[i]]==0)continue;
      dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    }
    dp[w[i]]=max(dp[w[i]],v[i]);
  }
  // REP(i,W+1){
  //   if(dp[i]==0)continue;
  //   cerr<<i<<" "<<dp[i]<<endl;
  // }
  return *max_element(dp,dp+W+1);
}

lint solve_case3(){
  REP(i,N*1000+1)dp[i]=W+1;
  REP(i,N){
    for(int j=200*1000;j>v[i];j--){
      if(dp[j-v[i]]>W)continue;
      dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
    }
    dp[v[i]]=min(dp[v[i]],w[i]);
  }
  // REP(i,N*1000+1){
  //   if(dp[i]>W)continue;
  //   cerr<<i<<" "<<dp[i]<<endl;
  // }
  for(int i=N*1000;i>0;i--)if(dp[i]<=W)return i;
  return -2;
}
int main(){
  cin>>N>>W;
  REP(i,N)cin>>v[i]>>w[i];
  lint ans;
  bool f=true;
  REP(i,N)if(w[i]>1000)f=false;
  int c;
  if(N<=30)c=1;
  else if(f)c=2;
  else c=3;
  switch(c){
    case 1:
      ans=solve_case1();
      break;
    case 2:
      ans=solve_case2();
      break;
    case 3:
      ans=solve_case3();
      break;
  }
  cout<<ans<<endl;
  return 0;
}