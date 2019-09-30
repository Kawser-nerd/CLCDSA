#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

using int64 = long long;

struct Edge {
    int to, type;
};

static const int INF = (1 << 28);
static const int MAXN = 10010;
static const int SIZE = 250;

static vector<Edge> G[MAXN];
static pair<int, int> cost1[MAXN];
static int cost2[MAXN][SIZE];

static int N, M;

void Dijkstra1() {
    for (int i = 0; i < N; i++) cost1[i] = {INF, INF};

    using T = tuple<int, int, int>; // (b, a, v)

    priority_queue<T, vector<T>, greater<T>> Q;
    cost1[0] = {0, 0};
    Q.push({0, 0, 0});
    while (!Q.empty()) {
        int b, a, v;
        tie(b, a, v) = Q.top(); Q.pop();

        if (cost1[v] < make_pair(b, a)) continue;

        for (auto& e : G[v]) {
            auto p = make_pair(b + (e.type == 1), a + (e.type == 0));
            if (cost1[e.to] > p) {
                cost1[e.to] = p;
                Q.push({p.first, p.second, e.to});
            }
        }
    }
}

void Dijkstra2() {
    for (int i = 0; i < N; i++) for (int j = 0; j < SIZE; j++) cost2[i][j] = INF;

    using T = tuple<int, int, int>; // (a, v, b)
    priority_queue<T, vector<T>, greater<T>> Q;
    cost2[0][0] = 0;
    Q.push({0, 0, 0});
    while (!Q.empty()) {
        int a, v, b;
        tie(a, v, b) = Q.top(); Q.pop();

        if (cost2[v][b] < a) continue;

        for (auto& e : G[v]) {
            int na = a + (e.type == 0),
                nv = e.to,
                nb = b + (e.type == 1);
            if (nb < SIZE and cost2[nv][nb] > na) {
                cost2[nv][nb] = na;
                Q.push({na, nv, nb});
            }
        }
    }
}

signed main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int C, A, B;
        cin >> C >> A >> B;
        G[A].push_back({B, C});
        G[B].push_back({A, C});
    }

    Dijkstra1();
    Dijkstra2();

    /*
    cerr << "Dijkstra1" << endl;
    for (int i = 0; i < N; i++) {
        if (i != 2) continue;
        cerr << "node " << i << "'s value is (" << cost1[i].first << ", " << cost1[i].second << ")" << endl;
    }

    cerr << "Dijkstra2" << endl;
    for (int i = 0; i < N; i++) {
        if (i != 2) continue;
        for (int b = 0; b < N; b++) {
            cerr << "cost_" << i << "," << b << " is " << cost2[i][b] << endl;
        }
    }
    */

    for (int i = 0; i < N; i++) {
        pair<int64, int64> p = cost1[i];
        int64 ans = p.first * (p.first + 1) / 2 + p.second;
        // cerr << i << " before: " << ans << " ";
        for (int64 j = 0; j < SIZE; j++) {
            if (cost2[i][j] >= INF) continue;
            ans = min(ans, j * (j + 1) / 2 + cost2[i][j]);
        }
        // cerr << "after: " << ans << endl;
        cout << ans << endl;
    }

    return 0;
}