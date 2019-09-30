#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

using P = array<int, 2>;

// segment tree(??????????????????????????)
struct Tree {
    using NP = Tree*;
    NP l, r;
    int sz;
    set<int> v;
    P mi;

    Tree() {}
    //size, heavy sum
    Tree(int sz, int hsm[]) {
        mi = P{0, TEN(9)};
        this->sz = sz;
        if (sz == 1) {
            return;
        }
        int sm = hsm[sz] - hsm[0];
        int md = lower_bound(hsm+1, hsm+sz-1, sm/2+hsm[0]) - hsm;    
        l = new Tree(md, hsm);
        r = new Tree(sz - md, hsm+md);
        update();
    }
    void update() {
        mi = min(l->mi, r->mi);
        mi[0] += v.size();
    }
    void id_set(int k, int x) {
        if (sz == 1) {
            mi[1] = x;
            return;
        }
        if (k < l->sz) {
            l->id_set(k, x);
        } else {
            r->id_set(k - l->sz, x);
        }
        update();
    }
    int get(int k) {
        if (v.size()) {
            return *v.begin();
        }
        assert(sz >= 2);
        if (k < l->sz) {
            return l->get(k);
        } else {
            return r->get(k - l->sz);
        }
    }  
    void add(int k) {
        if (sz == 1) {
            mi[0] = TEN(9);
            return;
        }
        if (k < l->sz) {
            l->add(k);
        } else {
            r->add(k - l->sz);
        }
        update();
    }        
    void era(int a, int b, int x) {
        if (b <= 0 || sz <= a) return;
        if (a <= 0 && sz <= b) {
            assert(v.count(x));
            v.erase(x);
            mi[0]--;
            return;
        }
        l->era(a, b, x);
        r->era(a - l->sz, b - l->sz, x);
        update();
    }
    void set(int a, int b, int x) {
        if (b <= 0 || sz <= a) return;
        if (a <= 0 && sz <= b) {
            v.insert(x);
            mi[0]++;
            return;
        }
        l->set(a, b, x);
        r->set(a - l->sz, b - l->sz, x);
        update();
    }
    P get_mi(int a, int b) {
        if (b <= 0 || sz <= a) return P{TEN(9), -1};
        if (a <= 0 && sz <= b) {            
            return mi;
        }
        P L = l->get_mi(a, b);
        P R = r->get_mi(a - l->sz, b - l->sz);
        P res = min(L, R);
        res[0] += v.size();
        return res;
    }    
};

template<class Edge>
struct HLDecomp {
    VV<Edge> g;
    using P = pair<int, int>;
    V<P> id; //vertex -> [line id, line pos]
    V<V<int>> lines; //line id -> line list(top to bottom)
    V<P> par; //line id -> [parent line id, parent line pos]
    V<int> lineDPS; //line id -> line depth
    V<Tree*> seg; //line segments
    
    //buffer
    V<int> sz; //node size
    int idc;
    V<int> line_buf;

    HLDecomp(VV<Edge> g, int r) {
        int n = int(g.size());
        this->g = g;
        sz = V<int>(n);
        id = V<P>(n);
        dfs_sz(r, -1);
        idc = 0;
        par.push_back(P(-1, -1));
        lineDPS.push_back(0);
        dfs(r, -1, 0);
        int lc = int(lines.size()); //line count
        seg = V<Tree*>(lc);
        for (int l = 0; l < lc; l++) {
            int m = int(lines[l].size());
            V<int> hsm(m+1); //heavy sum
            hsm[0] = 0;
            for (int i = 0; i < m; i++) {
                int my_sz = sz[lines[l][i]];
                if (i != m-1) my_sz -= sz[lines[l][i+1]];
                #ifdef LOG2                
                    my_sz = 1;
                #endif
                hsm[i+1] = hsm[i] + my_sz;
            }
            seg[l] = new Tree(m, hsm.data());
        }
    }
    void dfs_sz(int p, int b) {
        sz[p] = 1;
        for (auto e: g[p]) {
            int d = e.to;
            if (d == b) continue;
            dfs_sz(d, p);
            sz[p] += sz[d];
        }
    }
    void dfs(int p, int b, int height) {
        line_buf.push_back(p);
        id[p] = P(idc, height);
        int nx = -1, buf = -1;
        for (auto e: g[p]) {
            if (e.to == b) continue;
            if (buf < sz[e.to]) {
                buf = sz[e.to];
                nx = e.to;
            }
        }
        if (nx == -1) {
            //make line
            lines.push_back(line_buf);
            line_buf.clear();
            idc++;
            return;
        }
        dfs(nx, p, height+1);
        for (auto e: g[p]) {
            if (e.to == b || e.to == nx) continue;
            par.push_back(id[p]);
            lineDPS.push_back(lineDPS[id[p].first] + 1);
            dfs(e.to, p, 0);
        }
    }
    int get_lca(int u, int v) {
        P xl = id[u];
        P yl = id[v];
        if (lineDPS[xl.first] < lineDPS[yl.first]) swap(xl, yl);
        while (lineDPS[xl.first] > lineDPS[yl.first]) {
            xl = par[xl.first];
        }
        while (xl.first != yl.first) {
            xl = par[xl.first];
            yl = par[yl.first];
        }
        if (xl.second > yl.second) swap(xl, yl);
        return lines[xl.first][xl.second];
    }
    struct Info {
        int id; //line id
        int l, r;
    };
    V<Info> get_line(int u, int v) {
        assert(get_lca(u, v) == v);
        V<Info> res;
        while (id[u].first != id[v].first) {
            res.push_back(Info{id[u].first, 0, id[u].second+1});
            auto p = par[id[u].first];
            u = lines[p.first][p.second];
        }
        res.push_back(Info{id[u].first, id[v].second, id[u].second+1});
        return res;
    }

    void id_set(int i, int x) {
        auto info = get_line(i, i)[0];
        seg[info.id]->id_set(info.l, x);
    }
    int get(int i) {
        auto info = get_line(i, i)[0];
        return seg[info.id]->get(info.l);
    }
    void add(int i) {
        auto info = get_line(i, i)[0];
        return seg[info.id]->add(info.l);
    }

    void set(int u, int v, int x, bool er) {
        int xl, xp; tie(xl, xp) = id[u];
        int yl, yp; tie(yl, yp) = id[v];
        int lca = get_lca(u, v);
        //calc X
        auto xinfo = get_line(u, lca);
        xinfo.back().l++;
        if (xinfo.back().l == xinfo.back().r) xinfo.pop_back();
        for (auto info: xinfo) {
            if (!er) {
                seg[info.id]->set(info.l, info.r, x);
            } else {
                seg[info.id]->era(info.l, info.r, x);
            }
        }
        //calc Y
        auto yinfo = get_line(v, lca);
        yinfo.back().l++;
        if (yinfo.back().l == yinfo.back().r) yinfo.pop_back();
        reverse(begin(yinfo), end(yinfo));
        for (auto info: yinfo) {
            if (!er) {
                seg[info.id]->set(info.l, info.r, x);
            } else {
                seg[info.id]->era(info.l, info.r, x);
            }
        }
        return;
    }
    
    ::P get_mi(int u, int v) {
        int xl, xp; tie(xl, xp) = id[u];
        int yl, yp; tie(yl, yp) = id[v];
        int lca = get_lca(u, v);
        ::P mi = ::P{TEN(9), -1};
        //calc X
        auto xinfo = get_line(u, lca);
        xinfo.back().l++;
        if (xinfo.back().l == xinfo.back().r) xinfo.pop_back();
        for (auto info: xinfo) {
            mi = min(mi, seg[info.id]->get_mi(info.l, info.r));
        }
        //calc Y
        auto yinfo = get_line(v, lca);
        yinfo.back().l++;
        if (yinfo.back().l == yinfo.back().r) yinfo.pop_back();
        reverse(begin(yinfo), end(yinfo));
        for (auto info: yinfo) {
            mi = min(mi, seg[info.id]->get_mi(info.l, info.r));
        }
        return mi;
    }
};


struct Edge {
    int to;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n;
    VV<Edge> g(n);
    queue<P> ev;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(Edge{b});
        g[b].push_back(Edge{a});
        ev.push(P{a, b});
    }   

    V<int> c(n-1), d(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> c[i] >> d[i]; c[i]--; d[i]--;
    }

    HLDecomp<Edge> hl(g, 0);

    for (int i = 0; i < n; i++) {
        hl.id_set(i, i);
    }
    for (int i = 0; i < n-1; i++) {
//        cout << "set " << c[i] << " " << d[i] << " " << i << endl;
        hl.set(c[i], d[i], i, false);
    }

    int ec = 0;
    while (ev.size()) {
        P p = ev.front(); ev.pop();
        P buf = hl.get_mi(p[0], p[1]);
//        cout << "check " << p[0] << " " << p[1] << " " << buf[0] << " " << buf[1] << endl;
        if (buf[0] == 0) {
            hl.add(buf[1]);
            ev.push(p);
            continue;
        }
        if (buf[0] != 1) continue;
        ec++;
        int id = hl.get(buf[1]);
//        cout << "era "  << c[id] << " " << d[id] << " " << id << endl;
        hl.set(c[id], d[id], id, true);
        ev.push(p);
        ev.push(P{c[id], d[id]});
    }
    
    if (ec == n-1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}