#include <algorithm>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

const int M = 1000000000 + 7;

long long inv(int x, int m) {
  long long a[3] = {1, 0, x};
  long long b[3] = {0, 1, m};
  while (b[2] > 0) {
    long long r = a[2] / b[2];
    for (int i = 0; i < 3; ++i) {
      a[i] = a[i] - b[i] * r;
    }
    std::swap(a, b);
  }
  if (a[2] != 1) {
    throw std::runtime_error("no inv");
  }
  return a[0] > 0? a[0] % m: (m - (-a[0]) % m) % m;
}

long long comb(int n, int r) {
  long long x = 1;
  r = std::min(n, n - r);
  for (int i = 0; i < r; ++i) {
    x = x * (n - i) % M * inv(i + 1, M) % M;
  }
  return x;
}

int main() {
  long long h, w, a, b, c;
  long long ans = 0;
  std::cin >> h >> w >> a >> b;
  ans = comb(h + w - 2, h - 1);
  for (int i = 0; i < b; ++i) {
    // c = comb(h - a + i - 1, h - a - 1) * comb(a + w - i - 2, a - 1) % M;
    if (i == 0) {
      c = comb(h - a - 1, h - a - 1) * comb(a + w - 2, a - 1) % M;
    } else {
      c = c * (h - a + i - 1) % M * inv(i, M) % M;
      c = c * (w - i) % M * inv(a + w - i - 1, M) % M;
    }
    ans = (ans + M - c) % M;
  }
  std::cout << ans << std::endl;
  return 0;
}