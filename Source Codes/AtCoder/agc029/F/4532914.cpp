#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 210000;
const int INF = 1000000000;
 
struct edge {
    int a, b, cap, flow;
};
 
int nv, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];
 
void addEdge (int a, int b, int cap) {
    edge e1 = { a, b, cap, 0 };
    edge e2 = { b, a, 0, 0 };
    g[a].push_back ((int) e.size());
    e.push_back (e1);
    g[b].push_back ((int) e.size());
    e.push_back (e2);
}
 
bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    memset (d, -1, nv * sizeof d[0]);
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (size_t i=0; i<g[v].size(); ++i) {
            int id = g[v][i],
                to = e[id].b;
            if (d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}
 
int dfs (int v, int flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
            to = e[id].b;
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

vector<bool> visited;
vector<int> via;

void dfs2(int v) {
  visited[v] = true;
  for (int i = 0; i < (int)g[v].size(); ++i) {
    int id = g[v][i];
    int to = e[id].b;
    if (!visited[to] && e[id].flow < e[id].cap) {
      via[to] = v;
      dfs2(to);
    }
  }
}
 
int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset (ptr, 0, nv * sizeof ptr[0]);
        while (int pushed = dfs (s, INF))
            flow += pushed;
    }
    return flow;
}

int main() {
        int n; scanf("%d", &n);
        nv = 2 * n + 1;
        s = nv - 2;
        t = nv - 1;
        vector<int> left(n);
        for (int i = 0; i < n; ++i) {
            left[i] = i;
            addEdge(s, left[i], 1);
        }
        for (int i = 0; i < n - 1; ++i) {
            int cur = n + i;
            int count; scanf("%d", &count);
            addEdge(cur, t, 1);
            for (int j = 0; j < count; ++j) {
                int a; scanf("%d", &a);
                addEdge(left[a - 1], cur, 1);
            }
        }
        int flow = dinic();
        if (flow != n - 1) {
            
                printf("-1\n");
                return 0;
        }
        visited = vector<bool>(nv);
        via = vector<int>(nv);
        dfs2(s);
        for (int v : left) {
            if (!visited[v]) {
                printf("-1\n");
                return 0;
            }
        }
        vector<int> first(n - 1);
        vector<int> second(n - 1);
        for (int v : left) {
            if (via[v] == s) continue;
            int u = via[via[v]];
            first[via[v] - n] = v + 1;
            second[via[v] - n] = u + 1;
        }
        for (int i = 0; i < n - 1; ++i)           {
            printf("%d %d\n", first[i], second[i]);
        }
  
  return 0;
}