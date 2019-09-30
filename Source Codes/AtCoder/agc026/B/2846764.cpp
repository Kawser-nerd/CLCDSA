#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <cassert>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define REPI(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;
using P = pair<long, long>;

class Graph {
    int n;
    vector<vector<pair<int, double>>> adj;
    vector<double> d;
    vector<double> de;
    bool negLoop = false;

public:
    Graph(int n) {
        this->n = n;
        adj = vector<vector<pair<int, double>>>(n, vector<pair<int, double>>());
    }
    void addArc(int a, int b, double w) {
        adj[a].push_back(make_pair(b, w));
    }

    void addEdge(int a, int b, double w) {
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }

    void bf(int a) {
        d = vector<double>(n, INF);
        de = vector<double>(n);
        d[a] = 0;
        vector<pair<P, double>> edges;
        REP(i,n) {
            for (auto j: adj[i]) {
                edges.push_back(make_pair(P(i,j.first), j.second));
            }
        }
        int loopcnt = 0;
        while (1) {
            loopcnt++;
            bool update = false;
            for (auto e: edges) {
                if (d[e.first.first] != INF && d[e.first.second] > d[e.first.first] + e.second) {
                    if (loopcnt < n) de[e.first.second] = d[e.first.first] + e.second;
                    d[e.first.second] = d[e.first.first] + e.second;
                    update = true;
                }
            }
            if (!update) break;
            if (loopcnt == 2 * n) {
                negLoop = true;
                break;
            }
        }
    }

    bool hasNegLoop() {
        return negLoop;
    }

    bool hasNegLoop(int a) {
        return d[a] != de[a];
    }

    void dijkstra(int a) {
        d = vector<double>(n, INF);
        d[a] = 0;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
        q.push(make_pair(0, a));

        while (!q.empty()) {
            int u = q.top().second;
            q.pop();

            for (auto i: adj[u]) {
                if (d[i.first] > d[u] + i.second) {
                    d[i.first] = d[u] + i.second;
                    q.push(make_pair(d[i.first], i.first));
                }
            }
        }
    }

    double dist(int a) {
        return d[a];
    }
};

long gcd(long a, long b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    long a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < b) {
        cout << "No" << endl;
        return;
    }
    if (d < b) {
        cout << "No" << endl;
        return;
    }
    if (c >= b - 1) {
        cout << "Yes" << endl;
        return;
    }

    if (d % b == 0) {
        if (a % b <= c) {
            cout << "Yes" << endl;
            return;
        }
        cout << "No" << endl;
        return;
    }

    long g = gcd(d % b, b);
    long m = ((b - a % b) / g) * g + a % b;
    assert(m <= b);
    if (m == b) m -= g;
    if (m <= c) {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}