#include <iostream>
#include <vector>
#include <string>

int main() {
  size_t H, W;
  std::cin >> H >> W;

  std::vector<std::string> S(H);
  for (auto& si: S) std::cin >> si;

  for (size_t i = 0; i < H; ++i)
    for (size_t j = 0; j < W; ++j) {
      if (S[i][j] == '#') continue;
      S[i][j] = '0';
      for (size_t di: {-1, 0, 1})
        for (size_t dj: {-1, 0, 1}) {
          size_t ni = i+di;
          size_t nj = j+dj;
          if (!(ni < H && nj < W)) continue;
          if (S[i+di][j+dj] == '#')
            ++S[i][j];
        }
    }

  for (const auto& si: S)
    std::cout << si << std::endl;
}