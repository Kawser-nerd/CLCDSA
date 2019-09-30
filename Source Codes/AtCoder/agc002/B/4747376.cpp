#include <iostream>
#include <set>
#include <map>
#define ll long long
using namespace std;

int main () {
  ll n, m;
  cin >> n >> m;
  set<ll> box;
  map<ll, ll> dp;
  for (ll i = 1; i <= n; i++) dp[i] = 1;
  box.insert(1);
  for (ll i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    dp[x]--;
    dp[y]++;
    if (box.count(x) == 1) {
      box.insert(y);
      if (dp[x] == 0) box.erase(x);
    }  
  }
  /*
  for (auto last : box) {
    cout << last << endl;  
  }
  */
  cout << box.size() << endl;
    
}