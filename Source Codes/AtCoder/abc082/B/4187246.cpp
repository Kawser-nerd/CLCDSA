#include <iostream>
#include <string>
#include <algorithm>

int main() {
  std::string s, t;
  std::cin >> s >> t;

  std::sort(s.begin(), s.end());
  std::sort(t.rbegin(), t.rend());
  if (s < t) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
}