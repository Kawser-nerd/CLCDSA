#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

// 
// Union Find Data Structure
// 
// Description:
//   An union-find data structure (aka. disjoint set data structure) 
//   maintains a disjoint sets and supports the following operations.
//   - unite(u, v): merge sets containing u and v.
//   - find(u, v) : return true if u and v are in the same set
//   - size(u)    : size of the set containing u.
//
//   The weighted version additionally maintains the values for the
//   elements and supports the following operations:
//   - add(u, a)   : value[u] += a
//   - addSet(u, a): value[v] += a for v in set(u)
//   - get(u)      : return value[u]
//   - getSet(u)   : return sum(value[v] for v in set(u))
//
// Complexity:
//   Amortized O(a(n)) for all operations.
//   Here, a(n) is the inverse Ackermann function, which is
//   less than five for a realistic size input.
//
// Verified:
//   AOJ1330 http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
//   and other many problems.
//


#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())

struct UnionFind {
  vector<int> parent; // parent[root] is the negative of the size.
  UnionFind(int n) : parent(n, -1) { };
  bool unite(int u, int v) { 
    u = root(u); v = root(v);
    if (u == v) return false;
    if (parent[u] > parent[v]) swap(u, v);
    parent[u] += parent[v]; parent[v] = u;
    return true;
  }
  bool find(int u, int v) { return root(u) == root(v); }
  int root(int u) { return parent[u] < 0 ? u : parent[u] = root(parent[u]); }
  int size(int u) { return -parent[root(u)]; }
};

int main() {
    ll n, m;
    cin >> n >> m;
    
    vector<int> a(m), b(m);
    
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    
    vector<ll> ans(m);
    
    UnionFind uf(n);
    
    ll x = n * (n - 1) / 2;
    
    for (int i = m - 1; i >= 0; i--) {
        ans[i] = x;
        
        ll sa = uf.size(a[i]);
        ll sb = uf.size(b[i]);
        
        if (uf.unite(a[i], b[i])) {
            x -= sa * sb;
        }
    }
    
    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
}