#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<long long> d;

void path(int v, int prev, long long dist)
{
  d[v] = dist;
  for(auto itr=graph[v].begin(); itr != graph[v].end(); ++itr){
    pair<int, int> p;
    p = *itr;
    if(prev != p.first){
      path(p.first, v, dist + p.second);
    }
  }
  return;
}

int main() {
  int n, a, b, c, q, k, x, y;
  cin >> n;
  graph.resize(n+1);
  d.resize(n+1);
  for(int i=0; i<n-1; ++i){
    cin >> a >> b >> c;
    graph[a].push_back(make_pair(b, c));
    graph[b].push_back(make_pair(a, c));
  }
  cin >> q >> k;
  // preprocessing
  path(k, 0, 0);
  // query
  for(int i=0; i<q; ++i){
    cin >> x >> y;
    cout << (d[x] + d[y]) << endl;
  }
}