#include <iostream>
#include <cmath>
using namespace std;

int dp[2][2005];
int a[2005];

int main(){
  int n,z,w;
  cin >> n >> z >> w;
  for(int i=0;i<n;i++) cin >> a[i];
  // dp[i][j] = score when j_th card was drowed by !i. 
  if(n==1){
  	cout << abs(a[0] - w) << endl;
    return 0;
  }
  for(int i=n-1;i>=0;i--){
    if(i==n-1){
      dp[0][n-1] = abs(a[n-2]-a[n-1]);
      dp[1][n-1] = abs(a[n-2]-a[n-1]);
    }else if(i==0){
      dp[0][0] = abs(w - a[n-1]);
      for(int j=1;j<n;j++){
      dp[0][0] = dp[0][0] < dp[1][j] ? dp[1][j] : dp[0][0];
      }
      dp[1][0] = abs(z - a[n-1]);
      for(int j=1;j<n;j++){
        dp[1][0] = dp[1][0] < dp[0][j] ? dp[0][j] : dp[1][0];
      }
    }else{
      dp[0][i] = abs(a[i-1] - a[n-1]);
      dp[1][i] = abs(a[i-1] - a[n-1]);
      for(int j=i+1;j<n;j++){
        dp[0][i] = dp[0][i] < dp[1][j] ? dp[1][j] : dp[0][i];
      }
      for(int j=i+1;j<n;j++){
        dp[1][i] = dp[1][i] < dp[0][j] ? dp[1][i] : dp[0][j];
      }
    }
  }
  cout << dp[0][0] << endl;
  return 0;
}