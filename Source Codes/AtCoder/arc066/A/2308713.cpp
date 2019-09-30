#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

#define REP(i, n) for (int i = 0; i < n; i++)

typedef long long ll;
using namespace std;

int main() {
  ll N;
  cin >> N;
  map<int, int> mp;

  if (N % 2 == 0) {
    for (int i = 1; i < N; i += 2) {
      mp[i] = 0;
    }
  } else {
    for (int i = 0; i < N; i += 2) {
      mp[i] = 0;
    }
  }

  bool invalid = false;
  REP(i, N) {
    ll t;
    cin >> t;
    auto itr = mp.find(t);
    if (itr == mp.end()) {
      invalid = true;
    } else {
      mp[t] += 1;
    }
  }

  if (invalid) {
    cout << 0 << endl;
    // cout << "debug x" << endl;
    return 0;
  }

  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    int key = itr->first;
    int cnt = itr->second;
    if (N % 2 == 1 && key == 0) {
      if (cnt == 1) {
        continue;
      } else {
        invalid = true;
      }
    } else {
      if (cnt != 2) {
        invalid = true;
      }
    }
  }

  if (invalid) {
    cout << 0 << endl;
    // cout << "debug y" << endl;
    return 0;
  }

  ll ans = 1;
  for (ll i = 0; i < N / 2; i++) {
    ans *= 2;
    ans %= 1000000007;
  }
  cout << ans << endl;

  return 0;
}