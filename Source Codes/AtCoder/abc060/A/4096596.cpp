#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;
using int64 = int_fast64_t;
#define int int64
constexpr int MAX_N = 202020;
constexpr int MOD = 1e9 + 7;

signed main() {
  string a,b,c;
  cin >> a >> b >> c;
  cout << (a.back() == b[0] && b.back() == c[0] ? "YES" : "NO") << endl;
  return 0;
}