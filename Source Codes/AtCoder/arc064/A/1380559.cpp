#include <iostream>
#include <vector>

int main() {
  unsigned long long N, x;
  std::cin >> N >> x;
  std::vector<unsigned long long> a(N);
  for (unsigned i = 0; i < N; ++i) { std::cin >> a[i]; }
  unsigned long long ans = 0ull;
  for (unsigned i = 1; i < N; ++i) {
    if (a[i - 1] + a[i] > x) {
      if (a[i - 1] < x) {
        ans += a[i] + a[i - 1] - x;
        a[i] -= a[i] + a[i - 1] - x;
      } else {
        ans += a[i];
        a[i] = 0;
        ans += a[i - 1] - x;
      }
    }
  }
  std::cout << ans;
  return 0;
}