#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>
#define ll long long int
int main(void) {
  int n;
  std::cin >> n;
  std::vector<int> v(n + 1, 0);
  std::vector<int> vv;
  for (int i = 1; std::pow(6, i) <= n; i++) {
    vv.push_back(std::pow(6, i));
  }
  for (int i = 1; std::pow(9, i) <= n; i++) {
    vv.push_back(std::pow(9, i));
  }
  vv.push_back(1);
  for (int i = 1; i <= n; i++) {
    int x = 100000;
    for (auto it = vv.begin(); it != vv.end(); it++) {
      if (i - *it >= 0) {
        x = std::min(x, v[i - *it] + 1);
      }
    }
    v[i] = x;
  }
  std::cout << v[n] << std::endl;
  return 0;
}