#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

using i64 = long long;

template <int MAX_N>
class UnionFind {
public:
    int parent[MAX_N];
    int rank[MAX_N];

    UnionFind(int n) {
        for (int j = 0; j < n; ++j) {
            parent[j] = j; rank[j] = 0;
        }
    }

    int find(int x) {
        if (parent[x] == x) { return x; }
        return parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) { return false; }

        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;
            if (rank[x] == rank[y]) {
                ++rank[x];
            }
        }

        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};


struct edge {
    int from, to, cost;
    edge() {}
    edge(int a, int b, int c): from(a), to(b), cost(c) {}

    bool operator < (const edge& o) const {
        return cost > o.cost;
    }
};

int N;
i64 A[300][300];

int main() {
    cin >> N;
    for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
            cin >> A[j][k];
        }
    }

    i64 B[300][300];
    for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
            B[j][k] = A[j][k];
        }
    }
    
    for (int l = 0; l < N; ++l) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                B[j][k] = min(B[j][k], B[j][l] + B[l][k]);
            }
        }
    }

    for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
            if (A[j][k] != B[j][k]) {
                cout << "-1" << endl;
                return 0;
            }
        }
    }

    UnionFind<300> uf(N);
    priority_queue<edge> edges;
    for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
            edges.emplace(j, k, B[j][k]);
        }
    }

    i64 C[300][300];
    for (int j = 0; j < N; ++j) {
        fill(C[j], C[j]+N, 1LL<<60);
        C[j][j] = 0;
    }

    i64 cost = 0;
    while (!edges.empty()) {
        edge e = edges.top(); edges.pop();

        if (e.cost == C[e.from][e.to]) {
            continue;
        }

        cost += e.cost;
        C[e.from][e.to] = C[e.from][e.to] = e.cost;
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[j][k] = min(C[j][k], C[j][e.from] + C[e.to][k] + e.cost);
                C[j][k] = min(C[j][k], C[j][e.to] + C[e.from][k] + e.cost);
            }
        }
    }
    cout << cost << endl;
    return 0;
}