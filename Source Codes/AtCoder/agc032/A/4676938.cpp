#include <iostream>
#include <string.h>
#include <set>
#include <vector>

using namespace std;
#define ll long long

int main () {
  ll n;
  cin >> n;
  ll b[n], stand[n];
  for (ll i = 0; i < n; i++) {
    cin >> b[i];
    stand[i] = 0;
  }    
  vector<ll> ans;
  int length = 0;
  int itr = -1;
  for (int i = 0; i < n; i++) {
    // n???????
    length = 0;
    itr = -1;
    for (int j = 0; j < n; j++) {
      if (stand[j] == 1) continue;
      length++;
      if (length == b[j]) {
        itr = j;  
      }  
    }   
    if (itr != -1) {
      ans.push_back(b[itr]);
      stand[itr] = 1;    
    }
  }
  for (int i = 0; i < n; i++) {
    if (stand[i] == 0) {
      cout << -1 << endl;
      return 0;  
    }  
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[ans.size() - 1 - i] << endl;  
  }
}