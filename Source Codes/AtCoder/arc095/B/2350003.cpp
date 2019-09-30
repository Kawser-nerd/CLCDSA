#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  unsigned long n;
  std::cin >> n;
  std::vector<long long> a(n);
  for (auto &i : a) { std::cin >> i; }
  std::sort(a.begin(), a.end());
  auto odd = a.back() % 2 == 1;
  auto med = a.back() / 2;
  auto min = a.back();
  auto ans = a.back();
  for (auto i : a) {
    if (i == a.back()) { continue; }
    if (i > med) {
      if (odd) {
        if (min > (i - med) - 1) {
          min = (i - med) - 1;
          ans = i;
        }
      } else {
        if (min > (i - med)) {
          min = i - med;
          ans = i;
        }
      }
    } else {
      if (min > (med - i)) {
        min = med - i;
        ans = i;
      }
    }
  }
  std::cout << a.back() << " " << ans << std::endl;
  return 0;
}