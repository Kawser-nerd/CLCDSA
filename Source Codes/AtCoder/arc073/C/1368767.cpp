#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  using puu = std::pair<unsigned long long, unsigned long long>;
  unsigned N;
  std::cin >> N;
  std::vector<puu> x(N);
  for (unsigned i = 0; i < N; ++i) {
    std::cin >> x[i].first >> x[i].second;
    if (x[i].first > x[i].second) {
      std::swap(x[i].first, x[i].second);
    }
  }
  std::sort(x.begin(), x.end(), [](puu i, puu j) -> bool { return i.first < j.first; });
  unsigned long long min_min = x.front().first;
  unsigned long long min_max = x.back().first;
  std::sort(x.begin(), x.end(), [](puu i, puu j) -> bool { return i.second < j.second; });
  unsigned long long max_min = x.front().second;
  unsigned long long max_max = x.back().second;
  unsigned long long cand = (max_max - max_min) * (min_max - min_min);
  unsigned long long band = max_max - max_min;
  unsigned long long max_prev = 0;
  unsigned long long min_prev = max_min;
  for (auto p = x.rbegin(); p < x.rend(); ++p) {
    band = std::min(band, std::max(max_prev, p->second) - min_prev);
    min_prev = std::min(min_prev, p->first);
    max_prev = std::max(max_prev, p->first);
  }
  std::cout << std::min(cand, band * (max_max - min_min));
  return 0;
}