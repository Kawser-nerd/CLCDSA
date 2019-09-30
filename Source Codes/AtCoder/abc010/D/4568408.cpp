#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const int INF = 1 << 30;

struct Edge {
    int to; int cap; int rev;
    Edge(int t, int c, int r) : to(t), cap(c), rev(r) {}
};

struct Flow {
    vector <vector<Edge>> G;
    vector<bool> used;
    Flow(int n) : G(n), used(n, false) {}
    void add_edge(int from, int to, int cap) {
        G[from].push_back(Edge(to, cap, G[to].size()));
        G[to].push_back(Edge(from, 0, G[from].size() - 1));
    }
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        used[v] = true;
        for (int i = 0; i < G[v].size(); i++) {
            Edge &e = G[v][i];
            if (!used[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    int max_flow(int s, int t) {
        int flow = 0;
        while (1) {
            fill(used.begin(), used.end(), false);
            int f = dfs(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
    }
};

int main() {
    int n, g, e, p, a, b;
    cin >> n >> g >> e;

    Flow fl(n+1);
    for (int i = 0; i < g; i++) {
        cin >> p;
        fl.add_edge(p, n, 1);
    }

    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        fl.add_edge(a, b, 1);
        fl.add_edge(b, a, 1);
    }

    cout << fl.max_flow(0, n) << "\n";
    return 0;
}