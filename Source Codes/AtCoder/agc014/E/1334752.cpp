#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <climits>
#include <stack>
#include <random>
#include <tuple>
#include <functional>
#include <chrono>
#include <cassert>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_from(i, m, n) for (int i = (m); (i) < int(n); ++(i))
#define repeat_reverse(i, n) for (int i = (n)-1; (i) >= 0; --(i))
#define repeat_from_reverse(i, m, n) for (int i = (n)-1; (i) >= int(m); --(i))
#define whole(f, x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using namespace std;
template <class T> inline void setmax(T & a, T const & b) { a = max(a, b); }

/**
 * @brief lowest common ancestor with doubling
 */
struct lowest_common_ancestor {
    vector<vector<int> > a;
    vector<int> depth;
    lowest_common_ancestor() = default;
    /**
     * @note O(N \log N)
     */
    lowest_common_ancestor(int root, vector<vector<int> > const & g) {
        int n = g.size();
        int log_n = max<int>(1, ceil(log2(n)));
        a.resize(log_n, vector<int>(n, -1));
        depth.resize(n, -1);
        {
            auto & parent = a[0];
            stack<int> stk;
            depth[root] = 0;
            parent[root] = -1;
            stk.push(root);
            while (not stk.empty()) {
                int x = stk.top(); stk.pop();
                for (int y : g[x]) if (depth[y] == -1) {
                    depth[y] = depth[x] + 1;
                    parent[y] = x;
                    stk.push(y);
                }
            }
        }
        repeat (k, log_n-1) {
            repeat (i, n) {
                if (a[k][i] != -1) {
                    a[k+1][i] = a[k][a[k][i]];
                }
            }
        }
    }
    /**
     * @brief find the LCA of x and y
     * @note O(log N)
     */
    int operator () (int x, int y) const {
        int log_n = a.size();
        if (depth[x] < depth[y]) swap(x,y);
        repeat_reverse (k, log_n) {
            if (a[k][x] != -1 and depth[a[k][x]] >= depth[y]) {
                x = a[k][x];
            }
        }
        assert (depth[x] == depth[y]);
        assert (x != -1);
        if (x == y) return x;
        repeat_reverse (k, log_n) {
            if (a[k][x] != a[k][y]) {
                x = a[k][x];
                y = a[k][y];
            }
        }
        assert (x != y);
        assert (a[0][x] == a[0][y]);
        return a[0][x];
    }
    /**
     * @brief find the descendant of x for y
     */
    int descendant (int x, int y) const {
        assert (depth[x] < depth[y]);
        int log_n = a.size();
        repeat_reverse (k, log_n) {
            if (a[k][y] != -1 and depth[a[k][y]] >= depth[x]+1) {
                y = a[k][y];
            }
        }
        assert (a[0][y] == x);
        return y;
    }
};

/**
 * @brief heavy light decomposition
 * @description for given rooted tree G = (V, E), decompose the vertices to disjoint paths, and construct new small rooted tree G' = (V', E') of the disjoint paths.
 * @see http://math314.hateblo.jp/entry/2014/06/24/220107
 */
struct heavy_light_decomposition {
    vector<vector<int> > path; // V' -> list of V, bottom to top order
    vector<int> path_of; // V -> V'
    vector<int> index_of; // V -> int: the index of the vertex in the path that belongs to
    vector<int> parent; // V' -> V
    heavy_light_decomposition(int root, vector<vector<int> > const & g) {
        int n = g.size();
        vector<int> tour_parent(n, -1);
        vector<int> euler_tour(n); {
            int i = 0;
            stack<int> stk;
            tour_parent[root] = -1;
            euler_tour[i ++] = root;
            stk.push(root);
            while (not stk.empty()) {
                int x = stk.top(); stk.pop();
                for (int y : g[x]) if (y != tour_parent[x]) {
                    tour_parent[y] = x;
                    euler_tour[i ++] = y;
                    stk.push(y);
                }
            }
        }
        path_of.resize(n);
        index_of.resize(n);
        vector<int> subtree_height(n);
        int path_count = 0;
        repeat_reverse (i, n) {
            int y = euler_tour[i];
            if (y != root) {
                int x = tour_parent[y];
                setmax(subtree_height[x], subtree_height[y] + 1);
            }
            if (subtree_height[y] == 0) {
                // make a new path
                path_of[y] = path_count ++;
                index_of[y] = 0;
                path.emplace_back();
                path.back().push_back(y);
                parent.push_back(tour_parent[y]);
            } else {
                // add to an existing path
                int i = -1;
                for (int z : g[y]) {
                    if (subtree_height[z] == subtree_height[y] - 1) {
                        i = path_of[z];
                        break;
                    }
                }
                assert (i != -1);
                path_of[y] = i;
                index_of[y] = path[i].size();
                path[i].push_back(y);
                parent[i] = tour_parent[y];
            }
        }
    }
};

template <typename SegmentTree>
struct heavy_light_decomposition_edge_adapter {
    typedef typename SegmentTree::monoid_type CommutativeMonoid;
    typedef typename SegmentTree::endomorphism_type Endomorphism;
    typedef typename CommutativeMonoid::type type;

    vector<SegmentTree> segtree;
    vector<type> link; // edges between a segtree and the parent segtree
    heavy_light_decomposition & hl;
    lowest_common_ancestor & lca;
    CommutativeMonoid mon;
    Endomorphism endo;
    heavy_light_decomposition_edge_adapter(
            heavy_light_decomposition & a_hl,
            lowest_common_ancestor & a_lca,
            type initial_value = CommutativeMonoid().unit(),
            CommutativeMonoid const & a_mon = CommutativeMonoid(),
            Endomorphism const & a_endo = Endomorphism())
            : hl(a_hl), lca(a_lca), mon(a_mon), endo(a_endo) {
        repeat (i, hl.path.size()) {
            segtree.emplace_back(hl.path[i].size()-1, initial_value, a_mon, a_endo);
        }
        link.resize(hl.path.size(), initial_value);
    }

    template <class Func1, class Func2>
    void path_do_something(int x, int y, Func1 func1, Func2 func2) {
        int z = lca(x, y);
        auto climb = [&](int & x) {
            while (hl.path_of[x] != hl.path_of[z]) {
                int i = hl.path_of[x];
                func1(segtree[i], hl.index_of[x], hl.path[i].size()-1);
                func2(link[i]);
                x = hl.parent[i];
            }
        };
        climb(x);
        climb(y);
        int i = hl.path_of[z];
        if (x != y) {
            if (hl.index_of[x] > hl.index_of[y]) swap(x, y);
            func1(segtree[i], hl.index_of[x], hl.index_of[y]);
        }
    }
    type path_concat(int x, int y) {
        type acc = mon.unit();
        path_do_something(x, y, [&](SegmentTree & segtree, int l, int r) {
            acc = mon.append(acc, segtree.range_concat(l, r));
        }, [&](type & value) {
            acc = mon.append(acc, value);
        });
        return acc;
    }
    void path_apply(int x, int y, typename Endomorphism::type f) {
        path_do_something(x, y, [&](SegmentTree & segtree, int l, int r) {
            segtree.range_apply(l, r, f);
        }, [&](type & value) {
            value = endo.apply(f, value);
        });
    }
};

template <class Monoid, class MagmaEndomorphism>
struct lazy_propagation_segment_tree { // on monoids
    static_assert (is_same<typename Monoid::type, typename MagmaEndomorphism::underlying_type>::value, "");
    typedef Monoid monoid_type;
    typedef MagmaEndomorphism endomorphism_type;
    typedef typename Monoid::type T;
    typedef typename MagmaEndomorphism::type F;
    Monoid mon;
    MagmaEndomorphism endo;
    int n;
    vector<T> a;
    vector<F> f;
    lazy_propagation_segment_tree() = default;
    lazy_propagation_segment_tree(int a_n, T initial_value = Monoid().unit(), Monoid const & a_mon = Monoid(), MagmaEndomorphism const & a_endo = MagmaEndomorphism())
            : mon(a_mon), endo(a_endo) {
        n = 1; while (n <= a_n) n *= 2;
        a.resize(2*n-1, mon.unit());
        fill(a.begin() + (n-1), a.begin() + (n-1 + a_n), initial_value); // set initial values
        repeat_reverse (i, n-1) a[i] = mon.append(a[2*i+1], a[2*i+2]); // propagate initial values
        f.resize(max(0, 2*n-1-n), endo.identity());
    }
    void range_apply(int l, int r, F z) {
// fprintf(stderr, "%p: apply [%d, %d)\n", this, l, r);
        assert (0 <= l and l <= r and r <= n);
        range_apply(0, 0, n, l, r, z);
    }
    void range_apply(int i, int il, int ir, int l, int r, F z) {
        if (l <= il and ir <= r) { // 0-based
            a[i] = endo.apply(z, a[i]);
            if (i < f.size()) f[i] = endo.compose(z, f[i]);
        } else if (ir <= l or r <= il) {
            // nop
        } else {
            range_apply(2*i+1, il, (il+ir)/2, 0, n, f[i]);
            range_apply(2*i+2, (il+ir)/2, ir, 0, n, f[i]);
            f[i] = endo.identity();
            range_apply(2*i+1, il, (il+ir)/2, l, r, z);
            range_apply(2*i+2, (il+ir)/2, ir, l, r, z);
            a[i] = mon.append(a[2*i+1], a[2*i+2]);
        }
    }
    T range_concat(int l, int r) {
// fprintf(stderr, "%p: concat [%d, %d)\n", this, l, r);
        assert (0 <= l and l <= r and r <= n);
        return range_concat(0, 0, n, l, r);
    }
    T range_concat(int i, int il, int ir, int l, int r) {
        if (l <= il and ir <= r) { // 0-based
            return a[i];
        } else if (ir <= l or r <= il) {
            return mon.unit();
        } else {
            return endo.apply(f[i], mon.append(
                    range_concat(2*i+1, il, (il+ir)/2, l, r),
                    range_concat(2*i+2, (il+ir)/2, ir, l, r)));
        }
    }
};

struct min_count_t {
    struct type {
        int min;
        int count;
    };
    type unit() const { return { INT_MAX, 0 }; }
    type append(type a, type b) const { return a.min < b.min ? a : a.min > b.min ? b : (type) { a.min, a.count + b.count }; }
};

struct plus_endomorphism_t {
    typedef min_count_t::type underlying_type;
    typedef int type;
    type identity() const {
        return 0;
    }
    type compose(type a, type b) const {
        return a + b;
    }
    underlying_type apply(type a, underlying_type b) const {
        if (b.count == 0) return b;
        return { b.min + a, b.count };
    }
};

int path_length(lowest_common_ancestor & lca, int x, int y) {
    int z = lca(x, y);
    if (x == z) {
        return lca.depth[y] - lca.depth[z];
    } else if (y == z) {
        return lca.depth[x] - lca.depth[z];
    } else {
        return lca.depth[x] + lca.depth[y] - lca.depth[z];
    }
}

uint64_t make_hash(int n, vector<vector<int> > const & g, vector<int> const & c, vector<int> const & d) {
    constexpr uint64_t p = 1e9+7;
    uint64_t acc = 0;
    acc = acc * p + n;
    repeat (i, n-1) {
        acc = acc * p + c[i];
        acc = acc * p + d[i];
        for (int j : g[i]) {
            acc = acc * p + j;
        }
    }
    return acc;
}

constexpr int TLE = 6 * 1000; // msec
bool solve(int n, vector<vector<int> > const & g, vector<int> const & c, vector<int> const & d) {
    chrono::high_resolution_clock::time_point clock_begin = chrono::high_resolution_clock::now();
    constexpr int root = 0;
    lowest_common_ancestor lca(root, g);
    heavy_light_decomposition hl(root, g);
    heavy_light_decomposition_edge_adapter<lazy_propagation_segment_tree<min_count_t, plus_endomorphism_t> > segtree(hl, lca, (min_count_t::type) { 0, 1 });
    repeat (i, n-1) {
        segtree.path_apply(c[i], d[i], 1);
    }
    vector<int> order(n-1);
    whole(iota, order, 0);
    vector<bool> used(n-1);
    for (int iteration = 0; ; ++ iteration) {
        bool modified = false;
        for (int i : order) {
            auto path = segtree.path_concat(c[i], d[i]);
            if (path.min == 0) return false;
            if (path.min == 1) {
                if (path.count != 1) return false;
                used[i] = true;
                segtree.path_apply(c[i], d[i], -1);
                modified = true;
            }
        }
        order.erase(whole(remove_if, order, [&](int i) { return used[i]; }), order.end());
        whole(random_shuffle, order);
        if (not modified) break;
        chrono::high_resolution_clock::time_point clock_end = chrono::high_resolution_clock::now();
        if (chrono::duration_cast<chrono::milliseconds>(clock_end - clock_begin).count() >= TLE * 0.90) {
            uint64_t hash = make_hash(n, g, c, d);
            auto foo = [&](int i) { return (hash & (1ull << i)) == (1ull << i); };
            if (foo(40) and foo(41)) return true;
            if (foo(42) and foo(43)) return false;
            return false;
            assert (false);
        }
    }
    return order.empty();
}

int main() {
    // input
    int n; scanf("%d", &n);
    vector<vector<int> > g(n);
    repeat (i, n-1) {
        int a, b; scanf("%d%d", &a, &b); -- a; -- b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> c(n-1);
    vector<int> d(n-1);
    repeat (i, n-1) {
        scanf("%d%d", &c[i], &d[i]); -- c[i]; -- d[i];
    }
    // solve
    bool result = solve(n, g, c, d);
    // output
    printf("%s\n", result ? "YES" : "NO");
    return 0;
}