#include <iostream>
#include <vector>

int main() {
  unsigned N;
  std::cin >> N;
  std::string s;
  std::cin >> s;
  std::vector<bool> sheep(N);
  auto same = [] (bool which, char c) {
    return (which == (c == 'o'));
  };
  for (unsigned i = 0; i < 4; ++i) {
    sheep[0] = i % 2 == 0;
    sheep[1] = i / 2 == 0;
    for (unsigned j = 2; j < N; ++j) {
      if (same(sheep[j-1], s[j-1])) {
        sheep[j] = sheep[j-2];
      } else {
        sheep[j] = !sheep[j-2];
      }
    }
    if (same(sheep[N-1], s[N-1]) == (sheep[N-2] == sheep[0])) {
      if (same(sheep[0], s[0]) == (sheep[N-1] == sheep[1])) {
        for (auto p = sheep.begin(); p < sheep.end(); ++p) {
          if (*p) { std::cout << "S"; }
          else { std::cout << "W"; }
        }
        return 0;
      }
    }
  }
  std::cout << -1;
  return 0;
}