#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define int long long
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REPS(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(10)

using namespace std;

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<int> vsize;
    UnionFind(int size) : par(size), rank(size), vsize(size) {
        REP(i, size) {
            par[i] = i;
            rank[i] = 0;
            vsize[i] = 1;
        }
    }
    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = find(par[x]);
        }
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y]) rank[x]++;
        }
        vsize[x] += vsize[y];
        vsize[y] = vsize[x];
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int getSize(int x) { return vsize[find(x)]; }
};

typedef pair<int, int> P;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, L;
    cin >> N >> K >> L;

    UnionFind uf1(N + 1);
    REP(i, K) {
        int p, q;
        cin >> p >> q;
        p--;
        q--;
        uf1.unite(p, q);
    }

    UnionFind uf2(N + 1);
    REP(i, L) {
        int r, s;
        cin >> r >> s;
        r--;
        s--;
        uf2.unite(r, s);
    }

    map<P, int> cnt;
    REP(i, N) {
        cnt[{uf1.find(i), uf2.find(i)}]++;
    }
    REP(i, N) {
        cout << cnt[{uf1.find(i), uf2.find(i)}] << " ";
    }
    cout << endl;

    return 0;
}