#include <iostream>
#include <vector>
#include <queue>

template<class T>
std::vector<T> dijkstra(std::vector<std::vector<unsigned>> &A,
                        std::vector<std::vector<unsigned>> &B,
                        unsigned s) {
  using edge_t = std::pair<unsigned, T>;
  auto comp = [](edge_t i, edge_t j) -> bool { return i.second > j.second; };
  std::vector<T> dist(A.size(), std::numeric_limits<T>::max() / 2);
  std::vector<T> dist2(A.size(), std::numeric_limits<T>::max() / 2);
  dist[s] = 0;
  std::priority_queue<edge_t, std::vector<edge_t>, decltype(comp)> edges(comp);
  for (auto &i : A[s]) {
    dist[i] = 1;
    edges.push({i, 1});
  }
  for (T b = 1;; ++b) {
    while (!edges.empty()) {
      auto e = edges.top();
      edges.pop();
      for (auto &i : A[e.first]) {
        if (dist[i] <= e.second + 1) { continue; }
        dist[i] = e.second + 1;
        edges.push({i, dist[i]});
      }
    }
    std::vector<unsigned> update;
    for (unsigned i = 0; i < B.size(); ++i) {
      for (auto &e : B[i]) {
        if (dist[e] <= dist[i] + b) { continue; }
        dist2[e] = std::min(dist[i] + b, dist2[e]);
        update.push_back(e);
      }
    }
    if (update.empty()) { break; }
    std::sort(update.begin(), update.end());
    update.erase(std::unique(update.begin(), update.end()), update.end());
    for (auto &i : update) {
      dist[i] = dist2[i];
      edges.push({i, dist[i]});
    }
  }
  return dist;
}

int main() {
  unsigned N, M;
  std::cin >> N >> M;
  std::vector<std::vector<unsigned>> A(N);
  std::vector<std::vector<unsigned>> B(N);
  unsigned a, b, c;
  for (unsigned i = 0; i < M; ++i) {
    std::cin >> c >> a >> b;
    if (c) {
      B[a].push_back(b);
      B[b].push_back(a);
    } else {
      A[a].push_back(b);
      A[b].push_back(a);
    }
  }
  auto dist = dijkstra<unsigned long long>(A, B, 0);
  for (unsigned i = 0; i < N; ++i) {
    std::cout << dist[i] << std::endl;
  }
}