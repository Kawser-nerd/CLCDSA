#include <iostream>
#include <vector>

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

int main() {
  unsigned N, M;
  std::cin >> N >> M;
  std::vector<std::pair<unsigned, unsigned>> lr(N);
  for (unsigned i = 0; i < N; ++i) {
    std::cin >> lr[i].first >> lr[i].second;
  }
  std::sort(lr.begin(), lr.end(),
            [](std::pair<unsigned, unsigned> i,
               std::pair<unsigned, unsigned> j) -> bool {
              return (i.second - i.first) < (j.second - j.first);
            });
  auto p = lr.begin();
  long long inc = N;
  FenwickTree<long long> fenwickTree(M + 2);
  for (unsigned i = 1; i <= M; ++i) {
    while (p < lr.end() && (p->second - p->first + 1) < i) {
      --inc;
      fenwickTree.add(p->first, 1);
      fenwickTree.add(p->second + 1, -1);
      ++p;
    }
    auto ans = inc;
    for (unsigned j = 0; j <= M; j += i) {
      ans += fenwickTree.sum(j);
    }
    std::cout << ans << std::endl;
  }
  return 0;
}