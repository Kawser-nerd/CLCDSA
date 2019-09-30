#include <iostream>
#include <vector>

template<class T>
class SegmentTree2 {
 public:
  SegmentTree2<T>(unsigned size, T &cmp) : index(size * 2), cmp(cmp) {
    for (unsigned i = 0; i < size; ++i) { index[i + size - 1] = i; }
    for (unsigned i = size - 1; i-- > 0;) {
      index[i] = cmp(index[2 * i + 1], index[2 * i + 2]) ? index[2 * i + 1] : index[2 * i + 2];
    }
  }
  void update(unsigned i) {
    i += index.size() / 2 - 1;
    while (i) {
      i = (i - 1) / 2;
      index[i] = cmp(index[2 * i + 1], index[2 * i + 2]) ? index[2 * i + 1] : index[2 * i + 2];
    }
  }
  unsigned minimum(unsigned a, unsigned b, unsigned k, unsigned l, unsigned r) {
    if (r <= a || b <= l) { return static_cast<unsigned>(index.size()); }
    if (a <= l && r <= b) { return index[k]; }
    else {
      auto x = minimum(a, b, 2 * k + 1, l, (l + r) / 2);
      auto y = minimum(a, b, 2 * k + 2, (l + r) / 2, r);
      if (x == index.size()) { return y; }
      else if (y == index.size()) { return x; }
      else { return cmp(x, y) ? x : y; }
    }
  }
 private:
  std::vector<unsigned> index;
  T &cmp;
};

int main() {
  const unsigned long long MOD = 1000000007;
  unsigned N;
  unsigned long long A, B;
  std::cin >> N >> A >> B;
  std::vector<unsigned long long> a(N);
  auto max = 0ull;
  for (unsigned i = 0; i < N; ++i) {
    std::cin >> a[i];
    max = std::max(max, a[i]);
  }
  auto cmp = [&](unsigned i, unsigned j) -> bool { return a[i] < a[j]; };
  SegmentTree2<decltype(cmp)> segTree(N, cmp);
  auto min_index = segTree.minimum(0, N, 0, 0, N);
  if (A == 1) {
    std::sort(a.begin(), a.end());
    for (unsigned i = 0; i < N; ++i) {
      std::cout << a[i] << std::endl;
    }
    return 0;
  }
  while (max > a[min_index] * A && B) {
    --B;
    a[min_index] *= A;
    max = std::max(a[min_index], max);
    segTree.update(min_index);
    min_index = segTree.minimum(0, N, 0, 0, N);
  }
  std::sort(a.begin(), a.end());
  for (auto &i : a) {
    i %= MOD;
    auto j = B / N;
    unsigned long long memo = A;
    while (j) {
      if (j & 1) {
        i *= memo;
        i %= MOD;
      }
      j >>= 1;
      memo *= memo;
      memo %= MOD;
    }
  }
  for (auto i = B % N; i < N; ++i) {
    std::cout << a[i] << std::endl;
  }
  for (auto i = 0u; i < B % N; ++i) {
    std::cout << a[i] * A % MOD << std::endl;
  }
  return 0;
}