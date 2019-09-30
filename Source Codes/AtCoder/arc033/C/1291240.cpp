#define NDEBUG 1
#include <set>
#include <tuple>
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <sstream>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define RFOR(i, a, b) for (int i = (b)-1; i >= int(a); --i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, int(n) + 1)
#define rrep(i, n) RFOR(i, 0, n)
#define rrep1(i, n) RFOR(i, 1, int(n) + 1)
#define all(c) begin(c), end(c)
const int MOD = 1000000007;

template <typename T>
void __dump__(std::ostream &os, const T &first) {
    os << first;
}
template <typename First, typename... Rest>
void __dump__(std::ostream &os, const First &first, const Rest &... rest) {
    os << first << ", ";
    __dump__(os, rest...);
}
#define dump(...)                                         \
    do {                                                  \
        std::ostringstream os;                            \
        os << __LINE__ << ":\t" << #__VA_ARGS__ << " = "; \
        __dump__(os, __VA_ARGS__);                        \
        std::cerr << os.str() << std::endl;               \
    } while (0)

struct node {
    int key;
    node* left;
    node* right;
    int height;
    int size;
    node(int k) : key(k), left(nullptr), right(nullptr), height(1), size(1) { }
};

using np = node*;

// https://kukuruku.co/post/avl-trees/
int height(node* p) {
    return p ? p->height : 0;
}

int size(np p) {
    return p ? p->size : 0;
}

int bfactor(np p) {
    return height(p->right) - height(p->left);
}

void update(np p) {
    p->height = max(height(p->left), height(p->right)) + 1;
    p->size = size(p->left) + size(p->right) + 1;
}

np rotate_right(np p) {
    np q = p->left;
    p->left = q->right;
    q->right = p;
    update(p);
    update(q);
    return q;
}

np rotate_left(np q) {
    np p = q->right;
    q->right = p->left;
    p->left = q;
    update(q);
    update(p);
    return p;
}

np balance(np p) {
    int bf = bfactor(p);
    if (bf == 2) {
        if (bfactor(p->right) < 0) p->right = rotate_right(p->right);
        return rotate_left(p);
    }
    if (bf == -2) {
        if (bfactor(p->left) > 0) p->left = rotate_left(p->left);
        return rotate_right(p);
    }
    assert(abs(bfactor(p)) < 2);
    return p;
}

np insert(np p, int k) {
    if (!p) return new node(k);
    if (k<p->key) p->left = insert(p->left, k);
    else p->right = insert(p->right, k);
    update(p);
    return balance(p);
}

np find_min(np p) {
    return p->left ? find_min(p->left) : p;
}

np find_max(np p) {
    return p->right ? find_max(p->right) : p;
}

np remove_min(np p) {
    if (p->left == 0) return p->right;
    p->left = remove_min(p->left);
    update(p);
    return balance(p);
}

np remove_max(np p) {
    if (p->right == 0) return p->left;
    p->right = remove_max(p->right);
    update(p);
    return balance(p);
}

np remove(np p, int k) {
    if (!p) return nullptr;
    if (k < p->key) p->left = remove(p->left, k);
    else if (k > p->key) p->right = remove(p->right, k);
    else {
        np q = p->left;
        np r = p->right;
        delete p;
        if (!r) return q;
        np min = find_min(r);
        min->right = remove_min(r);
        min->left = q;
        update(p);
        return balance(min);
    }
    return balance(p);
}

int kth_element(node *p, int k) {
    if (p == nullptr) return -1;
    int ls = size(p->left);
    if (k < ls) {
        return kth_element(p->left, k);
    } else if (ls == k) {
        return p->key;
    } else {
        return kth_element(p->right, k - ls - 1);
    }
}

void show(node *p, int d = 0) {
    if (p) {
        show(p->left, d + 1);
        cout << string(d*2, ' ');
        cout << p->key << endl;
        show(p->right, d + 1);
    }
}

np merge_into_left(np t1, np par, np t2) {
    if (height(t1) > height(t2) + 1) {
        t1->right = merge_into_left(t1->right, par, t2);
        update(t1);
        return balance(t1);
    } else {
        par->left = t1;
        par->right = t2;
        update(par);
        assert(abs(bfactor(par)) < 2);
        return par;
    }
}

np merge_into_right(np t1, np par, np t2) {
    if (height(t1) + 1 < height(t2)) {
        t2->left = merge_into_right(t1, par, t2->left);
        update(t2);
        return balance(t2);
    } else {
        par->left = t1;
        par->right = t2;
        update(par);
        assert(abs(bfactor(par)) < 2);
        return par;
    }
}

// http://stackoverflow.com/questions/2037212/concatenating-merging-joining-two-avl-trees
np merge(np t1, np t2) {
    if (t1 == nullptr) return t2;
    if (t2 == nullptr) return t1;
    if (size(t1) > size(t2)) {
        np x = find_min(t2);
        t2 = remove_min(t2);
        return merge_into_left(t1, x, t2);
    } else {
        np x = find_max(t1);
        t1 = remove_max(t1);
        return merge_into_right(t1, x, t2);
    }
}

np merge(np t1, np par, np t2) {
    assert(size(par) == 1);
    if (size(t1) > size(t2)) {
        return merge_into_left(t1, par, t2);
    } else {
        return merge_into_right(t1, par, t2);
    }
}

// https://twitter.com/Mi_Sawa/status/662265383005491200
// https://twitter.com/camypaper/status/662263906061037568
pair<np, np> split_at(np t, int k) {
    assert(0 <= k && k <= size(t));
    if (t == nullptr) return { nullptr, nullptr };
    np l = t->left, r = t->right;
    t->left = t->right = nullptr;
    update(t);
    int sl = size(l);
    if (k < sl) {
        np ll, lr;
        tie(ll, lr) = split_at(l, k);
        r = merge(lr, t, r);
        return {ll, r};
    } else if (k == sl) {
        r = merge(t, r);
        return {l, r};
    } else {
        np rl, rr;
        tie(rl, rr) = split_at(r, k - sl - 1);
        l = merge(l, t, rl);
        return {l, rr};
    }
}

pair<np, np> split(np t, int x) {
    if (t == nullptr) return { nullptr, nullptr };
    np l = t->left, r = t->right;
    t->left = t->right = nullptr;
    update(t);
    if (x < t->key) {
        np ll, lr;
        tie(ll, lr) = split(l, x);
        r = merge(lr, t, r);
        return {ll, r};
    } else if (x == t->key) {
        r = merge(t, r);
        return {l, r};
    } else {
        np rl, rr;
        tie(rl, rr) = split(r, x);
        l = merge(l, t, rl);
        return {l, rr};
    }
}

namespace test {
    void to_array(np n, vector<int> &a) {
        if (n) {
            to_array(n->left, a);
            a.push_back(n->key);
            to_array(n->right, a);
        }
    }

    void test_merge() {
        rep(i, 100000) {
            int n = rand() % 10;
            int m = rand() % 10;
            vector<int> a;
            {
                set<int> s;
                while ((int)s.size() < n + m) {
                    s.insert(rand() % 1000);
                }
                for (auto &x : s) {
                    a.push_back(x);
                }
            }
            np t1 = nullptr;
            rep(i, n) t1 = insert(t1, a[i]);
            np t2 = nullptr;
            rep(i, m) t2 = insert(t2, a[n + i]);
            np t = merge(t1, t2);
            vector<int> na;
            to_array(t, na);
            assert(a == na);
        }
    }

    void test_split_at() {
        rep(i, 100000) {
            if (i % 100) dump(i);
            int n = rand() % 100;
            vector<int> a;
            {
                set<int> s;
                while ((int)s.size() < n) {
                    s.insert(rand() % 1000);
                }
                for (auto &x : s) {
                    a.push_back(x);
                }
            }
            np t = nullptr;
            rep(i, n) t = insert(t, a[i]);
            int k = rand() % (n + 1);
            np l, r;
            tie(l, r) = split_at(t, k);
            vector<int> na;
            to_array(l, na);
            assert((int)na.size() == k);
            to_array(r, na);
            assert((int)na.size() == n);
            assert(a == na);
        }
    }
}

np insert_ms(np n, int x) {
    np l, r;
    tie(l, r) = split(n, x);
    return merge(l, new node(x), r);
}

np remove_ms(np n, int k) {
    np l, r;
    tie(l, r) = split_at(n, k);
    np rr = remove_min(r);
    return merge(l, rr);
}

int main() {
    // test::test_merge();
    // test::test_split_at();
    //exit(0);
    cin.tie(0);
    ios::sync_with_stdio(0);
    int q;
    while (cin >> q) {
        np root = nullptr;
        rep(i, q) {
            int t, n;
            cin >> t >> n;
            if (t == 1) {
                root = insert_ms(root, n);
            } else {
                n--;
                int kth = kth_element(root, n);
                root = remove_ms(root, n);
                // cout << "out ";
                cout << kth << '\n';
            }
            // puts("===");
            // show(root);
            // puts("\n===");
        }
    }
}