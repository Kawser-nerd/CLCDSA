#include <iostream>
#include <vector>

std::vector<unsigned> inc(std::vector<unsigned> &x, unsigned index) {
  auto y = x;
  y[index] += 1;
  for (unsigned i = 0; i < x.size() - 1; ++i) {
    y[i + 1] += y[i] / 10;
    y[i] %= 10;
  }
  return y;
}

bool lt(
    std::vector<unsigned>::iterator x_begin,
    std::vector<unsigned>::iterator x_end,
    std::vector<unsigned>::iterator y_begin,
    std::vector<unsigned>::iterator y_end) {
  if (y_end - y_begin > x_end - x_begin) {
    for (int p = 0; p < (y_end - y_begin) - (x_end - x_begin); ++p) {
      if (*(y_end - p - 1)) { return true; }
    }
    y_end -= (y_end - y_begin) - (x_end - x_begin);
  }
  if (x_end - x_begin > y_end - y_begin) {
    for (int p = 0; p < (x_end - x_begin) - (y_end - y_begin); ++p) {
      if (*(x_end - p - 1)) { return false; }
    }
    x_end -= (x_end - x_begin) - (y_end - y_begin);
  }
  for (int p = 0; p < (y_end - y_begin); ++p) {
    if (*(x_end - p - 1) < *(y_end - p - 1)) {
      return true;
    } else if (*(x_end - p - 1) > *(y_end - p - 1)) {
      return false;
    }
  }
  return false;
}

int main() {
  std::vector<unsigned> a(1, 0);
  while (true) {
    char x = (char) std::cin.get();
    if (x == '\n') {
      break;
    } else {
      a.push_back(x - '0');
    }
  }
  std::reverse(a.begin(), a.end());
  a.push_back(0);
  a.push_back(0);
  a.push_back(0);
  unsigned N = a.size();
  std::vector<unsigned> b(3 * N, 0);
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < N; ++j) {
      b[i + j] += a[i] * a[j];
    }
  }
  for (unsigned i = 0; i < 3 * N - 1; ++i) {
    b[i + 1] += b[i] / 10;
    b[i] %= 10;
  }
  auto a2 = inc(a, 0);
  std::vector<unsigned> c(3 * N, 0);
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < N; ++j) {
      c[i + j] += a2[i] * a2[j];
    }
  }
  for (unsigned i = 0; i < 3 * N - 1; ++i) {
    c[i + 1] += c[i] / 10;
    c[i] %= 10;
  }
  int k = 0;
  bool hoge = true;
  for (unsigned i = 0; i < 3 * N; i += 2) {
    if (hoge) {
      k = i;
    } else {
      auto b2 = inc(b, i);
      std::fill(b2.begin(), b2.begin() + i, 0);
      if (lt(b2.begin(), b2.end(), c.begin(), c.end())) {
        k = i;
      }
    }
    if (b[i]) { hoge = false; }
  }
  bool flg = false;
  for (int i = 0; i < k; ++i) {
    if (b[i]) {
      flg = true;
      break;
    }
  }
  if (flg) {
    b[k] += 1;
  }
  for (unsigned i = k; i < 3 * N - 1; ++i) {
    b[i + 1] += b[i] / 10;
    b[i] %= 10;
  }
  for (int i = 3 * N - 1; i >= k; --i) {
    if (b[i] > 0) {
      for (; i >= k; --i) {
        std::cout << b[i];
      }
    }
  }
  std::cout << std::endl;
  return 0;
}