#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

#define REP(i, n) for (int i = 0; i < n; i++)

using namespace std;

typedef pair<int, int> P;
typedef long long ll;

int main() {
  ll n;
  int x;
  cin >> n, cin >> x;

  vector<int> vec;
  REP(i, n) {
    int t;
    cin >> t;
    vec.push_back(t);
  }

  // ???????reduce
  // ????????????????

  ll cnt = 0;
  for (ll i = 0; i < n - 1; i++) {
    int left = vec[i];
    int right = vec[i + 1];
    if (left + right > x) {
      int diff = left + right - x;
      if (diff >= right) {
        right = 0;
        left = left - (diff - right);
      } else {
        right = right - diff;
      }
      vec[i] = left;
      vec[i + 1] = right;
      cnt += diff;
    }
  }

  cout << cnt << endl;
  return 0;
}