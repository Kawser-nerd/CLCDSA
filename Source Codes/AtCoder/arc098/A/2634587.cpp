#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

#define REPI(i, n) for (int i = 0; i < static_cast<int>(n); ++i)
#define REPD(i, n) for (int i = static_cast<int>(n); i >= 0; --i)
#define FOR(i, c) for (auto i : (c))
#define FOR_REF(i, c) for (auto &i : (c))
#define ALL(c) (c).begin(), (c).end()
#define LEN(c) static_cast<int>((c).size())

#define IO_SETUP                                                               \
  std::cin.tie(nullptr);                                                       \
  std::ios::sync_with_stdio(false);

#define SEE(i) std::cerr << #i << ": " << i << " at: (" << __LINE__ << ")\n";

int main() {
  using namespace std;
  IO_SETUP;
  constexpr int SIZ = 300001;
  int n;
  cin >> n;
  int a[SIZ] = {}, b[SIZ] = {};
  string s;
  cin >> s;
  REPI(i, n) {
    if (i == 0) {
      a[i] = (s[i] == 'W' ? 1 : 0);
      continue;
    }
    a[i] = a[i - 1] + (s[i] == 'W' ? 1 : 0);
  }
  REPD(i, n - 1) {
    if (i == n - 1) {
      b[i] = (s[i] == 'E' ? 1 : 0);
      continue;
    }
    b[i] = b[i + 1] + (s[i] == 'E' ? 1 : 0);
  }
  int val = n;
  REPI(i, n) { val = min(val, a[i] + b[i]); }
  cout << val - 1;
  return 0;
}