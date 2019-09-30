#include <iostream>
#include <vector>

int main() {
  uint64_t N;
  std::cin >> N;
  std::vector<uint64_t> a(N);
  for (unsigned i = 0; i < N; ++i) {
    std::cin >> a[i];
  }
  uint64_t max = std::numeric_limits<uint64_t>::max() / 4;
  uint64_t min = 0;
  auto ok = [&](uint64_t k) -> bool {
    uint64_t kk = 0ull;
    for (auto &i : a) {
      if (i + k > N - 1) {
        kk += (i + k - N) / (N + 1) + 1;
      }
      if (kk > k) {
        return false;
      }
    }
    return true;
  };
  while (max - min > 2) {
    auto k = (max + min) / 2;
    bool b = false;
    for (unsigned i = 0; i < N; ++i) {
      if (k >= i) {
        auto bb = ok(k - i);
        if (bb) {
          b = true;
          break;
        }
      }
    }
    if (b) {
      max = k + 1;
    } else {
      min = k + 1;
    }
  }
  if (ok(min + 1)) std::cout << (ok(min) ? min : min + 1) << std::endl;
  else std::cout << min << std::endl;
  return 0;
}