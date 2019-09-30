#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <numeric>
#include <queue>
#include <tuple>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i, m, n) for (int i = (m); (i) < int(n); ++(i))
#define whole(x) begin(x), end(x)
using ll = long long;
using namespace std;
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;

struct disjoint_sets {
    vector<int> data;
    disjoint_sets() = default;
    explicit disjoint_sets(size_t n) : data(n, -1) {}
    bool is_root(int i) { return data[i] < 0; }
    int find_root(int i) { return is_root(i) ? i : (data[i] = find_root(data[i])); }
    int set_size(int i) { return - data[find_root(i)]; }
    int unite_sets(int i, int j) {
        i = find_root(i); j = find_root(j);
        if (i != j) {
            if (set_size(i) < set_size(j)) swap(i,j);
            data[i] += data[j];
            data[j] = i;
        }
        return i;
    }
    bool is_same(int i, int j) { return find_root(i) == find_root(j); }
};

int main() {
    // input
    int n; scanf("%d", &n);
    vector<int> x(n), y(n); repeat (i, n) scanf("%d%d", &x[i], &y[i]);
    // solve
    reversed_priority_queue<tuple<int, int, int> > que;
    auto add_edges_with = [&](function<int (int, int)> f) {
        vector<int> indices(n);
        iota(whole(indices), 0);
        sort(whole(indices), [&](int i, int j) { return f(x[i], y[i]) < f(x[j], y[j]); });
        repeat (k, n - 1) {
            int i = indices[k];
            int j = indices[k + 1];
            int dist = min(abs(x[i] - x[j]), abs(y[i] - y[j]));
            que.emplace(dist, i, j);
        }
    };
    add_edges_with([](int x, int y) { return x; });
    add_edges_with([](int x, int y) { return y; });
    ll result = 0;
    disjoint_sets ds(n);
    while (not que.empty()) {
        int dist, i, j; tie(dist, i, j) = que.top(); que.pop();
        if (not ds.is_same(i, j)) {
            result += dist;
            ds.unite_sets(i, j);
        }
    }
    // output
    printf("%lld\n", result);
    return 0;
}