#include <iostream>
using namespace std;
#define ll long long
#define inf 10000000001

int main () {
  ll n, m;
  cin >> n >> m;
  ll dp[n + 1][n + 1];
  ll max[n + 1];
  for (ll i = 0; i <= n; i++) {
    max[i] = -1;
    for (ll j = 0; j <= n; j++) {
      if (i == j) {
        dp[i][j] = 0;  
      }  
      else {
        dp[i][j] = inf;  
      }
    }  
  }
  for (ll i = 0; i < m; i++) {
    ll s, ss, t;
    cin >> s >> ss >> t;
    dp[s][ss] = t;
    dp[ss][s] = t;
  }
  for (ll k = 1; k <= n; k++) {
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= n; j++) {
        if (dp[i][j] >= dp[i][k] + dp[k][j]) {
          dp[i][j] = dp[i][k] + dp[k][j];  
        }  
      }  
    }
  }
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      if (max[i] < dp[i][j]) {
        max[i] = dp[i][j];  
      }
    }  
  }
  sort(max, max + n + 1);
  cout << max[1] << endl;
    
}