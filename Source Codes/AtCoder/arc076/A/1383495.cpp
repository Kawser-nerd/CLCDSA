#include <algorithm>
#include <iostream>
using namespace std;

using int64 = long long;
const int64 kMod = 1000000007;

int64 Count(int64 n, int64 m) {
  if (n > m)
    std::swap(n, m);
  if (n + 1 < m)
    return 0;

  int64 ret = 1;
  for (int64 i = 1; i <= n; ++i) {
    ret = ret * i % kMod;
  }
  for (int64 i = 1; i <= m; ++i) {
    ret = ret * i % kMod;
  }
  if (n == m) {
    ret = ret * 2 % kMod;
  }
  return ret;
}

int main(void) {
  int64 n, m;
  cin >> n >> m;
  cout << Count(n, m) << "\n";
  return 0;
}