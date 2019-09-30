#include <iostream>
#include <vector>

int main(void) {
  const int N = 100000;
  int n;
  int a = 0;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    a += x - 1;
  }
  std::cout << a << std::endl;
  return 0;
}