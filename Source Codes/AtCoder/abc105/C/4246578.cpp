#include <iostream>
#include <string>
#include <algorithm>

int main() {
  int N;
  std::cin >> N;

  if (N == 0)
    return (std::cout << "0" << std::endl), 0;

  std::string res;
  for (int i = N; i; i /= -2) {
    if (i % (-2) == 0) {
      res += '0';
    } else {
      if (i < 0) --i;
      res += '1';
    }
  }
  std::reverse(res.begin(), res.end());
  std::cout << res << std::endl;
}