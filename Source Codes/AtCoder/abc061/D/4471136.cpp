#include <iostream>
#include <utility>
#include <set>
#define ll long long
#define inf 1000000000000000

using namespace std;

int main () {
  ll n, m;
  cin >> n >> m;
  ll box[1001][1001];
  ll d[1001];
  for (ll i = 0; i <= 1000; i++) {
    d[i] = inf;
  }
  ll a[m], b[m], c[m];
  for (ll i = 0; i < m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    c[i] = c[i] * -1;
  }  
  d[1] = 0;
  ll before = 0;
  ll after = 0;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      if (d[b[j]] > d[a[j]] + c[j]) {
        d[b[j]] = d[a[j]] + c[j];  
      } 
    }  
    if (i == n - 2) {
      before = d[n];  
    }
    if (i == n - 1) {
      after = d[n];  
    }
  }
  if (before > after) {
    cout << "inf" << endl;
    return 0;
  }
  cout << d[n] * - 1 << endl;
  
}