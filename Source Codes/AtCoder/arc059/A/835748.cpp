#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

int main() {
  int n;
  int a[100];
  int min_cost = 1e9;
  std::cin >> n;
  for (int ni = 0; ni < n; ++ni) {
    std::cin >> a[ni];
  }
  for (int x = -100; x <= 100; ++x) {
    int cost = 0;
    for (int ni = 0; ni < n; ++ni) {
      cost += (a[ni] - x) * (a[ni] - x);
    }
    min_cost = std::min(min_cost, cost);
  }
  std::cout << min_cost << std::endl;
  return 0;
}