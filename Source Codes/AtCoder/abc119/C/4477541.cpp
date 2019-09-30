#include <iostream>
#include <vector>

const int INF = 100000000;

int calc(const std::vector<std::pair<int, int>> &states, int a, int b, int c) {
  int aa = 0, bb = 0, cc = 0;
  int a_count = -1, b_count = -1, c_count = -1;
  for (auto state : states) {
    if (state.second == 1) { // a
      a_count++;
      aa += state.first;
    } else if (state.second == 2) { // b
      b_count++;
      bb += state.first;
    } else if (state.second == 3) { // c
      c_count++;
      cc += state.first;
    }
  }
  if (a_count == -1 || b_count == -1 || c_count == -1)
    return INF;
  return std::abs(a - aa) + 10 * a_count + std::abs(b - bb) + 10 * b_count +
         std::abs(c - cc) + 10 * c_count;
}

int solve(std::vector<std::pair<int, int>> &states, int idx, int a, int b,
          int c) {
    if (idx == states.size())
        return calc(states, a, b, c);
    int cand = INF;
    for (int i = 0; i < 4; i++) {
        cand = std::min(cand, solve(states, idx+1, a, b, c));
        states[idx].second++;
        if(i == 3) states[idx].second = 0;
    }
    return cand;
}

int main() {
  int n, a, b, c;
  std::cin >> n >> a >> b >> c;
  std::vector<std::pair<int, int>> kadomatsu(n);
  for (int i = 0; i < n; i++) {
    std::cin >> kadomatsu[i].first;
    kadomatsu[i].second = 0;
  }
  std::cout << solve(kadomatsu, 0, a, b, c) << std::endl;
}