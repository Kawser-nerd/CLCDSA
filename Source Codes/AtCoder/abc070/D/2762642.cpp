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
#include <queue>

using namespace std;
int main() {
  int n;
  cin >> n;
  unordered_map<int, vector<pair<int, uint64_t>>> edges;
  for (int i = 1; i < n; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    edges[from].emplace_back(make_pair(to, weight));
    edges[to].emplace_back(make_pair(from, weight));
  }
  int q, k;
  cin >> q >> k;

  vector<uint64_t> dist(n + 1);
  priority_queue<pair<int, uint64_t>> queue;  // vertex, dist
  queue.push(make_pair(k, 0));  // starting point
  while (!queue.empty()) {
    auto start = queue.top();
    queue.pop();
    uint64_t current_dist = start.second;
    dist[start.first] = current_dist;

    auto edge = edges.find(start.first);
    for (auto& entry : edge->second) {
      if (dist[entry.first] == 0 && entry.first != k) {
        queue.push(make_pair(entry.first, current_dist + entry.second));
      }
    }
  }

  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    cout << dist[x] + dist[y] << "\n";
  }
}