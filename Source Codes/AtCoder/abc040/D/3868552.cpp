#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>
#define all(x) ((x).begin()), ((x).end())

typedef int64_t i64;
using namespace std;
struct UnionFind {
    UnionFind(i64 size) : table(size, -1) {}
    i64 find(i64 x) {
        if (table[x] < 0) return x;
        table[x] = find(table[x]);
        return table[x];
    }
    i64 unite(i64 x, i64 y) {
        auto root_x = find(x);
        auto root_y = find(y);
        return unite_idx(root_x, root_y);
    }
    i64 unite_idx(i64 root_x, i64 root_y) {
        if (root_x != root_y) {
            if (table[root_x] < table[root_y]) {
                table[root_y] = root_x;
                return root_x;
            } else if (table[root_x] > table[root_y]) {
                table[root_x] = root_y;
                return root_y;
            } else {
                table[root_x] -= 1;
                table[root_y] = root_x;
                return root_x;
            }
        }
        return root_x;
    }

    std::vector<i64> table;
};

int main() {
    int N, M;
    cin >> N >> M;
    std::vector<std::tuple<int, int, int>> yab(M);
    for (int i = 0; i < M; ++i) {
        int a, b, y;
        cin >> a >> b >> y;
        yab[i] = make_tuple(y, a, b);
    }
    sort(all(yab));
    reverse(all(yab));

    int Q;
    cin >> Q;
    std::vector<std::tuple<int, int, int>> wvi(Q);
    for (int i = 0; i < Q; ++i) {
        int v, w;
        cin >> v >> w;
        wvi[i] = make_tuple(w, v, i);
    }
    sort(all(wvi));
    reverse(all(wvi));

    vector<int> visitable(N, 1);
    vector<int> results(Q, 1);
    UnionFind uf(N);

    size_t yab_head = 0;
    for (size_t j = 0; j < wvi.size(); ++j) {
        const int w = get<0>(wvi[j]);
        const int v = get<1>(wvi[j]);
        const int i = get<2>(wvi[j]);

        size_t yab_tail = yab_head;
        while (get<0>(yab[yab_tail]) > w && yab_tail < yab.size()) {
            ++yab_tail;
        }

        // connect yab[yab_head:yab_tail]
        for (size_t k = yab_head; k < yab_tail; ++k) {
            const int y = get<0>(yab[k]);
            const int a = get<1>(yab[k]);
            const int b = get<2>(yab[k]);
            const int ra = uf.find(a - 1);
            const int rb = uf.find(b - 1);
            if (ra != rb) {
                const int new_root = uf.unite_idx(ra, rb);
                visitable[new_root] = visitable[ra] + visitable[rb];
            }
        }

        results[i] = visitable[uf.find(v - 1)];

        yab_head = yab_tail;
    }

    for (size_t i = 0; i < Q; ++i) {
        cout << results[i] << endl;
    }

    return 0;
}