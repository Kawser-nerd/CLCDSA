#include <iostream>
using namespace std;
#define ll long long

int main () {
  ll n;
  cin >> n;
  ll a[n];
  for (ll i = 0; i < n; i++) cin >> a[i];
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    if (a[i] % 2 == 1 && (i + 1) < n) {
      if (a[i + 1] > 0) {
        a[i + 1]--;
        a[i]--;
        ans++;  
      }
    }
    ans += a[i] / 2;
    a[i] = 0;
  }  
  cout << ans << endl;
}