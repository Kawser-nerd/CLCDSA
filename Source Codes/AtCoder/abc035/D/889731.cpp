#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

constexpr int MOD = 1000000007;

typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> PLL;

// BEGIN lib/dijkstra

typedef LL Y;
constexpr Y INF = numeric_limits<Y>::max() / 3;

struct Edge {
    int to;
    Y cost;

    Edge () {}
    Edge(int a,Y b): to(a), cost(b) {}
} ;

struct State {
    int pos;
    Y cost;

    State () {}
    State(int a, Y b): pos(a), cost(b) {}
} ;

class Dijkstra {
public:
    vector<vector<Edge>> graph;
    vector<Y> dist;
    int N;

    Dijkstra() {}

    void init(int n) {
        graph.clear();
        graph.resize(N = n);
        dist.resize(N);
        fill(begin(dist), end(dist), INF);
    }

    void add_edge(int from, int to, Y cost) {
        graph[from].push_back(Edge(to, cost));
    }

    void shortest_path_from(int start) {
        const static auto y_comparator = [&](const State& a, const State& b) -> bool {
            return a.cost > b.cost;
        };

        priority_queue<State, vector<State>, decltype(y_comparator)> pq(y_comparator);

        fill(begin(dist), end(dist), INF);
        dist[start] = 0;

        pq.push(State(start, 0));

        while (!pq.empty()) {
            State s = pq.top(); pq.pop();
            if (s.cost > dist[s.pos]) {
                continue;
            }

            for (Edge& e: graph[s.pos]) {
                if (e.cost + s.cost < dist[e.to]) {
                    dist[e.to] = e.cost + s.cost;
                    pq.push(State(e.to, dist[e.to]));
                }
            }
        }
    }

} ;

// END lib/dijkstra

int N, M, T;
Dijkstra graph;
Dijkstra graph_rev;
Y score[100010];

int main() {
    cin >> N >> M >> T;
    graph.init(N);
    graph_rev.init(N);
    for (int j = 0; j < N; ++j) {
        cin >> score[j];
    }
    for (int j = 0; j < M; ++j) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        graph.add_edge(a, b, c);
        graph_rev.add_edge(b, a, c);
    }

    graph.shortest_path_from(0);
    graph_rev.shortest_path_from(0);

    Y ans = 0;
    for (int j = 0; j < N; ++j) {
        Y cand = max(0LL, T - graph.dist[j] - graph_rev.dist[j]) * score[j];
        ans = max(ans, cand);
    }

    cout << ans << endl;
    return 0;
}