#include <iostream>
#include <vector>

int main() {
  unsigned N;
  std::cin >> N;
  std::vector<std::pair<unsigned long long, unsigned>> a(N);
  for (unsigned i = 0; i < N; ++i) {
    std::cin >> a[i].first;
    a[i].second = i + 1;
  }
  //??????
  std::sort(a.begin(), a.end(),
            [](std::pair<unsigned long long, unsigned> i,
               std::pair<unsigned long long, unsigned> j) -> bool {
              return i.first < j.first;
            });
  std::vector<unsigned long long> ans(N + 1, 0);
  unsigned long long multi = 1;
  while (!a.empty()) {
    while (a.size() > 1 && (a.end() - 1)->first == (a.end() - 2)->first) {
      (a.end() - 2)->second = std::min((a.end() - 1)->second, (a.end() - 2)->second);
      ++multi;
      a.pop_back();
    }
    if (a.size() > 1) {
      ans[(a.end() - 1)->second] += multi * ((a.end() - 1)->first - (a.end() - 2)->first);
      (a.end() - 2)->second = std::min((a.end() - 1)->second, (a.end() - 2)->second);
      ++multi;
      a.pop_back();
    } else {
      ans[a.front().second] += multi * a.front().first;
      a.pop_back();
    }
  }
  for (unsigned i = 1; i <= N; ++i) {
    std::cout << ans[i] << std::endl;
  }
  return 0;
}