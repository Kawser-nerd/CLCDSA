#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[51][51][11111];
int num[51][51][11111];
int main(){
  int w,n,k;
  cin>>w;
  cin>>n>>k;
  vector<pair<int,int> > ab;
  for(int i = 0;i<n;i++){
    int a,b;
    cin>>a>>b;
    ab.push_back(make_pair(a, b));
    
  }
  for(int i = 1;i<=n;i++){
    for(int j = 1;j<= k;j++){
      for(int l = 1;l<= w;l++){
	if(l < ab[i-1].first){
	  dp[i][j][l] = dp[i-1][j][l];
	}else{
	  dp[i][j][l] = max(dp[i-1][j][l],dp[i-1][j-1][l-ab[i-1].first]+ab[i-1].second);
	}
      }
    }
  }
  int ans = 0;
  for(int i = 0;i<=k;i++){
    for(int j = 0;j<=w;j++){
      ans = max(ans,dp[n][i][j]);
    }
  }

  cout<<dp[n][k][w]<<endl;
  return 0;
}