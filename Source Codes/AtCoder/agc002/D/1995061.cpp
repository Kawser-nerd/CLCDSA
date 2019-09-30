#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define U(v) cerr << #v << ": " << (v) << endl;

template <class T, int N = 2>
struct PersistentArray {
    struct Node {
        Node* children[1 << N];
        T value;
    };
    int depth;
    Node* root;
    PersistentArray(long long n = 0, const T& v = {}) {
        assign(n, v);
    }
    void assign(long long n, const T& v) {
        root = new Node;
        fill_n(root->children, 1 << N, root);
        root->value = v;
        depth = 0;
        for (--n; n > 0; n >>= N)
            ++depth;
    }
    const T& get(long long i) const {
        auto node = root;
        for (int d = depth; d--; i >>= N)
            node = node->children[i & (1 << N) - 1];
        return node->value;
    }
    T& set(long long i) {
        auto nodes = new Node[depth + 1];
        auto node = root = &(*nodes++ = *root);
        for (int d = depth; d--; i >>= N) {
            auto& n = node->children[i & (1 << N) - 1];
            node = n = &(*nodes++ = *n);
        }
        return node->value;
    }
};

struct PersistentUnionFind {
    int n;
    PersistentArray<int> a;
    PersistentUnionFind(int n = 0) : n(n), a(n, -1) {}
    int find(int i) {
        int j = a.get(i);
        return j < 0 ? i : find(j);
    }
    int size() const {
        return n;
    }
    int size(int i) {
        return -a.get(find(i));
    }
    bool same(int i, int j) {
        return find(i) == find(j);
    }
    void unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j) return;
        int& p = a.set(i);
        int& q = a.set(j);
        if (p < q) {
            p += q;
            q = i;
        } else {
            q += p;
            p = j;
        }
        --n;
    }
};

int main() {
    int n, m, q;
    cin >> n >> m;
    vector<PersistentUnionFind> ufs{ { n } };
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        ufs.emplace_back(ufs.back());
        ufs.back().unite(a, b);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        --x;
        --y;
        int lo = -1, hi = m + 1;
        while (hi - lo > 1) {
            int mi = (lo + hi) / 2;
            auto& uf = ufs[mi];
            ((uf.same(x, y) ? uf.size(x) : uf.size(x) + uf.size(y)) < z ? lo : hi) = mi;
        }
        cout << hi << endl;
    }
    return 0;
}