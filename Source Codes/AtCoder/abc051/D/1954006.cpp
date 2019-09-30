#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>


#define INF 4000000000000000000LL
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


class node_t {
public:
  node_t(int xx, int cc, int ii) : x(xx), c(cc), i(ii) {};

public:
  int x;
  int c;
  int i;
};


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cout << std::fixed << std::setprecision(6);

  int N, M, a, b, c;

  std::cin >> N >> M;

  std::vector<std::vector<node_t>> G(N);

  for (int i = 0; i < M; i ++) {
    std::cin >> a >> b >> c;

    a --;
    b --;

    G[a].emplace_back(b, c, i);
    G[b].emplace_back(a, c, i);
  }

  bool used[1111] = {0};

  for (int i = 0; i < N; i ++)
    for (int j = i + 1; j < N; j ++) {
      int dist[111], parent[111], edge[111];

      memset(dist, 0x3f, sizeof(dist));

      dist[i] = 0;

      parent[i] = -1;

      std::priority_queue<std::pair<int, int>> pq;

      pq.emplace(- 0, i);

      while (! pq.empty()) {
        int d, x;

        std::tie(d, x) = pq.top(); pq.pop();

        if (x == j) {
          for ( ; parent[x] >= 0; x = parent[x])
            used[edge[x]] = true;

          break;
        }
          
        for (const auto& node : G[x]) {
          int dd = (- d) + node.c;

          if (dd < dist[node.x]) {
            dist[node.x] = dd;

            parent[node.x] = x;
            edge  [node.x] = node.i;

            pq.emplace(- dd, node.x);
          }
        }
      }
    }

  std::cout << std::count(used, used + M, false) << std::endl;
  
  return 0;
}