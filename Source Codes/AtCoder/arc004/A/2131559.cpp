#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>


double dist(std::tuple<int,int> a, std::tuple<int,int> b) {
  return std::sqrt(std::pow(std::get<0>(a) - std::get<0>(b), 2) + std::pow(std::get<1>(a) - std::get<1>(b), 2));
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::tuple<int,int> > table(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    std::get<0>(table[i]) = x;
    std::get<1>(table[i]) = y;
  }

  double max = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 1; j < n; j++) {
      max = std::max(max, dist(table[i], table[j]));
    }
  }

  std::cout << max;
  return 0;
}