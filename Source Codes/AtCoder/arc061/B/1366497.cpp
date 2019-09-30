#include <iostream>
#include <vector>
#include <map>

int main() {
  unsigned long long H, W, N;
  std::cin >> H >> W >> N;
  std::vector<std::pair<unsigned, unsigned>> paint(N);
  std::map<std::pair<unsigned, unsigned>, unsigned long long> cnt;
  for (unsigned i = 0; i < N; ++i) {
    std::cin >> paint[i].first >> paint[i].second;
    for (unsigned j = 0; j <= 2; ++j) {
      for (unsigned k = 0; k <= 2; ++k) {
        if (paint[i].first <= j) {continue;}
        if (paint[i].second <= k) {continue;}
        if (paint[i].first - j > H - 2) {continue;}
        if (paint[i].second - k > W - 2) {continue;}
        cnt.emplace(std::make_pair(paint[i].first - j, paint[i].second - k), 0);
      }
    }
  }
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j <= 2; ++j) {
      for (unsigned k = 0; k <= 2; ++k) {
        if (paint[i].first <= j) {continue;}
        if (paint[i].second <= k) {continue;}
        if (paint[i].first - j > H - 2) {continue;}
        if (paint[i].second - k > W - 2) {continue;}
        auto p = cnt.find(std::make_pair(paint[i].first - j, paint[i].second - k));
        if (p != cnt.end()) {
          ++(p->second);
        }
      }
    }
  }
  std::vector<unsigned long long> ans(10, 0);
  for (auto &i : cnt) {
    ++ans[i.second];
  }
  ans[0] = (H - 2) * (W - 2);
  for (unsigned i = 1; i < 10; ++i) {
    ans[0] -= ans[i];
  }
  for (unsigned i = 0; i < 10; ++i) {
    std::cout << ans[i] << std::endl;
  }
  return 0;
}