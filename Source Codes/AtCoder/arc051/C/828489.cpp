#include <string>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

std::size_t powmod (std::size_t x, std::size_t n, std::size_t p) {
  if (n == 0) { return 0; }
  if (n == 1) { return x % p; }
  if (n % 2 == 0) {
    std::size_t y = powmod(x, n / 2, p);
    return (y * y) % p;
  }
  return (powmod(x, n / 2, p) * powmod(x, n / 2 + 1, p)) % p;
}

std::size_t intlog (std::size_t x, std::size_t p) {
  if (x >= p) {
    return 1 + intlog(x / p, p);
  }
  return 1;
}

int main (int argc, char ** argv) {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string line;
  std::getline(std::cin, line);
  char * p = &*line.begin();

  std::size_t N = std::strtol(p, &p, 10);
  std::size_t A = std::strtol(p, &p, 10);
  std::size_t B = std::strtol(p, &p, 10);
  std::size_t P = 1000000007;

  std::vector<std::size_t> a(N);

  std::getline(std::cin, line);
  p = &*line.begin();
  for (int i = 0; i < N; ++i) {
    a[i] = std::strtol(p, &p, 10);
  }
  std::sort(a.begin(), a.end());

  if (A == 1) {
    for (int i = 0; i < N; ++i) {
      std::cout << (a[i] % P) << std::endl;
    }
    return 0;
  }

  int i;
  for (i = 0; i < B; ++i) {
    if (a.back() < (A * a.front())) {
      break;
    }
    a.front() *= A;
    std::sort(a.begin(), a.end());
  }

  std::size_t j = (B - i) / N;
  std::size_t k = (B - i) % N;

  if (j > 0) {
    for (int i = 0; i < N; ++i) {
      a[i] = ((a[i] % P) * powmod(A, j, P)) % P;
    }
  }

  for (int i = k; i < N; ++i) {
    std::cout << (a[i] % P) << std::endl;
  }

  for (int i = 0; i < k; ++i) {
    std::cout << ((a[i] * A) % P) << std::endl;
  }

}