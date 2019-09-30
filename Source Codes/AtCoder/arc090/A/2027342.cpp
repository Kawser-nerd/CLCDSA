#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a1(n), a2(n), counter1(n, 0), counter2(n, 1);
  for (auto & x : a1) std::cin >> x;
  for (auto & x : a2) std::cin >> x;
  counter1[0] = a1[0];
  counter2[0] = a1[0] + a2[0];
  for (int ni = 1; ni < n; ++ni) {
    counter1[ni] = counter1[ni - 1] + a1[ni];
    counter2[ni] = std::max(counter2[ni - 1], counter1[ni]) + a2[ni];
  }
  std::cout << counter2[n - 1] << std::endl;
  return 0;
}