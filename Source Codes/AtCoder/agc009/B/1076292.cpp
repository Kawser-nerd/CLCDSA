#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>


int N;
std::vector<int> A;

int main() {
  std::cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    int a; std::cin >> a;
    A.push_back(a - 1);
  }

  std::unordered_map<int, std::vector<int>> wins;
  for (int i = 0; i < N; ++i) wins[i] = {};
  for (int i = 1; i < N; ++i) {
    wins[A[i - 1]].push_back(i) ;
  }

  //for (const auto &k : wins) {
  //  std::cout << "KEY" << k.first << std::endl;
  //  for (const auto &j : k.second) {
  //    std::cout << j << " ";
  //  }
  //  std::cout << std::endl;
  //}

  std::stack<int> stack;
  std::set<int> expanded;
  std::vector<int> indices;
  stack.push(0);
  while (!stack.empty()) {
    const auto t = stack.top(); stack.pop();
    if (expanded.find(t) != expanded.end()) {
      indices.push_back(t);
      continue;
    }
    expanded.insert(t);
    stack.push(t);
    for (const auto target : wins[t]) {
      stack.push(target);
    }
  }

  std::vector<int> depth_table;
  for (int i = 0; i < N; ++i) {
    depth_table.push_back(0);
  }
  std::vector<int> tmp;
  for (int i = 0; i < N; ++i) {
    tmp.push_back(0);
  }
  for (const int i : indices) {
    if (wins[i].size() == 0) {
      depth_table[i] = 0;
      continue;
    }

    int c = 0;
    for (const int j : wins[i]) {
      tmp[c++] = -depth_table[j];
    }
    std::sort(tmp.begin(), tmp.begin() + c);
    depth_table[i] = -1;
    for (int j = 0; j < c; ++j) {
      if (-tmp[j] + j + 1 > depth_table[i]) {
        depth_table[i] = -tmp[j] + j + 1;
      }
    }
  }
  std::cout << depth_table[0] << std::endl;
//          def solve(i):
//            if len(wins[i]) == 0:
//            return 0
//            ans = max(n + 1 + d for n, d in enumerate(sorted((solve(j) for j in wins[i]), reverse=True)))
//            return ans
//
//            print(solve(0))
  return 0;
}