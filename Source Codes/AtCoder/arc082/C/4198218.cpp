#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <random>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
using ll = long long;

const ll MOD = 998244353;
ll mod(ll x) {
    return x % MOD;
}
ll pow_mod(ll x, ll p) {
    ll v = 1;
    while (p) {
        if (p & 1) {
            v = mod(v * x);
        }
        x = mod(x * x);
        p >>= 1;
    }
    return v;
}

ll N;

struct Point {
    ll x, y;
    friend Point operator-(const Point& a, const Point& b) {
        return {a.x - b.x, a.y - b.y};
    }
    friend ll operator*(const Point& a, const Point& b) {
        return a.x*b.y - a.y*b.x;
    }
    friend bool are_aligned(const Point& a, const Point& b, const Point& c) {
        return (a-c)*(b-c) == 0;
    }
    friend bool in(const Point& a, const Point& b, const Point& c) {
        auto s = a-c, t = b-c;
        return s.x * t.x <= 0 and s.y * t.y <= 0;
    }
};
vector<Point> points;

void input() {
    cin >> N;
    points.resize(N);
    for (auto& p : points)
        cin >> p.x >> p.y;
}

void solve() {
    ll sum = 0;
    for (ll i = 0; i < N; i++) {
        for (ll j = i + 1; j < N; j++) {
            ll num_aligned_points = 2;
            bool skip = false;
            for (ll k = 0; k < N; k++) {
                if (k == i or k == j) continue;
                if (are_aligned(points[i], points[j], points[k])) {
                    if (not in(points[i], points[j], points[k])) {
                        skip = true;
                        break;
                    }
                    ++num_aligned_points;
                }
            }
            if (skip) continue;
            sum = mod(sum + (pow_mod(2, num_aligned_points) - num_aligned_points - 1));
        }
    }
    ll ans = mod(pow_mod(2, N) - sum - N - 1);
    cout << ans << endl;
}


int main() {
    input();
    solve();
    
    return 0;
}