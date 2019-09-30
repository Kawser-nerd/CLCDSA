#include <iostream>
#include <string.h>
#include <map>
using namespace std;
#define ll long long

int main () {
  ll n, m;
  cin >> n >> m;
  map<ll, ll> box;
  ll v[9] = {
   2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6 
  };
  for (ll i = 1; i <= 9; i++) {
    box[i] = v[i - 1];      
  }  
  ll a[m], b[m];
  for (ll i = 0; i < m; i++) {
    cin >> a[i];
  }
  sort(a, a + m);
  for (ll i = 0; i < m; i++) {
    b[i] = box[a[i]];  
  }
  string dp[100000 + 1];
  for (ll i = 0; i <= n; i++) {
    dp[i] = "0";
    string max = "";
    for (ll j = 0; j < m; j++) {
      if (i - b[j] == 0) {
        if (dp[i][0] < ('0' + a[j])) {
          dp[i][0] = '0' + a[j];  
        }        
      }  
      if (i - b[j] > 0 && dp[i - b[j]] != "0") {
        string sub = to_string(a[j]) + dp[i - b[j]]; 
        if (sub.size() > max.size()) {
          max = sub;  
        }
        else if (max.size() == sub.size() && string(sub).compare(max) > 0) {
          max = sub;
        }
      }
    }   
    if (max != "") {
      dp[i] = max;  
    }
  }
  cout << dp[n] << endl;
}