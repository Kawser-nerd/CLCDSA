#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;
Int dp[108000][2];
int n;
Int a[108000];
int main(){
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> a[i];
  }
  dp[0][0] = 0;
  dp[0][1] = 0;
  for(int i = 1;i <= n;i++){
    dp[i][0] = max(dp[i][0], dp[i-1][0] + a[i-1] / 2);
    if(a[i-1] >= 1)dp[i][0] = max(dp[i][0], dp[i-1][1] + (a[i-1] - 1) / 2 );
    if(a[i] > 0 && a[i-1] > 0)dp[i][1] = max(dp[i][1], dp[i-1][0] + (a[i-1] - 1) / 2 + 1);
    if(a[i] > 0 && a[i-1] > 1)dp[i][1] = max(dp[i][1], dp[i-1][1] + (a[i-1] - 2) / 2 + 1);
  }
  cout << dp[n][0] << endl;
  return 0;
}