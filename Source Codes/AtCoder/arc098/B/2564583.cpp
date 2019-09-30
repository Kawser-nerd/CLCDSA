#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

bool is_acceptable(int a, int b) {
  for (int i = 0; i <= 20; ++i) {
    int x = (a >> i) & 1;
    int y = (b >> i) & 1;
    if (x == 1 and y == 1) return false;
  }
  return true;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int ni = 0; ni < n; ++ni) std::cin >> a[ni];
  long long ans = 0;
  int total = 0;
  int right = 0;
  for (int left = 0; left < n; ++left) {
    while (right < n) {
      if (is_acceptable(total, a[right])) {
        total += a[right];
        ++right;
      } else {
        break;
      }
    }
    ans += right - left;
    total -= a[left];
  }
  std::cout << ans << std::endl;
  return 0;
}