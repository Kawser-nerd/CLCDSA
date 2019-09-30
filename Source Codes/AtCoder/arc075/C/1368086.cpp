#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
class FenwickTree {
 public:
  std::vector<T> data;
  FenwickTree<T>(unsigned size) : data(size + 1u, 0) {}
  T sum(unsigned index) {
    ++index;
    T ret = 0;
    while (index) {
      ret += data[index];
      index &= index - 1u;
    }
    return ret;
  }
  void add(unsigned index, T x) {
    ++index;
    while (index <= data.size()) {
      data[index] += x;
      index += index & (~index + 1u);
    }
  }
};

template<class T>
unsigned long long n_order_lte(const std::vector<T> &a) {
  std::vector<T> b(a);
  std::sort(b.begin(), b.end());
  FenwickTree<unsigned long long> fenwickTree(static_cast<unsigned>(a.size()));
  unsigned long long ans = 0;
  for (unsigned i = 0; i < a.size(); ++i) {
    unsigned x = b.end() - std::lower_bound(b.begin(), b.end(), a[i]) - 1;
    ans += x - fenwickTree.sum(x);
    x = b.end() - std::upper_bound(b.begin(), b.end(), a[i]);
    fenwickTree.add(x, 1);
  }
  return ans;
}

int main() {
  unsigned long long N;
  long long K;
  std::cin >> N >> K;
  std::vector<long long> a(N+1);
  a[0] = 0;
  for (unsigned i = 1; i <= N; ++i) {
    std::cin >> a[i];
    a[i] -= K;
  }
  for (unsigned i = 1; i <= N; ++i) {
    a[i] += a[i - 1];
  }
  std::cout << n_order_lte(a);
  return 0;
}