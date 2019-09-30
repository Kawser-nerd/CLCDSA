#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  ll N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  ll diff = B - A;
  bool ans = false;
  // cout << diff << endl;
  for (ll i = 0; i <= N-1; i++) {
    ll l = (N-1 - i)*C - i*D;
    ll r = (N-1 - i)*D - i*C;
    // cout << l << " " << r << endl;
    if (l <= diff && diff <= r) ans = true;
  }
  cout << (ans ? "YES" : "NO") << endl;
}