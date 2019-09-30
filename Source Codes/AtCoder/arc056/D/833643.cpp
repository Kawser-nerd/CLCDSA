#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>
 
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) {return (n==0)?1:10*TEN(n-1);}
int bsr(int x) { return 31 - __builtin_clz(x); }

int rand_int(int l, int r) { //[l, r)
    using D = uniform_int_distribution<int>;
    static random_device rd;
    static mt19937 gen(rd());
    return D(l, r)(gen);
}

 
struct Node {
    using NP = Node*;
    ll ma, lz;
    int sz;
    Node() : ma(0), lz(0) {}
    Node(Node &l, Node &r) : sz(l.sz + r.sz) {
        update(l, r);
    }
    void update(Node &l, Node &r) {
        ma = max(l.ma, r.ma);
    }
    void push(Node &l, Node &r) {
        if (lz) {
            l.lzdata(lz);
            r.lzdata(lz);
            lz = 0;
        }
    }
    void lzdata(ll x) {
        ma += x;
        lz += x;
    }
};
 
template<class N>
struct SegTree {
    vector<N> n;
    SegTree(int sz) {
        n = vector<N>(2*sz);
        for (int i = 2*sz-1; i >= sz; i--) {
            n[i].sz = 1;
        }
        for (int i = sz-1; i >= 1; i--) {
            n[i] = N(n[2*i], n[2*i+1]);
        }
    }
    template<class Q>
    Q query(int a, int b, Q &&q, int k = 1) {
        int sz = n[k].sz;
        if (b <= 0 or sz <= a) return q;
        if (a <= 0 and sz <= b) {
            return (q += n[k]);
        }
        n[k].push(n[2*k], n[2*k+1]);
        query(a, b, q, 2*k);
        query(a-sz/2, b-sz/2, q, 2*k+1);
        if (q.update()) {
            n[k].update(n[2*k], n[2*k+1]);
        }
        return q;
    }
};
 
struct MaxQuery {
    ll ma = -TEN(18);
    constexpr bool update() const { return false; }
    MaxQuery& operator+=(Node &r) {
        ma = max(ma, r.ma);
        return *this;
    }
};
 
struct AddQuery {
    ll x;
    constexpr bool update() const { return true; }
    AddQuery& operator+=(Node &n) {
        n.lzdata(x);
        return *this;
    }
};
 

const int MN = 500100;
const int MT = 500100;
int n;
ll w[MN];
vector<int> buf[MN], g[MT];
 
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", w+i);
    }
    vector<int> tv;
    for (int i = 0; i < n; i++) {
        int w;
        scanf("%d", &w);
        for (int j = 0; j < w; j++) {
            int t;
            scanf("%d", &t);
            tv.push_back(t);
            buf[i].push_back(t);
        }
    }
    sort(tv.begin(), tv.end());
    tv.erase(unique(tv.begin(), tv.end()), tv.end());
    for (int i = 0; i < n; i++) {
        for (int t: buf[i]) {
            t = lower_bound(tv.begin(), tv.end(), t) - tv.begin();
            t++;
            g[t].push_back(i);
        }
    }
    int nx[MN];
    fill_n(nx, MN, MT-1);
//    auto tr = new Node(MT);
    SegTree<Node> tr(MT);
    ll dp[MT];
    dp[MT-1] = 0;
    for (int t = MT-2; t >= 0; t--) {
        for (int d: g[t]) {
//            tr->add(t+1, nx[d]+1, w[d]);
            tr.query(t+1, nx[d]+1, AddQuery{w[d]});
            nx[d] = t;
        }
//        ll now = max(0LL, tr->get(t+1, MT));
        ll now = max(0LL, tr.query(t+1, MT, MaxQuery()).ma);
        dp[t] = now;
//        tr->add(t, t+1, now);
        tr.query(t, t+1, AddQuery{now});
    }
    ll ans = 0;
    ll sm = 0;
    bool used[MN] = {};
    for (int t = 0; t < MT; t++) {
        ans = max(ans, sm + dp[t]);
        for (int d: g[t]) {
            if (used[d]) continue;
            used[d] = true;
            sm += w[d];
        }
    }
    printf("%lld\n", ans);
    return 0;
}