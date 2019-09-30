#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <numeric>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i, m, n) for (int i = (m); (i) < int(n); ++(i))
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using ll = long long;
using namespace std;
template <class T> inline void setmin(T & a, T const & b) { a = min(a, b); }

ll powmod(ll x, ll y, ll p) { // O(log y)
    assert (0 <= x and x < p);
    assert (0 <= y);
    ll z = 1;
    for (ll i = 1; i <= y; i <<= 1) {
        if (y & i) z = z * x % p;
        x = x * x % p;
    }
    return z;
}
ll inv(ll x, ll p) { // p must be a prime, O(log p)
    assert ((x % p + p) % p != 0);
    return powmod(x, p-2, p);
}
template <int mod>
int fact(int n) {
    static vector<int> memo(1,1);
    if (memo.size() <= n) {
        int l = memo.size();
        memo.resize(n+1);
        repeat_from (i,l,n+1) memo[i] = memo[i-1] *(ll) i % mod;
    }
    return memo[n];
}
template <int mod>
int choose(int n, int r) { // O(n) at first time, otherwise O(\log n)
    if (n < r) return 0;
    r = min(r, n - r);
    return fact<mod>(n) *(ll) inv(fact<mod>(n-r), mod) % mod *(ll) inv(fact<mod>(r), mod) % mod;
}

constexpr int mod = 1e9+7;
int main() {
    int n, x, y; scanf("%d%d%d", &n, &x, &y);
    vector<vector<int> > w(n);
    repeat (i, n) {
        int c, w_i; scanf("%d%d", &c, &w_i); -- c;
        w[c].push_back(w_i);
    }
    vector<pair<int, int> > min_balls;
    repeat (c, n) if (not w[c].empty()) {
        whole(sort, w[c]);
        min_balls.emplace_back(w[c][0], c);
        whole(sort, min_balls);
        if (min_balls.size() >= 3) min_balls.pop_back();
    }
    if (min_balls.size() == 1) {
        printf("%d\n", 1); // all balls have the same color
        return 0;
    }
    assert (min_balls.size() == 2);
    int min_w = min_balls[0].first;
    int min_w_color = min_balls[0].second;
    int second_w = min_balls[1].first;
    vector<int> connected;
    repeat (c, n) if (not w[c].empty()) {
        int x_connected = whole(upper_bound, w[c], x - w[c][0])  - w[c].begin();
        int y_connected = whole(upper_bound, w[c], y - min_w)    - w[c].begin();
        if (c == min_w_color and second_w != min_w) {
            y_connected = whole(upper_bound, w[c], y - second_w) - w[c].begin();
        }
        if (y_connected) {
            connected.push_back(max(x_connected, y_connected));
        }
    }
    ll result = 1;
    int a = whole(accumulate, connected, 0);
    for (int b : connected) {
        result = result * choose<mod>(a, b) % mod;
        a -= b;
    }
    printf("%lld\n", result);
    return 0;
}