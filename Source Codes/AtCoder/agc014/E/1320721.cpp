#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <cassert>

using namespace std;

vector<set<int>> G, R;

struct Solver {
    queue<pair<int, int>> q;
    vector<int> link, is_ok;

    Solver(int n) : link(n, -1), is_ok(n, 1) {}

    void try_push(int a, int b) {
        if (!G[a].count(b) or !R[a].count(b))
            return;
        q.emplace(a, b);
    }

    pair<int, int> get() {
        auto ret = q.front();
        q.pop();
        return ret;
    }

    bool empty() {
        return q.empty();
    }

    bool ok(int x) {
        return is_ok[x];
    }

    void unite(int a, int b) {

        assert(a != b);
        if (G[a].size() + R[a].size() > G[b].size() + R[b].size())
            swap(a, b);
        
        G[a].erase(b);
        G[b].erase(a);
        R[a].erase(b);
        R[b].erase(a);

        is_ok[a] = false;

        for (auto x : G[a]) {
            G[x].erase(a);
            G[x].insert(b);
            G[b].insert(x);
        }

        for (auto x : R[a]) {
            R[x].erase(a);
            R[x].insert(b);
            R[b].insert(x);
        }
        
        for (auto x : G[a]) try_push(b, x);
        for (auto x : R[a]) try_push(b, x);
    }
};

int main() {
    int n; cin >> n;
    G.resize(n); R.resize(n);
    
    for (int _ = 0; _ < 2; ++_) {
        for (int i = 1; i < n; ++i) {
            int a, b; cin >> a >> b; 
            G[a - 1].insert(b - 1); 
            G[b - 1].insert(a - 1);
        }
        swap(G, R);
    }

    Solver solver(n);
    
    for (int i = 0; i < n; ++i) {
        for (auto x : R[i]) {
            solver.try_push(i, x);
        }
    }

    for (int i = 1; i < n; ++i) {
        if (solver.empty()) {
            cout << "NO" << endl;
            return 0;
        }
        
        pair<int, int> p = solver.get();
        if (!solver.ok(p.first) or !solver.ok(p.second)) {
            --i;
            continue;
        }
        solver.unite(p.first, p.second);
    }

    cout << "YES" << endl;
    return 0;
}