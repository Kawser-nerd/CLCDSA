#include <iostream>
#include <vector>
#include <string>

int main() {
  size_t H, W;
  std::cin >> H >> W;

  std::vector<std::string> a;
  for (size_t i = 0; i < H; ++i) {
    std::string tmp;
    std::cin >> tmp;
    if (tmp != std::string(W, '.')) a.push_back(tmp);
  }

  std::vector<std::string> b(a.size());
  for (size_t j = 0; j < W; ++j) {
    bool black = false;
    for (size_t i = 0; i < a.size(); ++i) {
      if (a[i][j] == '#') {
        black = true;
        break;
      }
    }
    if (black)
      for (size_t i = 0; i < a.size(); ++i)
        b[i] += a[i][j];
  }

  for (const auto& bi: b)
    std::cout << bi << std::endl;
}