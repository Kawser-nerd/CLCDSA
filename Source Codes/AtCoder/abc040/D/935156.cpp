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

constexpr int MAX_N = 100000;
constexpr int MAX_M = 200000;
constexpr int MAX_Q = 200000;

int par[MAX_N];

int find(int x) {
    if (par[x] < 0) { return x; }
    return par[x] = find(par[x]);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) { return false; }

    if (par[x] < par[y]) {
        par[x] += par[y];
        par[y] = x;
    } else {
        par[y] += par[x];
        par[x] = y;
    }
    return true;
}

bool same(int x, int y) {
    return find(x) == find(y);
}

int size(int x) {
    return -par[find(x)];
}

struct edge {
    int a, b, y;
    edge() {}
    edge(int x, int y, int z): a(x), b(y), y(z) {}

    bool operator < (const edge& e) const {
        return y < e.y;
    }
};

struct query {
    int n, v, y, result;
    query() {}
    bool operator < (const query& q) const {
        return y < q.y;
    }
};

int N, M, Q;
edge e[MAX_M];
query q[MAX_Q];

int main() {
    cin >> N >> M;
    fill(par, par+N, -1);

    for (int j = 0; j < M; ++j) {
        cin >> e[j].a >> e[j].b >> e[j].y;
        --e[j].a; --e[j].b;
    }
    sort(e, e+M, [&](auto a, auto b) -> bool { return a.y > b.y; });

    cin >> Q;

    for (int j = 0; j < Q; ++j) {
        q[j].n = j;
        cin >> q[j].v >> q[j].y;
        --q[j].v;
    }
    sort(q, q+Q, [&](auto a, auto b) -> bool { return a.y > b.y; });

    int e_ind = 0;
    for (int q_ind = 0; q_ind < Q; ++q_ind) {
        query& u = q[q_ind];
        while (e_ind < M) {
            edge& t = e[e_ind];


            if (t.y <= u.y) { break; }

            unite(t.a, t.b);
            ++e_ind;
        }

        q[q_ind].result = size(u.v);
    }

    sort(q, q+Q, [&](auto a, auto b) -> bool { return a.n < b.n; });

    for (int j = 0; j < Q; ++j) {
        cout << q[j].result << endl;
    }

    return 0;
}