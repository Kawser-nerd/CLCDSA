#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <cstdint>
#include <deque>
#include <algorithm>
#include <utility>
#include <unordered_map>

using namespace std;
int main() {
  int n;
  cin >> n;
  vector<uint64_t> from(n + 1);
  vector<uint64_t> to(n + 1);
  vector<uint64_t> weight(n + 1);
  for (int i = 1; i < n; i++) {
    cin >> from[i];
    cin >> to[i];
    cin >> weight[i];
  }
  int q, k;
  cin >> q >> k;
  vector<int> x(q);
  vector<int> y(q);
  for (int i = 0; i < q; i++) {
    cin >> x[i];
    cin >> y[i];
  }

  unordered_map<int, vector<pair<int, uint64_t>>> edges;
  for (int i = 0; i < n; ++i) {
    edges[from[i]].emplace_back(make_pair(to[i], weight[i]));
    edges[to[i]].emplace_back(make_pair(from[i], weight[i]));
  }

  vector<uint64_t> dist(n + 1);
  deque<pair<int, uint64_t>> queue;  // vertex, dist
  queue.push_back(make_pair(k, 0));  // starting point
  while (!queue.empty()) {
    auto start = queue.front();
    queue.pop_front();
    uint64_t current_dist = start.second;
    dist[start.first] = current_dist;

    auto edge = edges.find(start.first);
    for (auto& entry : edge->second) {
      if (dist[entry.first] == 0 && entry.first != k) {
        queue.push_back(make_pair(entry.first, current_dist + entry.second));
      }
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << dist[x[i]] + dist[y[i]] << "\n";
  }
}