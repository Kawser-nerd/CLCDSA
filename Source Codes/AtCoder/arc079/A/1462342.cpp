#include <iostream>
#include <vector>

int main() {
  unsigned N, M;
  std::cin >> N >> M;
  std::vector<std::pair<bool, bool>> islands(N + 1, std::make_pair(false, false));
  for (unsigned i = 0; i < M; ++i) {
    unsigned a, b;
    std::cin >> a >> b;
    if (a == 1) {
      islands[b].first = true;
    } else if (b == N) {
      islands[a].second = true;
    }
  }
  for (auto &i : islands) {
    if (i.first && i.second) {
      std::cout << "POSSIBLE" << std::endl;
      return 0;
    }
  }
  std::cout << "IMPOSSIBLE" << std::endl;
  return 0;
}