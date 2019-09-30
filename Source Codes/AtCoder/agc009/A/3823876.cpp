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
#include <unordered_map>
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

template <typename T>
vector<bool> sieve(const T& n) {
  vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (T i = 2; i <= n; i++) {
    if (is_prime[i]) {
      for (T j = 2 * i; j <= n; j += i) is_prime[j] = false;
    }
  }
  return is_prime;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  vector<i64> a(n), b(n);
  for (int i = n - 1; i >= 0; i--) {
    cin >> a[i] >> b[i];
  }

  i64 res = 0;
  for (int i = 0; i < n; i++) {
    a[i] += res;
    if (a[i] % b[i] == 0) continue;
    res += b[i] - a[i] % b[i];
  }

  cout << res << endl;
}