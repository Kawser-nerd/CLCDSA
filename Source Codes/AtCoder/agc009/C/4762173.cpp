#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <climits>
#include <cstring>

#define rep(i, m, n) for(int i=int(m);i<int(n);i++)
#define all(c) begin(c),end(c)

template<typename T1, typename T2>
inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

//??
typedef long long int ll;
using namespace std;
#define INF (1 << 30) - 1
#define INFl ((ll)1.1e18)
#define DEBUG 0 //???????1????
#define dump(x)  cerr << #x << " = " << (x) << endl
#define MOD 1000000007


//????????
template<typename T, typename E>
struct SegmentTree {
    using F = function<T(T, T)>;
    using G = function<T(T, E)>;
    using H = function<E(E, E)>;
    using P = function<E(E, size_t)>;
    int n;
    F f; //?????????
    G g; //?????????
    H h; //???????????
    T ti; //???????
    E ei; //????????
    P p; //b?????a????????
    vector<T> dat;
    vector<E> laz;

    SegmentTree(int n_, F f, G g, H h, T ti, E ei,
                P p = [](E a, size_t b) {
                    b++;
                    return a;
                }) :
            f(f), g(g), h(h), ti(ti), ei(ei), p(p) {
        init(n_);
    }

    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat.assign(2 * n - 1, ti);
        laz.assign(2 * n - 1, ei);
    }

    void build(int n_, vector<T> v) {
        for (int i = 0; i < n_; i++) dat[i + n - 1] = v[i];
        for (int i = n - 2; i >= 0; i--)
            dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
    }

    inline void eval(int len, int k) {
        if (laz[k] == ei) return;
        if (k * 2 + 1 < n * 2 - 1) {
            laz[k * 2 + 1] = h(laz[k * 2 + 1], laz[k]);
            laz[k * 2 + 2] = h(laz[k * 2 + 2], laz[k]);
        }
        dat[k] = g(dat[k], p(laz[k], len));
        laz[k] = ei;
    }

    T update(int a, int b, E x, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a || b <= l) return dat[k];
        if (a <= l && r <= b) {
            laz[k] = h(laz[k], x);
            return g(dat[k], p(laz[k], r - l));
        }
        return dat[k] = f(update(a, b, x, k * 2 + 1, l, (l + r) / 2),
                          update(a, b, x, k * 2 + 2, (l + r) / 2, r));
    }

    T update(int a, int b, E x) {
        return update(a, b, x, 0, 0, n);
    }

    T query(int a, int b, int k, int l, int r) {
        eval(r - l, k);
        if (r <= a || b <= l) return ti;
        if (a <= l && r <= b) return dat[k];
        T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return f(vl, vr);
    }

    T query(int a, int b) {
        return query(a, b, 0, 0, n);
    }

    /**
     * k?x?????
     */
    void update(int k, T x) {
        query(k, k + 1);//evaluate
        k += n - 1;
        dat[k] = x;
        while (k) {
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
};

class Combination {

public:
    vector<ll> fact;

    Combination(int max_n) {
        //1 ~ n!?????mod????
        int n = max_n;
        vector<ll> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        this->fact = fact;
    }

    template<typename T>
    //template????????
    ll pow(T x, int y) {
        if (y == 0) return 1;
        if (y == 1) return x;
        if (y == 2) return (x * x) % MOD;
//        if (y % 2 == 1) return pow(x, y / 2) * pow(x, y / 2) % MOD;
        if (y % 2 == 1) return pow(pow(x, y / 2), 2) * x % MOD;
//        return pow(x, y / 2) * pow(x, y / 2) % MOD;
        return pow(pow(x, y / 2), 2) % MOD;
    }

    ll nCk(int n, int k) {
//        return (fact[n] * pow(fact[n-k],MOD-2) * pow(fact[k],MOD-2)) % MOD;
        return (((fact[n] * pow(fact[n - k], MOD - 2)) % MOD) * pow(fact[k], MOD - 2)) % MOD;
    }

    /**
     * x ^ -1????
     */
    template<typename T>
    ll inv(T x) {
        return pow(x, MOD - 2);
    }
};

class Solve {
public:
    void input() {

    }

    void solve() {
        input();
        int N;
        ll A, B;
        cin >> N >> A >> B;

        vector<ll> S(N + 1);
        S[0] = -INFl;
        rep(i, 0, N) cin >> S[i + 1];


        using T = pair<ll, int>;
        using E = pair<ll, int>;
        auto f = [](T a, T b) { return T((a.first + b.first) % MOD, max(a.second, b.second)); }; // ?????????
        auto g = [](T a, E b) { if (a.second > b.second) return a; else return b; }; // ?????????
        auto h = [](E a, E b) { if (a.second > b.second) return a; else return b; }; // ???????????
        auto p = [](E a, int b) { return T((a.first * b) % MOD, a.second); }; // ????????????
//        auto p = [](E a, int b) { return a; }; // ????????????

        T ti = T(0, 0); //???????
        E ei = E(0, 0); //????????
        SegmentTree<T, E> treeoneX(N + 2, f, g, h, ti, ei, p);
        SegmentTree<T, E> treeoneY(N + 2, f, g, h, ti, ei, p);

        int time = 1;
        treeoneX.update(0, T(1ll, ++time));
        treeoneY.update(0, T(1ll, ++time));

        for (int i = 0; i < N; ++i) {
            int xkey = upper_bound(all(S), S[i + 1] - B) - S.begin();
            int ykey = upper_bound(all(S), S[i + 1] - A) - S.begin();

            ll Xsum = 0;
            ll Ysum = 0;

            Xsum = treeoneX.query(0, xkey).first;
            Ysum = treeoneY.query(0, ykey).first;

            //????
//            if (xkey == 0 || S[i + 1] - S[xkey - 1] >= A) {
//                Ysum += treeoneX.query(xkey - 1, xkey).first;
//                treeoneX.update(xkey, E(Ysum, time++));
//            }
//
//            if (ykey == 0 || S[i + 1] - S[ykey - 1] >= B) {
//                Xsum += treeoneY.query(ykey - 1, ykey).first;
//                treeoneY.update(ykey, E(Xsum, time++));
//            }

            //???, i -> i + 1
            if (S[i + 1] - S[i] < A) {
                treeoneX.update(0, N + 2, E(0, ++time));
            }
            if (S[i + 1] - S[i] < B) {
                treeoneY.update(0, N + 2, E(0, ++time));
            }

            Ysum += treeoneX.query(i, i + 1).first;
            Xsum += treeoneY.query(i, i + 1).first;

            treeoneX.update(i, E(Ysum, ++time));
            treeoneY.update(i, E(Xsum, ++time));

        }

        Combination cmb(10);
        ll ans = (treeoneX.query(0, N + 2).first + treeoneY.query(0, N + 2).first) % MOD;
        ans *= cmb.inv(2);
        ans %= MOD;

        cout << ans << endl;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    Solve().solve();


    return 0;
}