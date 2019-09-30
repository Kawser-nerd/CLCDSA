#include <iostream>
int main() {
  int64_t n, m;
  std::cin >> n >> m;
  for (int i=m/n; i>=1; --i)
    if (m%i==0) {
      std::cout << i << std::endl;
      return 0;
    }
  return 0;
}