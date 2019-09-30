#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <set>
#include <string>
#include <utility>
#include <vector>
 
int main() {
  int n;
  int a[200000], inv[200000];
  std::set<int> s;
  long long ans = 0;
  std::cin >> n;
  for (int ni = 0; ni < n; ++ni) {
    std::cin >> a[ni];
    inv[a[ni] - 1] = ni;
  }
  for (int ni = 0; ni < n; ++ni) {
    auto pos = s.insert(inv[ni]).first;
    long long begin, end;
    if (pos == s.begin()) {
      begin = 0;
    } else {
      begin = *std::prev(pos) + 1;
    }
    if (std::next(pos) == s.end()) {
      end = n;
    } else {
      end = *std::next(pos);
    }
    ans += ((end - begin) * (end - begin + 1)
            - (inv[ni] - begin) * (inv[ni] - begin + 1)
            - (end - inv[ni] - 1) * (end - inv[ni])) / 2 * (ni + 1);
  }
  std::cout << ans << std::endl;
  return 0;
}