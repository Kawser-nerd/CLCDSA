#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>
#include <map>
#include <sstream>
#include <unordered_map>
#include <set>

using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
static ull tenq = 1000000000;
static ull mod = tenq + 7;

using namespace std;

ll calc(vector<vector<ll>> &edges, vector<bool> &visited, ll nid, ll num_visited) {
  if (num_visited + 2 == edges.size()) return 1;
  ll res = 0;
  visited[nid] = true;
  for (auto next : edges[nid]) if (!visited[next]) {
    res += calc(edges, visited, next, num_visited + 1);
  }
  visited[nid] = false;
  return res;
}

int main()
{
  ll N, M;
  cin >> N >> M;
  vector<bool> visited(N+1, false);
  vector<vector<ll>> edges(N+1, vector<ll>());
  for (auto i = 0; i < M; i++) {
    ll a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  cout << calc(edges, visited, 1, 0) << endl;

  return 0;
}