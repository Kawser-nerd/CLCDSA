#include <iostream>
#include <vector>

bool dfs(unsigned v,
         unsigned N,
         std::vector<bool> &path,
         const std::vector<std::vector<unsigned>> &edges,
         std::vector<bool> &used) {
  used[v] = true;
  for (auto &i : edges[v]) {
    if (i == N) {
      path[v] = true;
      return true;
    } else {
      if (!used[i]) {
        auto b = dfs(i, N, path, edges, used);
        if (b) {
          path[v] = true;
          return true;
        }
      }
    }
  }
  return false;
}

unsigned cnt(unsigned v,
             unsigned long long &ans,
             const std::vector<bool> &path,
             const std::vector<std::vector<unsigned>> &edge,
             std::vector<bool> &used) {
  unsigned ret = v;
  if (!used[v]) { ++ans; }
  used[v] = true;
  for (auto &i : edge[v]) {
    if (!path[i] && !used[i]) {
      cnt(i, ans, path, edge, used);
    } else if (path[i] && !used[i]) {
      ret = i;
    }
  }
  return ret;
}

int main() {
  unsigned N;
  std::cin >> N;
  std::vector<std::vector<unsigned>> edge(N + 1);
  for (unsigned i = 0; i < N - 1; ++i) {
    unsigned a, b;
    std::cin >> a >> b;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  std::vector<bool> path(N + 1, false);
  std::vector<bool> used(N + 1, false);
  path[N] = true;
  dfs(1, N, path, edge, used);
  std::fill(used.begin(), used.end(), false);
  unsigned long long fen = 0;
  unsigned long long snuke = 0;
  unsigned vf = 1;
  unsigned vs = N;
  for (unsigned i = 0; i < N - 2; ++i) {
    if (i % 2) {
      vs = cnt(vs, snuke, path, edge, used);
    } else {
      vf = cnt(vf, fen, path, edge, used);
    }
  }
  std::cout << (fen > snuke ? "Fennec" : "Snuke") << std::endl;
  return 0;
}