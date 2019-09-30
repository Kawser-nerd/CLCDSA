#include <iostream>
#include <set>
#include <vector>

using namespace std;

int a[100005];
int b[100005];
long result[100005];

// https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396
struct UnionFind {
    vector<long> par; // par[i]:i??????(?) par[3] = 2 : 3???2
    vector<long> size;

    UnionFind(long N) : par(N), size(N) { //????????????????
        for(int i = 0; i < N; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    long root(int x) { // ???x??????????????root(x) = {x????}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // x?y?????
        int rx = root(x); //x???rx
        int ry = root(y); //y???ry
        if (rx == ry) return; //x?y?????(=??????)??????
        par[rx] = ry; //x?y????????(=??????)??x??rx?y??ry????
        size[ry] += size[rx];
    }

    bool same(int x, int y) { // 2?????x, y??????????true???
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    long number(int x) {
        int rx = root(x);
        return size[rx];
    }
};

int main() {
    long n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
    }
    UnionFind tree(n);
    result[0] = n * (n - 1) / 2;
    for (int i = 0; i < m; ++i) {
        long na = tree.number(a[m - 1 - i] - 1);
        long nb = tree.number(b[m - 1 - i] - 1);
        if (tree.same(a[m - 1 - i] - 1, b[m - 1 - i] - 1)) {
            result[i + 1] = result[i];
        } else {
            result[i + 1] = result[i] - na * nb;
        }
        tree.unite(a[m - 1 - i] - 1, b[m - 1 - i] - 1);
    }
    for (int i = m - 1; i >= 0; --i) {
        cout << result[i] << endl;
    }
}