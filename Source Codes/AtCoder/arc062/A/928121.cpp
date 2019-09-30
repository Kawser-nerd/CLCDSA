#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

int main() {
  long long n, t, a, xt, xa;
  std::cin >> n;
  for (long long ni = 0; ni < n; ++ni) {
    std::cin >> t >> a;
    if (ni == 0) {
      xt = t;
      xa = a;
    } else {
      long long k = std::max((xt + t - 1) / t, (xa + a - 1) / a);
      xt = k * t;
      xa = k * a;
    }
  }
  std::cout << xt + xa << std::endl;
  return 0;
}