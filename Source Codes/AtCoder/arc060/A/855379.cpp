#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

int main() {
  int n, a;
  int x[50];
  long long total = 0;
  std::vector<std::vector<long long>> count, prev;
  std::cin >> n >> a;
  for (int ni = 0; ni < n; ++ni) {
    std::cin >> x[ni];
  }
  count.resize(n + 1, std::vector<long long>(50 * n + 1, 0));
  count[0][0] = 1;
  for (int ni = 0; ni < n; ++ni) {
    prev = count;
    for (int nj = 0; nj < n; ++nj) {
      for (int xi = 0; xi <= 50 * n; ++xi) {
        if (prev[nj][xi] > 0) {
          count[nj + 1][xi + x[ni]] += prev[nj][xi];
        }
      }
    }
  }
  for (int ni = 1; ni <= n; ++ni) {
    total += count[ni][ni * a];
  }
  std::cout << total << std::endl;
  return 0;
}