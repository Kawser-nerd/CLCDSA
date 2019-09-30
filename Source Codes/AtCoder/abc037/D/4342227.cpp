#include <iostream>
using namespace std;
#define ll long long
#define mod 1000000007

ll h, w;
ll a[1000][1000];
ll dp[1000][1000];
ll stand[1000][1000];
ll ans = 0;
ll sub = 0;

void dfs (ll i, ll j) {
  stand[i][j] = 1;
  dp[i][j] = 1;
  ll vx[4] = {1, -1, 0, 0};
  ll vy[4] = {0, 0, 1, -1};
  for (ll l = 0; l < 4; l++) {
    ll y = i + vy[l];
    ll x = j + vx[l];
    if (y >= 0 && y < h && x >= 0 && x < w) {
      if (a[y][x] > a[i][j]) {
        if (stand[y][x] == 0) {
          dfs(y, x);  
        }
        dp[i][j] = (dp[i][j] + dp[y][x]) % mod;
      }  
    }  
  }
}

int main () {
  cin >> h >> w;
  for (ll i = 0; i < h; i++) {
    for (ll j = 0; j < w; j++) {
      cin >> a[i][j];  
      dp[i][j] = 0;
      stand[i][j] = 0;
    }  
  }  
  for (ll i = 0; i < h; i++) {
    for (ll j = 0; j < w; j++) {
      if (stand[i][j] == 0) {
        dfs(i, j);  
      }
    } 
  }
  for (ll i = 0; i < h; i++) {
    for (ll j = 0; j < w; j++) {
      ans = (ans + dp[i][j]) % mod;
    }  
  }
  cout << ans << endl;
}