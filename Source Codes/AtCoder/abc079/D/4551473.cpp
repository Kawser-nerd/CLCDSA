#include <iostream>
using namespace std;

#define ll long long

int main () {
  ll h, w;
  cin >> h >> w;
  ll dp[10][10];
  for (ll i = 0; i < 10; i++) {
    for (ll j = 0; j < 10; j++) {
      cin >> dp[i][j];  
    }  
  }  
  for (ll k = 0; k < 10; k++) {
    for (ll i = 0; i < 10; i++) {
      for (ll j = 0; j < 10; j++) {
        if (dp[i][j] > dp[i][k] + dp[k][j]) {
          dp[i][j] = dp[i][k] + dp[k][j];  
        }  
      }  
    }  
  }
  ll ans = 0;
  for (ll i = 0; i < h; i++) {
    for (ll j = 0; j < w; j++) {
      ll s;
      cin >> s;
      if (s != -1) {
        ans += dp[s][1];
      }
    }  
  }
  cout << ans << endl;
}