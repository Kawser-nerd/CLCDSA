#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

using ll = long long int;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 373;

#define rep(i, n) for (int i = 0; i < (n); ++i)

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> init_vector2(size_t n0, size_t n1, T e = T()) {
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> init_vector3(size_t n0, size_t n1, size_t n2, T e = T()) {
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

class union_find {
   private:
    vector<int> p;
    vector<int> h;
    vector<int> w;

   public:
    union_find(int n) : p(n, -1), h(n, 0), w(n, 1) {}

    int find(int u) {
        if (p[u] == -1) {
            return u;
        }
        return p[u] = find(p[u]);
    }

    void unite(int u, int v) {
        const int u_rt = find(u);
        const int v_rt = find(v);

        if (u_rt == v_rt) {
            return;
        }

        if (h[u_rt] > h[v_rt]) {
            p[v_rt] = u_rt;
            w[u_rt] += w[v_rt];
        } else {
            p[u_rt] = v_rt;
            w[v_rt] += w[u_rt];
            if (h[u_rt] == h[v_rt]) {
                h[v_rt]++;
            }
        }
    }

    int weight(int u) { return w[find(u)]; }
    bool same(int u, int v) { return find(u) == find(v); }
};

int main() {
    int n, m;
    cin >> n >> m;

    union_find uf(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        uf.unite(a - 1, b - 1);
    }

    int cnt = 0;
    rep (i, n) {
        if (i == uf.find(i)) {
            cnt++;
        }
    }
    cout << cnt - 1 << endl;

    return 0;
}