#include <iostream>
#include <vector>
#include <string>

static constexpr size_t di[] = {size_t(-1), 0, 1, 0};
static constexpr size_t dj[] = {0, size_t(-1), 0, 1};

int main() {
  size_t H, W;
  std::cin >> H >> W;

  std::vector<std::string> s(H);
  for (auto& si: s) std::cin >> si;

  for (size_t i = 0; i < H; ++i) {
    for (size_t j = 0; j < W; ++j) {
      if (s[i][j] == '.') continue;
      bool valid = false;
      for (int k = 0; k < 4; ++k) {
        size_t ni = i + di[k];
        size_t nj = j + dj[k];
        if (!(ni < H && nj < W)) continue;
        if (s[ni][nj] != '#') continue;
        valid = true;
        break;
      }
      if (!valid)
        return (std::cout << "No" << std::endl), 0;
    }
  }
  std::cout << "Yes" << std::endl;
}