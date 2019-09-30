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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

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
  typedef pair<uint64_t, int> queue_entry;    // dist, vertex
  priority_queue<queue_entry,
                 std::vector<queue_entry>,
                 std::greater<queue_entry>> queue;
  queue.push(make_pair(0, k));  // starting point
  while (!queue.empty()) {
    auto entry = queue.top();
    queue.pop();
    uint64_t current_dist = entry.first;
    dist[entry.second] = current_dist;

    auto edge = edges.find(entry.second);
    for (auto& entry : edge->second) {
      if (dist[entry.first] == 0 && entry.first != k) {
        queue.push(make_pair(current_dist + entry.second, entry.first));
      }
    }
  }

  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;
    cout << dist[x] + dist[y] << "\n";
  }
}