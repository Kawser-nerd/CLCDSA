#include <iostream>

#include <vector>
template<class T>
class Matrix {
 public:
  Matrix(unsigned long m, unsigned long n) : m(m), n(n), data(m * n) {}
  T &operator()(unsigned i, unsigned j) { return data[i * n + j]; }
  unsigned long m;
  unsigned long n;
 private:
  std::vector<T> data;
};

#include <tuple>
template<class T>
T gcd(T a, T b) {
  if (a > b) { std::swap(a, b); }
  while (a && b) { b %= a, std::swap(a, b); }
  return a ? a : b;
}

void hoge(long long &a, long long b) {
  while (b % 2 == 0) {
    ++a;
    b /= 2;
  }
}

template<class T>
T determinant_int(Matrix<T> A) {
  T div = 0;
  T ret = 0;
  std::vector<unsigned> swap(A.m);
  for (unsigned i = 0; i < A.m; ++i) { swap[i] = i; }
  for (unsigned ii = 0; ii < A.m; ++ii) {
    auto i = ii;
    while (A(swap[i], ii) == 0) {
      ++i;
      if (i == A.m) { return static_cast<T>(1); }
    }
    if ((swap[ii] - swap[i]) % 2) { ret *= -1; }
    std::swap(swap[ii], swap[i]);
    i = swap[ii];
    hoge(ret, A(i, ii));
    for (unsigned jj = ii + 1; jj < A.m; ++jj) {
      unsigned j = swap[jj];
      if (A(j, ii) == 0) { continue; }
      auto g = gcd(A(i, ii), A(j, ii));
      auto a = A(i, ii) / g;
      auto b = A(j, ii) / g;
      hoge(div, a);
      for (unsigned k = ii + 1; k < A.n; ++k) {
        A(j, k) = a * A(j, k) - b * A(i, k);
        A(j, k) %= 2;
      }
    }
  }
  return ret - div;
}

int main() {
  unsigned N;
  std::cin >> N;
  Matrix<long long> A(N, N);
  for (unsigned i = 0; i < N; ++i) {
    std::string s;
    std::cin >> s;
    for (unsigned j = 0; j < s.size(); ++j) {
      A(i, j) = static_cast<long long>(s[j] - '0');
    }
  }
  std::cout << (determinant_int(A) ? "Even" : "Odd") << std::endl;
  return 0;
}