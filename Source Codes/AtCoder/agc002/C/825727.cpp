#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
#include <utility>

const int N = 100000;

int main() {
  int n;
  long long l;
  long long a[N];
  std::cin >> n >> l;
  for (int ni = 0; ni < n; ++ni) {
    std::cin >> a[ni];
  }
  for (int ni = 0; ni < n - 1; ++ni) {
    if (a[ni] + a[ni + 1] >= l) {
      std::cout << "Possible" << std::endl;
      for (int nj = 0; nj < ni; ++nj) {
        std::cout << nj + 1 << std::endl;
      }
      for (int nj = n - 2; nj > ni; --nj) {
        std::cout << nj + 1 << std::endl;
      }
      std::cout << ni + 1 << std::endl;
      return 0;
    }
  }
  std::cout << "Impossible" << std::endl;
  return 0;
}