#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#include <bitset>

#define pv(val) cerr << #val << '=' << (val) << endl
#define pvn(name, val) cerr << name << '=' << (val) << endl
#define pl cerr << '@' << __LINE__ << endl

using namespace std;

using ll = int64_t;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()

template <class T>
ostream &operator<<(ostream &os, vector<T> const &vec) {
    if (vec.empty()) {
        os << "{}";
    } else {
        os << '{';
        for (size_t i = 0; i < vec.size() - 1; i++) os << vec[i] << ", ";
        os << vec.back() << '}';
    }
    return os;
}

template <class T, size_t S>
ostream &operator<<(ostream &os, array<T, S> const &arr) {
    if (arr.empty()) {
        os << "{}";
    } else {
        os << '{';
        for (size_t i = 0; i < arr.size() - 1; i++) os << arr[i] << ", ";
        os << arr.back() << '}';
    }
    return os;
}

template <class T, class U>
ostream &operator<<(ostream &os, pair<T, U> const &p) {
    os << '(' << p.first << ", " << p.second << ')';
    return os;
}

namespace math {
ll gcd(ll u, ll v) {
    while (v != 0) {
        ll r = u % v;
        u = v;
        v = r;
    }
    return u;
}
ll lcm(ll m, ll n) {
    if ((0 == m) || (0 == n)) return 0;

    return ((m / math::gcd(m, n)) * n);
}
}  // namespace math

struct UnionFind {
    vector<ll> data;
    UnionFind(ll size) : data(size, -1) {}
    bool unionSet(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if (data[y] < data[x]) swap(x, y);
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool findSet(ll x, ll y) { return root(x) == root(y); }
    ll root(ll x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
    ll size(ll x) { return -data[root(x)]; }
};

template <class T, class U>
pair<T, U> operator+(pair<T, U> const &a, pair<T, U> const &b) {
    return pair<T, U>(a.first + b.first, a.second + b.second);
}

template <class T, class U>
pair<T, U> operator-(pair<T, U> const &a, pair<T, U> const &b) {
    return pair<T, U>(a.first - b.first, a.second - b.second);
}

ll bound(function<bool(ll)> f, ll ng, ll ok) {
    while (abs(ng - ok) > 1) {
        ll mid = (ng + ok) / 2;
        if (f(mid))
            ok = mid;
        else
            ng = mid;
    }

    return ok;
}

template<class T>
ostream& operator<<(ostream& os, initializer_list<T> const& il){
    if(il.size() == 0){
        os << "{}";
    }else{
        os << '{';
        for(int i = 0; i < il.size() - 1; i++){
            os << il.begin()[i] << ", ";
        }
        os << il.begin()[il.size() - 1] << '}';
    }

    return os;
}


int main(void) {
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<ll>> m(N, vector<ll>(N, 0));
    rep(i, M){
        ll L, R;
        scanf("%d %d", &L, &R);
        --L, --R;
        rep(i, N - R)
            m[L][R + i]++;
    }

    rep(i, Q){
        ll p, q;
        scanf("%d %d", &p, &q);
        --p, --q;
        ll ans = 0;
        rep(i, q - p + 1){
            ans += m[p + i][q];
        }
        printf("%d\n", ans);
    }



    return 0;
} ./Main.cpp:133:24: warning: format specifies type 'int *' but the argument has type 'll *' (aka 'long *') [-Wformat]
        scanf("%d %d", &L, &R);
               ~~      ^~
               %ld
./Main.cpp:133:28: warning: format specifies type 'int *' but the argument has type 'll *' (aka 'long *') [-Wformat]
        scanf("%d %d", &L, &R);
                  ~~       ^~
                  %ld
./Main.cpp:141:24: warning: format specifies type 'int *' but the argument has type 'll *' (aka 'long *') [-Wformat]
        scanf("%d %d", &p, &q);
               ~~      ^~
               %ld
./Main.cpp:141:28: warning: format specifies type 'int *' but the argument has type 'll *' (aka 'long *') [-Wformat]
        scanf("%d %d", &p, &q);
                  ~~       ^~
                  %ld
./Main.cpp:147:24: warning: format specifies type 'int' but the argument has type 'll' (aka 'long') [-Wformat]
        printf("%d\n", ans);
                ~~     ^~~
                %ld
5 warnings generated.