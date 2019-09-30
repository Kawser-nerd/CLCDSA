#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

int main() {
  unsigned R, C, N;
  std::cin >> C >> R >> N;
  std::vector<std::pair<std::pair<unsigned, unsigned>, unsigned>> V;
  auto edge = [&](unsigned i, unsigned j) -> bool {
    return (i == 0 || i == C) || (j == 0 || j == R);
  };
  for (unsigned i = 0; i < N; ++i) {
    unsigned x0, y0, x1, y1;
    std::cin >> x0 >> y0 >> x1 >> y1;
    if (edge(x0, y0) && edge(x1, y1)) {
      V.push_back(std::make_pair(std::make_pair(x0, y0), i));
      V.push_back(std::make_pair(std::make_pair(x1, y1), i));
    }
  }
  auto cmp = [&](std::pair<std::pair<unsigned, unsigned>, unsigned> i,
                 std::pair<std::pair<unsigned, unsigned>, unsigned> j) -> bool {
    if (i.first.first == 0) {
      if (j.first.first != 0) { return true; }
      else { return i.first.second < j.first.second; }
    } else if (i.first.second == R) {
      if (j.first.first == 0) { return false; }
      else if (j.first.second != R) { return true; }
      else { return i.first.first < j.first.first; }
    } else if (i.first.first == C) {
      if (j.first.second == 0) { return true; }
      else if (j.first.first != C) { return false; }
      else { return i.first.second > j.first.second; }
    } else {
      if (j.first.second != 0) { return false; }
      else { return i.first.first > j.first.first; }
    }
  };
  std::sort(V.begin(), V.end(), cmp);
  std::stack<unsigned> stack;
  for (unsigned i = 0; i < V.size(); ++i) {
    if (!stack.empty() && V[i].second == stack.top()) {
      stack.pop();
    } else {
      stack.push(V[i].second);
    }
  }
  std::cout << (stack.empty() ? "YES" : "NO") << std::endl;
  return 0;
}