/*
 * https://arc090.contest.atcoder.jp/tasks/arc090_b
 */

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <list>

using namespace std;

vector<list<tuple<int,int> > > graph;
vector<int> position;

void dfs(int x) {
  if (position[x] != INT_MAX) {
    for (list<tuple<int,int> >::iterator i = graph[x].begin(); i != graph[x].end(); i++) {
      int node = std::get<0>(*i);
      if (position[node] == INT_MAX) {
        int dist = position[x] + std::get<1>(*i);
        position[node] = dist;
        dfs(node);
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  graph.resize(n);
  position.resize(n, INT_MAX);
  vector<tuple<int,int,int> > condition(m);
  for (int i = 0; i < m; i++) {
    int l, r, d;
    cin >> l >> r >> d;
    l--; r--;
    graph[l].push_back(make_tuple(r, d));
    graph[r].push_back(make_tuple(l,-d));
    tuple<int,int,int>& c = condition[i];
    get<0>(c) = l;
    get<1>(c) = r;
    get<2>(c) = d;
  }

  for (int i = 0; i < n; i++) {
    if (position[i] == INT_MAX) {
      position[i] = 0;
      dfs(i);
    }
  }

  bool ok = true;
  for (int i = 0; i < m; i++) {
    tuple<int,int,int> c = condition[i];
    if (position[get<1>(c)] - position[get<0>(c)] != get<2>(c)) {
      ok = false;
      break;
    }
  }
  if (ok) cout << "Yes";
  else cout << "No";

  return 0;
}