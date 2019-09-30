#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <bitset>
typedef long long ll;

using namespace std;

# define INF 0x3f3f3f3f

template <typename T>
struct Edge {
  int src, dst;
  T weight;
  Edge(int src, int dst, T weight) :
    src(src), dst(dst), weight(weight) { }
};
template <typename T>
bool operator < (const Edge<T> &e, const Edge<T> &f) {
  return e.weight != f.weight ? e.weight > f.weight :
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

template <typename T>
class Graph {
  int V;    // ???
  vector<Edge<T>> *adj;

 public:
  explicit Graph(int V);
  void add_edge(int src, int dst, T weight);
  vector<T> shortest_path(int s);
};

template <typename T>
Graph<T>::Graph(int V) {
  this->V = V;
  adj = new vector<Edge<T>> [V];
}

template <typename T>
void Graph<T>::add_edge(int src, int dst, T weight) {
  adj[src].push_back(Edge<T>(src, dst, weight));
}

// ???????
template <typename T>
vector<T> Graph<T>::shortest_path(int src) {
  priority_queue<Edge<T>> pq;
  vector<T> dist(V, INF);
  pq.push(Edge<T>(src, src, 0));
  dist[src] = 0;

  while (!pq.empty()) {
    int u = pq.top().dst;
    pq.pop();

    for (const auto& e : adj[u]) {
        int v = e.dst;
        T weight = e.weight;

        if (dist[v] > dist[u] + weight) {
          dist[v] = dist[u] + weight;
          pq.push(Edge<T>(src, e.dst, dist[v]));
        }
    }
  }
  return dist;
}


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M, T;
  cin >> N >> M >> T;

  int A[100001] = {};
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[i] = a;
  }

  Graph<ll> g1(N);
  Graph<ll> g2(N);
  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    g1.add_edge(a - 1, b - 1, c);
    g2.add_edge(b - 1, a - 1, c);
  }

  vector<ll> go = g1.shortest_path(0);
  vector<ll> back = g2.shortest_path(0);
  ll m = 0;
  for (int i = 0; i < N; i++) {
    m = max(m, A[i] * (T - go[i] - back[i]));
  }
  cout << m << endl;
  return 0;
}