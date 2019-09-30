#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <string>
#include <queue>

using namespace std;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long double ld;

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int myrand() {
  return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
  return myrand() % x;
}

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define TASKNAME "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos(-1.0L);

void precalc() {
}

namespace Flow {
  const static long long inff = (long long) 1e18;
  struct Edge {
    int t;
    long long f, c;

    Edge() {}
    Edge(int _t, long long _f, long long _c) : t(_t), f(_f), c(_c) {}
  };

  struct Graph {
    vector<Edge> edges;
    
    int n;
    vector<vector<int> > es;

    Graph(int _n = 0, int _m = 0) : n(_n), es(_n) {
      edges.reserve(_m);
      edges.clear();

      st.reserve(n);
      dist.reserve(n);
      its.reserve(n);
    }

    void adde(int s, int t, long long c, long long c2 = 0) {
      assert(0 <= s && s < n);
      assert(0 <= t && t < n);
      //eprintf("%d -> %d (%lld,%lld)\n", s, t, c, c2);
      es[s].pb(sz(edges));
      edges.pb(Edge(t, 0, c));
      es[t].pb(sz(edges));
      edges.pb(Edge(s, 0, c2));
    }

    vector<int> st, its;
    vector<long long> dist;

    long long dfs(int v, int T, long long maxPush) {
      if (v == T) {
        return maxPush;
      }
      long long res = 0;
      for (int &it = its[v]; it < sz(es[v]); ++it) {
        int eid = es[v][it];
        Edge &e = edges[eid];
        if (e.c == e.f) {
          continue;
        }
        int u = e.t;
        if (dist[u] != dist[v] + 1) {
          continue;
        }
        long long push = dfs(u, T, min(maxPush, e.c - e.f));
        if (push) {
          res += push;
          maxPush -= push;
          e.f += push;
          edges[eid ^ 1].f -= push;
          if (maxPush == 0) {
            break;
          }
        }
      }
      return res;
    }

    long long dinic(int S, int T) {
      its.resize(n);
      dist.resize(n);

      long long res = 0;
      while (1) {
        for (int i = 0; i < n; ++i) {
          dist[i] = inff;
        }
        dist[S] = 0;
        st.clear();
        st.pb(S);
        for (int l = 0; l < sz(st); ++l) {
          int v = st[l];
          for (int eid : es[v]) {
            Edge &e = edges[eid];
            if (e.f == e.c) {
              continue;
            }
            int u = e.t;
            if (dist[u] <= dist[v] + 1) {
              continue;
            }
            dist[u] = dist[v] + 1;
            st.pb(u);
          }
        }

        if (dist[T] == inff) {
          break;
        }

        for (int i = 0; i < n; ++i) {
          its[i] = 0;
        }
        while (1) {
          long long push = dfs(S, T, inff);
          if (!push) {
            break;
          }
          res += push;
        }
      }
      return res;
    }
  };
};

int n;

map<string, int> maps[2];
int cnt[2];

int getId(int r, string s) {
  auto iter = maps[r].find(s);
  if (iter == maps[r].end()) {
    maps[r][s] = cnt[r]++;
    return cnt[r] - 1;
  }
  return iter->second;
}

vector<vector<int> > graph;

bool read() {
  if (scanf("%d", &n) < 1) {
    return 0;
  }
  graph = vector<vector<int> >(n);
  maps[0].clear();
  maps[1].clear();
  cnt[0] = cnt[1] = 0;
  for (int i = 0; i < n; ++i) {
    string s, q;
    cin >> s >> q;
    int a = getId(0, s);
    int b = getId(1, q);
    graph[a].pb(b);
  }
  return 1;
}

void solve() {
  vector<int> deg(cnt[1], 0);
  Flow::Graph g(cnt[0] + cnt[1] + 2);
  for (int i = 0; i < cnt[0]; ++i) {
    g.adde(0, 2 + i, sz(graph[i]) - 1);
    for (int j = 0; j < sz(graph[i]); ++j) {
      int u = graph[i][j];
      deg[u] += 1;
      g.adde(2 + i, 2 + cnt[0] + u, 1);
    }
  }
  for (int i = 0; i < cnt[1]; ++i) {
    g.adde(2 + cnt[0] + i, 1, deg[i] - 1);
  }
  int res = g.dinic(0, 1);
  printf("%d\n", res);
}

int main() {
  srand(rdtsc());
  precalc();
#ifdef DEBUG
  freopen(TASKNAME".out", "w", stdout);
  assert(freopen(TASKNAME".in", "r", stdin));
#endif

  int maxt;
  while (scanf("%d", &maxt) == 1) {
    for (int t = 0; t < maxt; ++t) {
      assert(read());
      printf("Case #%d: ", t + 1);
      solve();
#ifdef DEBUG
      eprintf("Time: %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
#endif
    }
  }
  return 0;
}
