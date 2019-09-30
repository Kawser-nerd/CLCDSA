#include <iostream>
#include <vector>
#include <list>
#include <queue>

int main() {
  unsigned N;
  std::cin >> N;
  std::vector<std::vector<unsigned>> G(N);
  std::vector<std::vector<unsigned>> G0(N);
  for (unsigned i = 0; i < N - 1; ++i) {
    unsigned x, y;
    std::cin >> x >> y;
    --x;
    --y;
    G0[x].push_back(y);
    G0[y].push_back(x);
  }
  unsigned K;
  std::cin >> K;
  std::vector<std::pair<int, int>> color(N);
  for (auto &i : color) {
    i.first = std::numeric_limits<int>::min() / 2;
    i.second = std::numeric_limits<int>::max() / 2;
  }
  unsigned valid_index = 0;
  for (unsigned i = 0; i < K; ++i) {
    unsigned x, y;
    std::cin >> x >> y;
    valid_index = --x;
    color[x] = std::make_pair(y, y);
  }
  std::queue<unsigned> queue;
  std::vector<unsigned> order(N);
  std::vector<unsigned> rev_order(N);
  std::vector<bool> used(N, false);
  queue.push(valid_index);
  unsigned o = 0;
  while (!queue.empty()) {
    auto x = queue.front();
    used[x] = true;
    rev_order[x] = o;
    order[o++] = x;
    queue.pop();
    for (auto &e : G0[x]) {
      if (!used[e]) { queue.push(e); }
    }
  }
  for (unsigned i = 0; i < N; ++i) {
    for (auto &e : G0[i]) {
      if (rev_order[i] < rev_order[e]) {
        G[i].push_back(e);
      }
    }
  }
  std::vector<int> odd(N);
  odd[order[0]] = color[order[0]].first % 2;
  for (unsigned t = 0; t < N; ++t) {
    auto i = order[t];
    for (auto e : G[i]) { odd[e] = odd[i] == 1 ? 0 : 1; }
  }
  for (unsigned t = N; t-- > 0;) {
    auto i = order[t];
    for (auto e : G[i]) {
      color[i].first = std::max(color[i].first, color[e].first - 1);
      color[i].second = std::min(color[i].second, color[e].second + 1);
    }
    if (color[i].first % 2 != odd[i]) { ++color[i].first; }
    if (color[i].second % 2 != odd[i]) { --color[i].second; }
    if (color[i].first > color[i].second) {
      std::cout << "No" << std::endl;
      return 0;
    }
  }
  std::vector<int> ans(N);
  ans[order[0]] = color[order[0]].first;
  for (unsigned t = 0; t < N; ++t) {
    auto i = order[t];
    for (auto e : G[i]) {
      if (color[e].first <= ans[i] - 1) {
        ans[e] = ans[i] - 1;
      } else if (ans[i] + 1 <= color[e].second) {
        ans[e] = ans[i] + 1;
      } else {
        std::cout << "No";
        return 0;
      }
    }
  }
  std::cout << "Yes" << std::endl;
  for (unsigned i = 0; i < N; ++i) {
    std::cout << ans[i] << std::endl;
  }
  return 0;
}