#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[51][51][11111];
//int num[51][51][11111];
int w,n,k;
vector<pair<int,int> > ab;

int solve(int use_w,int now,int use_k){
  if(dp[now][use_k][use_w] != 0)
    return dp[now][use_k][use_w];
  if(now == n)
    return 0;
  int ret = 0;

  if(use_k == k){
    ret = 0;
  }else if(use_w + ab[now].first <=w){
    ret = max(solve(use_w,now+1,use_k),solve(use_w + ab[now].first,now+1,use_k+1)+ab[now].second);
  }else if(use_w + ab[now].first > w){
    ret = solve(use_w,now+1,use_k);
  }
  
  return dp[now][use_k][use_w] = ret;
}

int main(){

  cin>>w;
  cin>>n>>k;
 
  for(int i = 0;i<n;i++){
    int a,b;
    cin>>a>>b;
    ab.push_back(make_pair(a, b));
    
  }
  
 
  cout<<solve(0,0,0)<<endl;
  return 0;
}