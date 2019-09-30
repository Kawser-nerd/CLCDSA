#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>
 
int main() {
  int n, len;
  int a[100];
  int nums[100] = {};
  std::cin >> n;
  for (int ni = 0; ni < n; ++ni) {
    std::cin >> a[ni];
    ++nums[a[ni]];
  }
  len = *std::max_element(a, a + n);
  for (int x = 0; x <= len; ++x) {
    --nums[std::max(len - x, x)];
  }
  if (*std::min_element(nums, nums + 100) < 0 or
      *std::max_element(nums, nums + (len + 1) / 2 + 1) > 0) {
    std::cout << "Impossible" << std::endl;
    return 0;
  }
  std::cout << "Possible" << std::endl;
  return 0;
}