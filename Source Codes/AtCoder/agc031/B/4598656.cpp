#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define ll long long
#define mod 1000000007

int main () {
  ll n;
  cin >> n;
  ll a[n];
  vector<ll> ans;
  ans.push_back(0);
  map<ll, ll> box;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    if (i != 0) {
      if (a[i] != a[i - 1]) {
        ans.push_back(a[i]);  
      }  
    }
    else {
      ans.push_back(a[i]);  
    }
  }  
  ll dp[ans.size()];
  for (ll i = 0; i < ans.size(); i++) {
    dp[i] = 0;  
  }
  dp[0] = 1;
  for (ll i = 1; i < ans.size(); i++) {
    if (box[ans[i]] == 0) {
      dp[i] = dp[i - 1];
      box[ans[i]] = i;  
    }     
    else {
      dp[i] = (dp[i - 1] + dp[box[ans[i]]]) % mod;
      box[ans[i]] = i;  
    }
  }
  cout << dp[ans.size() - 1] << endl;


}