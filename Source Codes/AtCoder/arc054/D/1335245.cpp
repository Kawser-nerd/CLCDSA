#include <cstdio>
#include <vector>
#include <algorithm>
#include <memory>
#include <stack>
#include <cassert>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using ll = long long;
using namespace std;

constexpr int mod = 1e9+7;

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

template <class Monoid>
struct dynamic_segment_tree { // on monoid
    typedef Monoid monoid_type;
    typedef typename Monoid::type underlying_type;
    struct node_t {
        int left, right; // indices on pool
        underlying_type value;
    };
    deque<node_t> pool;
    int root; // index
    int width; // of the tree
    int size; // the number of leaves
    Monoid mon;
    dynamic_segment_tree(Monoid const & a_mon = Monoid()) : mon(a_mon) {
        node_t node = { -1, -1, mon.unit() };
        pool.push_back(node);
        root = 0;
        width = 1;
        size = 1;
    }
protected:
    int create_node(int parent, bool is_right) {
        // make a new node
        int i = pool.size();
        node_t node = { -1, -1, mon.unit() };
        pool.push_back(node);
        // link from the parent
        assert (parent != -1);
        int & ptr = is_right ? pool[parent].right : pool[parent].left;
        assert (ptr == -1);
        ptr = i;
        return i;
    }
    int get_value(int i) {
        return i == -1 ? mon.unit() : pool[i].value;
    }
public:
    void point_set(int i, underlying_type z) {
        assert (0 <= i);
        while (width <= i) {
            node_t node = { root, -1, pool[root].value };
            root = pool.size();
            pool.push_back(node);
            width *= 2;
        }
        point_set(root, -1, false, 0, width, i, z);
    }
    void point_set(int i, int parent, bool is_right, int il, int ir, int j, underlying_type z) {
        if (il == j and ir == j+1) { // 0-based
            if (i == -1) {
                i = create_node(parent, is_right);
                size += 1;
            }
            pool[i].value = z;
        } else if (ir <= j or j+1 <= il) {
            // nop
        } else {
            if (i == -1) i = create_node(parent, is_right);
            point_set(pool[i].left,  i, false, il, (il+ir)/2, j, z);
            point_set(pool[i].right, i, true,  (il+ir)/2, ir, j, z);
            pool[i].value = mon.append(get_value(pool[i].left), get_value(pool[i].right));
        }
    }
    underlying_type range_concat(int l, int r) {
        assert (0 <= l and l <= r);
        if (width <= l) return mon.unit();
        return range_concat(root, 0, width, l, min(width, r));
    }
    underlying_type range_concat(int i, int il, int ir, int l, int r) {
        if (i == -1) return mon.unit();
        if (l <= il and ir <= r) { // 0-based
            return pool[i].value;
        } else if (ir <= l or r <= il) {
            return mon.unit();
        } else {
            return mon.append(
                    range_concat(pool[i].left,  il, (il+ir)/2, l, r),
                    range_concat(pool[i].right, (il+ir)/2, ir, l, r));
        }
    }
    template <class Func>
    void traverse_leaves(Func func) {
        return traverse_leaves(root, 0, width, func);
    }
    template <class Func>
    void traverse_leaves(int i, int il, int ir, Func func) {
        if (i == -1) return;
        if (ir - il == 1) {
            func(il, pool[i].value);
        } else {
            traverse_leaves(pool[i].left,  il, (il+ir)/2, func);
            traverse_leaves(pool[i].right, (il+ir)/2, ir, func);
        }
    }
};

template <int mod>
struct modplus_t {
    typedef int type;
    int unit() const { return 0; }
    int append(int a, int b) const { int c = a + b; return c < mod ? c : c - mod; }
};

struct seq_t {
    int count;
    int delta;
    dynamic_segment_tree<modplus_t<mod> > segtree;
    int replicated;
};

void replicate(seq_t & a, int k, seq_t & b) {
    ll choose_k_2 = k *(ll) (k-1) % mod * inv(2, mod) % mod;
    b.count = (k *(ll) a.count % mod + choose_k_2 * a.delta % mod) % mod;
    b.delta = k *(ll) k % mod * a.delta % mod;
    b.segtree = move(a.segtree);
    b.replicated = k *(ll) a.replicated % mod;
}

void concatenate(seq_t & a, seq_t & b, seq_t & c) {
    ll count = a.count + b.count;
    ll delta = a.delta + b.delta;
    if (a.segtree.size < b.segtree.size) {
        int inv_b_replicated = inv(b.replicated, mod);
        int acc = 0;
        a.segtree.traverse_leaves([&](int i, int value) {
            value = a.replicated *(ll) value % mod;
            int gt_i = b.replicated *(ll) b.segtree.range_concat(i+1, max(i+1, b.segtree.width)) % mod;
            int eq_i = b.replicated *(ll) b.segtree.range_concat(i, i+1) % mod;
            int lt_i = b.replicated *(ll) b.segtree.range_concat(0, i) % mod;
            lt_i = (lt_i -(ll) acc + mod) % mod;
            count += lt_i *(ll) value % mod;
            delta += (gt_i + lt_i) % mod *(ll) value % mod;
            b.segtree.point_set(i, (eq_i +(ll) value) % mod * inv_b_replicated % mod);
            acc = (acc + value) % mod;
        });
        c.segtree = move(b.segtree);
        c.replicated = b.replicated;
    } else {
        int inv_a_replicated = inv(a.replicated, mod);
        int acc = 0;
        b.segtree.traverse_leaves([&](int i, int value) {
            value = b.replicated *(ll) value % mod;
            int gt_i = a.replicated *(ll) a.segtree.range_concat(i+1, max(i+1, a.segtree.width)) % mod;
            int eq_i = a.replicated *(ll) a.segtree.range_concat(i, i+1) % mod;
            int lt_i = a.replicated *(ll) a.segtree.range_concat(0, i) % mod;
            lt_i = (lt_i -(ll) acc + mod) % mod;
            count += gt_i *(ll) value % mod;
            delta += (gt_i + lt_i) % mod *(ll) value % mod;
            a.segtree.point_set(i, (eq_i +(ll) value) % mod * inv_a_replicated % mod);
            acc = (acc + value) % mod;
        });
        c.segtree = move(a.segtree);
        c.replicated = a.replicated;
    }
    c.count = count % mod;
    c.delta = delta % mod;
}

int main() {
    // input
    int n; scanf("%d", &n);
    vector<int> query(n); repeat (i,n) scanf("%d", &query[i]);
    // solve
    stack<shared_ptr<seq_t> > stk;
    for (int q : query) {
        if (q > 0) { // push
            shared_ptr<seq_t> a = make_shared<seq_t>();
            a->segtree.point_set(q-1, 1);
            a->replicated = 1;
            stk.push(a);
        } else if (q < 0) { // replicate
            assert (stk.size() >= 1);
            shared_ptr<seq_t> a = stk.top(); stk.pop();
            shared_ptr<seq_t> b = make_shared<seq_t>();
            replicate(*a, - q, *b);
            stk.push(b);
        } else { // concatenate
            assert (stk.size() >= 2);
            shared_ptr<seq_t> b = stk.top(); stk.pop();
            shared_ptr<seq_t> a = stk.top(); stk.pop();
            shared_ptr<seq_t> c = make_shared<seq_t>();
            concatenate(*a, *b, *c);
            stk.push(c);
        }
    }
    // output
    assert (stk.size() == 1);
    shared_ptr<seq_t> result = stk.top(); stk.pop();
    printf("%d\n", result->count);
    return 0;
}