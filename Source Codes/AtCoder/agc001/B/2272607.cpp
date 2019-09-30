#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, n) for (long(i) = 0; (i) < (n); (i)++)
#define sort(s) sort(s.begin(), s.end(), greater<int>())
#define ll long long int
using namespace std;

ll gcd(ll u, ll v) {
  while (v != 0) {
    ll r = u % v;
    u = v;
    v = r;
  }
  return u;
}
int main() {
  ll n, x;
  cin >> n >> x;
  cout << 3 * (n - gcd(n, x)) << endl;
  return 0;
}