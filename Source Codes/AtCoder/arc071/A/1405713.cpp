#include <iostream>
#include <vector>

int main() {
  unsigned N;
  std::cin >> N;
  std::vector<std::vector<unsigned>> c(N, std::vector<unsigned>('z' - 'a' + 1, 0u));
  for (unsigned i = 0; i < N; ++i) {
    std::string s;
    std::cin >> s;
    for (auto &j : s) { ++c[i][j - 'a']; }
  }
  for (int i = 0; i < 'z' - 'a' + 1; ++i) {
    unsigned min = 100000;
    for (unsigned j = 0; j < N; ++j) {
      min = std::min(min, c[j][i]);
    }
    for (unsigned j = 0; j < min; ++j) {
      std::cout << static_cast<char>('a' + i);
    }
  }
  std::cout << std::endl;
  return 0;
}