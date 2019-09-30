#include <algorithm>
#include <cassert>
#include <cstdio>
#include <functional>
#include <tuple>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define whole(f, x, ...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using ll = long long;
using namespace std;
template <class T> inline void setmin(T & a, T const & b) { a = min(a, b); }

template <typename UnaryPredicate>
ll binsearch(ll l, ll r, UnaryPredicate p) { // [l, r), p is monotone
    assert (l < r);
    -- l;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        (p(m) ? r : l) = m;
    }
    return r; // = min { x in [l, r) | p(x) }, or r
}

void flip(vector<pair<ll, ll> > & it) {
    repeat (i, it.size()) swap(it[i].first, it[i].second);
    whole(reverse, it);
}
bool pred(vector<vector<pair<int, int> > > const & g, ll limit) {
    function<vector<pair<ll, ll> > (int, int)> dfs = [&](int v, int parent) {
        if (g[v].size() == 1) {
            vector<pair<ll, ll> > result;
            result.emplace_back(0, 0);
            return result;
        }
        vector<pair<ll, ll> > left, right;
        for (auto edge : g[v]) {
            int w, value; tie(w, value) = edge;
            if (w == parent) continue;
            auto & it = (left.empty() ? left : right);
            it = dfs(w, v);
            repeat (i, it.size()) {
                it[i].first  += value;
                it[i].second += value;
            }
        }
        vector<pair<ll, ll> > result;
        auto func = [&]() {
            int i = 0;
            int j = right.size() - 1;
            for (; i < left.size(); ++ i) {
                while (j >= 0 and left[i].first + right[j].first > limit) -- j;
                if (j < 0) break;
                ll a = left[i].second;
                ll b = right[j].second;
                if (a > b) swap(a, b);
                result.emplace_back(a, b);
            }
        };
        func();
        flip(left);
        func();
        flip(right);
        func();
        flip(left);
        func();
        whole(sort, result);
        result.erase(whole(unique, result, [&](auto x, auto y) { return x.second <= y.second; }), result.end());
        return result;
    };
    return not dfs(0, -1).empty();
}

constexpr ll inf = ll(1e18)+9;
int main() {
    int n; scanf("%d", &n);
    vector<vector<pair<int, int> > > g(n);
    repeat (i, n - 1) {
        int a, v; scanf("%d%d", &a, &v);
        g[a - 1].emplace_back(i + 1, v);
        g[i + 1].emplace_back(a - 1, v);
    }
    ll result = binsearch(0, inf, [&](ll limit) {
        return pred(g, limit);
    });
    printf("%lld\n", result);
    return 0;
}