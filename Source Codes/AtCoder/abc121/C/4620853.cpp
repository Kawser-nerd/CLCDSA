#include <iostream>
#include <utility>
using namespace std;
#define ll long long

int main () {
  ll n, m;
  cin >> n >> m;
  pair<ll, ll> box[1000000];
  for (ll i = 0; i < n; i++) {
    ll s, ss;
    cin >> s >> ss;
    box[i] = make_pair(s, ss);    
  }  
  sort(box, box + n);
  ll ans = 0;
  ll num = 0;
  for (ll i = 0; i < n; i++) {
    num += box[i].second;
    ans += box[i].second * box[i].first;
    if (num >= m) {
      ans -= box[i].first * (num - m);
      cout << ans << endl;
      return 0;    
    }    
  }
}