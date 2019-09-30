#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <numeric>
#include <set>
#include <bitset>
#include <cstdint>
using namespace std;

using i64 = int64_t;
using ui64 = uint64_t;
using d64 = long double;

constexpr int MOD = 1000000000 + 7;
constexpr int INF = (1 << 30);
constexpr i64 INF64 = INT64_MAX;
const long double PI = 3.141592653589793;

template <typename T>
void print(const vector<T> vec) {
  for (auto &e : vec) {
    cout << e << " ";
  }
  cout << endl;
}

int next_combination(int sub) {
  int x = sub & -sub, y = sub + x;
  return (((sub & ~y) / x) >> 1) | y;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  i64 n, k; cin >> n >> k;
  vector<ui64> s(n);
  bool flag = false;
  for(int i=0; i<n; i++) {
    cin >> s[i];
    if(s[i] == 0) flag = true;
  }
  if(flag) {
    cout << n << endl;
    return 0;
  }
  
  i64 ans = 0;
  for(int i=0; i<n; i++) {
    if(ans >= n - i) break;
    ui64 res = 1;
    i64 c = 0;
    for(int j=i; j<n; j++) {
      if(res*s[j] > k) break;
      res *= s[j];
      c++;
    }
    ans = max(ans, c);
  }

  cout << ans << endl;
}