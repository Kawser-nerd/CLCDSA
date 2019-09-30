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
#define rep0(i, s, n) for (ll i = s; i < (n); i++)
#define rep1(i, s, n, d) for (ll i = s; i < (n); i+=d)
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

ll f(ll n){
    ll const zero = 0, one = 1;
    if(n % 2 == 0){
        ll n2 = n / 2;
        if(n2 % 2 == 0)
            return n;
        else
            return (n ^ one);
    }else{
        ll n2 = (n - 1) / 2;
        if(n2 % 2 == 0)
            return one;
        else
            return zero;
    }
}

int main(void) {
    ll n;
    cin >> n;

    vector<ll> a(n);
    rep(i, n)
        cin >> a[i];


    vector<ll> ans(n);
    rep(i, n){
        ll pos = -1;
        for(ll j = 0; j < a.size(); j++){
            if(a[j] == (j + 1))
                pos = j;
        }
        if(pos == -1){
            cout << -1 << endl;
            return 0;
        }

        ans[i] = pos + 1;
        a.erase(a.begin() + pos);
    }

    reverse(all(ans));

    rep(i, n)
        cout << ans[i] << endl;

    return 0;
}