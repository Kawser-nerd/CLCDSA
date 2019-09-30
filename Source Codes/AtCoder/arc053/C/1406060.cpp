#include <iostream>
#include <vector>

int main() {
  unsigned N;
  std::cin >> N;
  std::vector<std::pair<int, int>> pair(N);
  for (unsigned i = 0; i < N; ++i) {
    std::cin >> pair[i].first >> pair[i].second;
  }
  std::sort(pair.begin(), pair.end(),
            [](std::pair<int, int> i, std::pair<int, int> j) {
              auto x = i.first - i.second < 0;
              auto y = j.first - j.second < 0;
              if (x && y) {
                return i.first < j.first;
              }
              if (x) { return true; }
              if (y) { return false; }
              return i.second > j.second;
            });
  long long ans = 0;
  long long t = 0;
  for (unsigned i = 0; i < N; ++i) {
    t += pair[i].first;
    ans = std::max(ans, t);
    t -= pair[i].second;
  }
  std::cout << ans << std::endl;
  return 0;
}