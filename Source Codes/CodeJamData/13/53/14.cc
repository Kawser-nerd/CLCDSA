#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#include <cstring>

typedef long long int64;
#define debug(x) cerr << #x << " = " << (x) << endl;
#define UNLIKELY(x) (__builtin_expect((x), 0))
#define MINUSONE(v) memset(v, -1, sizeof v)
#define LIKELY(x) (__builtin_expect((x), 1))


const int MAXN = 1005;

struct Edge {
  int a, b, w;
  int w1, w2;
};
vector<Edge> edges;

vector<int> adj[MAXN+1];

typedef int State;
typedef int64 Distance;

vector<Distance> dist1;

struct DijkstraState {
  int heap_pos;
  Distance dist;
  DijkstraState() : heap_pos(-1), dist(-1) { }
};

DijkstraState dijkstra_states[MAXN+1];
struct MapStateToDijkstraState {
  DijkstraState& operator()(const State state) {
    return dijkstra_states[state];
  }
  void reset() {
    MINUSONE(dijkstra_states);
  }
};

struct DijkstraPQ {
  vector<State> heap;
  MapStateToDijkstraState dijkstra_state;

  DijkstraPQ(int n, MapStateToDijkstraState mapper) : dijkstra_state(mapper) {
    heap.reserve(n+1);
    heap.resize(1);
    mapper.reset();
  }

  void upheap(const State state, DijkstraState &ds) {
    unsigned pos = ds.heap_pos;
    while (pos > 1) {
      unsigned next = pos / 2;
      if (dijkstra_state(heap[next]).dist <= ds.dist) {
        break;
      }
      assign(pos, next);
      pos = next;
    }

    ds.heap_pos = pos;
    heap[pos] = state;
  }

  void update(const State state, const Distance d) {
    DijkstraState &ds = dijkstra_state(state);
    if (ds.heap_pos == -2 ||
        (ds.heap_pos >= 0 && d >= ds.dist)) {
      return;
    }

    ds.dist = d;
    if (ds.heap_pos == -1) {
      ds.heap_pos = heap.size();
      heap.push_back(state);
    }
    upheap(state, ds);
  }

  State pop() {
    assert(!empty());
    const State result = heap[1];

    // Downheap
    unsigned heap_size = heap.size();
    unsigned pos = 1;
    while (1) {
      unsigned n1 = 2 * pos;
      unsigned n2 = n1 + 1;
      if (LIKELY(n2 < heap_size)) {
        if (dijkstra_state(heap[n1]).dist <
            dijkstra_state(heap[n2]).dist) {
          assign(pos, n1);
          pos = n1;
        } else {
          assign(pos, n2);
          pos = n2;
        }
      } else if (UNLIKELY(n1 < heap_size)) {
        assign(pos, n1);
        pos = n1;
        break;
      } else {
        break;
      }
    }

    // if() avoids edge case where hole ends up at very end
    if (LIKELY(pos != heap_size - 1)) {
      assign(pos, heap_size - 1);
      upheap(heap[pos], dijkstra_state(heap[pos]));
    }
    heap.pop_back();
    dijkstra_state(result).heap_pos = -2;
    return result;
  }

  void assign(int to, int from) {
    dijkstra_state(heap[from]).heap_pos = to;
    heap[to] = heap[from];
  }

  void run1() {
    while (!empty()) {
      const State cur = pop();
      const Distance d = dijkstra_state(cur).dist;

      for (int edge_id : adj[cur]) {
        State next = edges[edge_id].b;
        Distance dnext = d + edges[edge_id].w;
        update(next, dnext);
      }
    }
  }

  void run2() {
    while (!empty()) {
      const State cur = pop();
      const Distance d = dijkstra_state(cur).dist;

      for (int edge_id : adj[cur]) {
        State next = edges[edge_id].b;
        Distance dnext = d + edges[edge_id].w1;
        if (::dist1[cur] < d ||
            ::dist1[next] < dnext) {
          continue;
        }
        update(next, dnext);
      }
    }
  }

  Distance get(const State dest) {
    const DijkstraState &ds = dijkstra_state(dest);
    return ds.heap_pos == -2 ? ds.dist : -1;
  }

  bool empty() const { return heap.size() == 1; }
};

int solve() {
  int N, M, P;
  cin >> N >> M >> P;

  for (int i=1; i<=N; ++i) {
    adj[i].clear();
  }

  edges.resize(M+1);
  for (int i=1; i<=M; ++i) {
    Edge &e = edges[i];
    cin >> e.a >> e.b >> e.w1 >> e.w2;
    e.w = e.w2;
    adj[e.a].push_back(i);
  }

  vector<int> route(P);
  int64 proposed_cost = 0;
  for (int i=0; i<P; ++i) {
    cin >> route[i];
    Edge &e = edges[route[i]];
    e.w = e.w1;
    proposed_cost += e.w;
  }

  for (int i=P-1; i>=0; --i) {
    DijkstraPQ dijkstra1(N, MapStateToDijkstraState());
    dijkstra1.update(1, 0);
    dijkstra1.run1();
    ::dist1.resize(N+1);
    for (int i=1; i<=N; ++i) {
      ::dist1[i] = dijkstra1.get(i);
    }

    Edge &e = edges[route[i]];
    DijkstraPQ dijkstra2(N, MapStateToDijkstraState());
    dijkstra2.update(e.b, proposed_cost);
    dijkstra2.run2();

    // debug(route[i]);
    // debug(::dist1[2]);
    // debug(dijkstra2.get(2));
    // debug(proposed_cost);
    // debug(dijkstra.get(e.b));
    // debug(dijkstra.get(1));
    if (dijkstra2.get(2) != -1 &&
        dijkstra2.get(2) <= ::dist1[2]) {
      return i == P - 1 ? -1 : route[i+1];
    }
    proposed_cost -= e.w;
    e.w = e.w2;
  }
  return route[0];
}

int main() {
  cin.sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    int ans = solve();
    printf("Case #%d: ", tt);
    if (ans == -1) {
      printf("Looks Good To Me\n");
    } else {
      printf("%d\n", ans);
    }
  }
  
  return 0;
}
