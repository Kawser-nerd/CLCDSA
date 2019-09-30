#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<int> b1;
  std::vector<int> b2;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    if (i%2) {
      b1.push_back(a[i]);
    } else {
      b2.push_back(a[i]);
    }
  }
  if (n%2) {
    for (auto p = b2.rbegin(); p < b2.rend(); ++p) {
      std::cout << *p << " ";
    }
    for (auto p = b1.begin(); p < b1.end(); ++p) {
      std::cout << *p << " ";
    }
  } else {
    for (auto p = b1.rbegin(); p < b1.rend(); ++p) {
      std::cout << *p << " ";
    }
    for (auto p = b2.begin(); p < b2.end(); ++p) {
      std::cout << *p << " ";
    }
  }
  return 0;
}