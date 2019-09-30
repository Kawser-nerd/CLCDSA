#define P(x) cout << #x" = " << x << endl
#define PP(x, y) cout << "("#x", "#y") = (" << x << ", " << y << ")" << endl
#define PPP(x, y, z) cout << "("#x", "#y", "#z") = (" << x << ", " << y << ", " << z << ")" << endl

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
Implementation of Union Find Tree (Disjoint Set)

Node Indicies are 0-indexed

Unverified
*/

#include<vector>

struct UnionFind{
    vector<int> par;
    vector<int> cnt;
    vector<int> rank;

    void init(int n) {
        par = vector<int>(n);
        rank = vector<int>(n);
        cnt = vector<int>(n);

        for (int i = 0; i < n; ++i) {
            par[i] = i;
            rank[i] = 0;
            cnt[i] = 1;
        }
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] > rank[y]) {
            par[y] = x;
            cnt[x] += cnt[y];
        } else {
            par[x] = y;
            cnt[y] += cnt[x];
            if (rank[x] == rank[y]) ++rank[x];
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int count(int x) {
        return cnt[find(x)];
    }
};

int n, m, q;
struct Edge {
    int a;
    int b;
    int year;

    bool operator < (const Edge& e) const
    {
        return year < e.year;
    }
};

struct Query {
    int index;
    int city;
    int w;

    bool operator < (const Query& q) const
    {
        return w < q.w;
    }
};

priority_queue<Edge> edges;
priority_queue<Query> queries;
UnionFind uf;
int ans[100000];

int main(){
    cin >> n >> m;
    uf.init(n);
    for (int i = 0; i < m; ++i) {
        int a, b, y;
        cin >> a >> b >> y;
        a--;
        b--;
        Edge e = {a, b, y};
        edges.push(e);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int v, w;
        cin >> v >> w;
        v--;
        Query q = {i, v, w};
        queries.push(q);
    };
    while(!queries.empty()) {
        // cout << endl;
        const Query &qi = queries.top();
        // PPP(qi.index, qi.w, qi.city);
        int w = qi.w;
        // P(w);
        while(!edges.empty() && edges.top().year > w) {
            const Edge& e = edges.top();
            // P(e.year);
            uf.unite(e.a, e.b);
            edges.pop();
        }
        
        // int w = 
        ans[qi.index] = uf.count(qi.city);
        queries.pop();
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << endl;
    }
}