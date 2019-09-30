#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[]) {
  ll N;
  cin >> N;
  map<ll, ll> A;
  for (ll i = 0; i < N; i++) {
    ll temp;
    cin >> temp;
    A[temp]++;
  }
  ll ans = 0;
  for (auto iter = A.begin(); iter != A.end(); iter++) {
    cerr << "iter.second=" << iter->second << endl;
    if (iter->second % 2 == 1) ans++;
  }
  cout << ans << endl;
  return 0;
}