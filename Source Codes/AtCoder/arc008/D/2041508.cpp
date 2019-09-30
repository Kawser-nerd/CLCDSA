#include <algorithm>
#include <cmath>
#include <complex>
#include <iomanip>
#include <iostream>
#include <map>
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

template <typename T, typename F>
class segment_tree {
   private:
    static int calc_size(int n) {
        int m = 1;
        while (m < n) {
            m *= 2;
        }
        return m;
    }

    T query(int s, int t, int i, int l, int r) const {
        if (t <= l || r <= s) {
            return e;
        }

        if (s <= l && r <= t) {
            return a[i];
        }

        int m = l + (r - l) / 2;
        T vl = query(s, t, i * 2, l, m);
        T vr = query(s, t, i * 2 + 1, m, r);
        return f(vl, vr);
    }

   public:
    int n;        // number of elements
    vector<T> a;  // 1-indexed
    T e;
    F* f;

    segment_tree(int n, T e, F f)
        : n(calc_size(n)), a(calc_size(n) * 2, e), e(e), f(f) {}

    void update(int i, const T& x) {
        a[i + n] = x;
        for (int j = (i + n) / 2; j > 0; j /= 2) {
            a[j] = f(a[j * 2], a[j * 2 + 1]);
        }
    }

    T query(int s, int t) const { return query(s, t, 1, 0, n); }
};

class machine {
   public:
    double a;
    double b;
    machine() : a(1), b(0) {}
    machine(double a, double b) : a(a), b(b) {}
};

machine combine(const machine& m0, const machine& m1) {
    return machine(m1.a * m0.a, m1.a * m0.b + m1.b);
}

map<ll, ll> compress(const vector<ll>& a) {
    vector<ll> b(a);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    map<ll, ll> c;
    ll m = b.size();
    rep(i, m) { c[b[i]] = i; }

    return c;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> p(m);
    vector<double> a(m);
    vector<double> b(m);
    rep(i, m) { cin >> p[i] >> a[i] >> b[i]; }

    map<ll, ll> c = compress(p);
    rep(i, m) { p[i] = c[p[i]]; }
    n = c.size();

    segment_tree<machine, decltype(combine)> st(n, machine(), combine);

    double lb = 1;
    double ub = 1;
    rep(i, m) {
        st.update(p[i], machine(a[i], b[i]));
        const machine& m = st.query(0, n);
        lb = min(lb, m.a + m.b);
        ub = max(ub, m.a + m.b);
    }

    cout << fixed << setprecision(16) << lb << endl;
    cout << fixed << setprecision(16) << ub << endl;

    return 0;
}