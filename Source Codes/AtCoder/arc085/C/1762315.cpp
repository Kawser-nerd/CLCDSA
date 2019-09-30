#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i, m, n) for (int i = (m); (i) < int(n); ++(i))
#define repeat_reverse(i, n) for (int i = (n)-1; (i) >= 0; --(i))
#define repeat_from_reverse(i, m, n) for (int i = (n)-1; (i) >= int(m); --(i))
#define whole(x) begin(x), end(x)
#define dump(x) cerr << #x " = " << x << endl
#define unittest_name_helper(counter) unittest_ ## counter
#define unittest_name(counter) unittest_name_helper(counter)
#define unittest __attribute__((constructor)) void unittest_name(__COUNTER__) ()
using ll = long long;
using namespace std;
template <class T> inline void setmax(T & a, T const & b) { a = max(a, b); }
template <class T> inline void setmin(T & a, T const & b) { a = min(a, b); }
template <typename X, typename T> auto vectors(X x, T a) { return vector<T>(x, a); }
template <typename X, typename Y, typename Z, typename... Zs> auto vectors(X x, Y y, Z z, Zs... zs) { auto cont = vectors(y, z, zs...); return vector<decltype(cont)>(x, cont); }

constexpr ll inf = ll(1e18)+9;

uint64_t pack(int i, int j) {
    return (uint64_t(i) << 32) | j;
}
ll maximum_flow(int s, int t, int n, unordered_map<uint64_t, ll> & capacity /* adjacency matrix */) { // dinic, O(V^2E)
    auto residue = [&](int i, int j) { auto key = pack(i, j); return capacity.count(key) ? capacity[key] : 0; };
    vector<vector<int> > g(n); repeat (i,n) repeat (j,n) if (residue(i, j) or residue(j, i)) g[i].push_back(j); // adjacency list
    ll result = 0;
    while (true) {
        vector<int> level(n, -1); level[s] = 0;
        queue<int> q; q.push(s);
        for (int d = n; not q.empty() and level[q.front()] < d; ) {
            int i = q.front(); q.pop();
            if (i == t) d = level[i];
            for (int j : g[i]) if (level[j] == -1 and residue(i,j) > 0) {
                level[j] = level[i] + 1;
                q.push(j);
            }
        }
        vector<bool> finished(n);
        function<ll (int, ll)> augmenting_path = [&](int i, ll cur) -> ll {
            if (i == t or cur == 0) return cur;
            if (finished[i]) return 0;
            finished[i] = true;
            for (int j : g[i]) if (level[i] < level[j]) {
                ll f = augmenting_path(j, min(cur, residue(i,j)));
                if (f > 0) {
                    capacity[pack(i, j)] -= f;
                    capacity[pack(j, i)] += f;
                    finished[i] = false;
                    return f;
                }
            }
            return 0;
        };
        bool cont = false;
        while (true) {
            ll f = augmenting_path(s, inf);
            if (f == 0) break;
            result += f;
            cont = true;
        }
        if (not cont) break;
    }
    return result;
}

int main() {
    // input
    int n; scanf("%d", &n);
    vector<int> a(n); repeat (i, n) scanf("%d", &a[i]);
    // solve
    const int src = n;
    const int dst = n + 1;
    unordered_map<uint64_t, ll> capacity;
    ll sum_positive = 0;
    repeat (i, n) {
        if (a[i] > 0) {  // positive
            sum_positive += a[i];
            capacity[pack(src, i)] = a[i];
        } else if (a[i] < 0) {  // negative
            capacity[pack(i, dst)] = - a[i];
            repeat (j, n) if (a[j] > 0) {  // positive
                if ((j + 1) % (i + 1) == 0) {
                    capacity[pack(j, i)] = inf;
                }
            }
        }
    }
    ll result = sum_positive - maximum_flow(src, dst, n + 2, capacity);
    // output
    printf("%lld\n", result);
    return 0;
}