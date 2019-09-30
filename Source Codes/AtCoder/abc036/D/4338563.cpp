#include <iostream>
#include <set>
#define ll long long
#define mod 1000000007
using namespace std;

ll dp[100000][2];
set<ll> box[100000];

void dfs (ll i, ll pa = -1) {
  dp[i][0] = 1;
  dp[i][1] = 1;
  for (auto j : box[i]) {
    if (j != pa) {
      dfs(j, i);
      
      dp[i][0] = ((dp[i][0] % mod) * ((dp[j][0] + dp[j][1]) % mod)) % mod;  
      dp[i][1] = ((dp[i][1] % mod) * (dp[j][0] % mod)) % mod;
    }  
  }
}

int main () {
  ll n;
  cin >> n;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < 2; j++) {
      dp[i][j] = 0;  
    }  
  }
  for (ll i = 0; i < n - 1; i++) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    box[a].insert(b);
    box[b].insert(a);  
  }
  dfs(0);
  cout << (dp[0][1] + dp[0][0]) % mod << endl;
}