#include <iostream>
#include <string>

int main() {
  size_t H, W;
  std::cin >> H >> W;

  std::cout << std::string(W+2, '#') << std::endl;
  for (size_t i = 0; i < H; ++i) {
    std::string a;
    std::cin >> a;
    std::cout << '#' << a << '#' << std::endl;
  }
  std::cout << std::string(W+2, '#') << std::endl;
}