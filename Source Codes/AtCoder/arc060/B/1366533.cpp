#include <iostream>
#include <cmath>
#include <vector>

bool f(unsigned long long b, unsigned long long n, unsigned long long s) {
  unsigned long long k = 0;
  while (n) {
    k += n % b;
    n /= b;
  }
  return k == s;
}

int main() {
  unsigned long long n, s;
  std::cin >> n >> s;
  if (n < s) {
    std::cout << -1;
    return 0;
  }
  for (unsigned long long i = 2; i < std::sqrt(n) + 1; ++i) {
    if (f(i, n, s)) {
      std::cout << i;
      return 0;
    }
  }
  std::vector<unsigned long long> ans;
  for (unsigned long long i = 1; i < std::sqrt(n) + 1; ++i) {
    if ((n - s) % i) { continue; }
    auto k = (n - s) / i + 1;
    if (k > 1 && f(k, n, s)) {
      ans.push_back(k);
    }
  }
  if (!ans.empty()) {
    std::sort(ans.begin(), ans.end());
    std::cout << ans[0];
    return 0;
  }
  if (s == n) {
    std::cout << n + 1;
    return 0;
  }
  std::cout << -1;
  return 0;
}