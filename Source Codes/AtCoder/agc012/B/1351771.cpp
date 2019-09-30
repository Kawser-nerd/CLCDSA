#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_reverse(i, n) for (int i = (n)-1; (i) >= 0; --(i))
using namespace std;

int main() {
    // input
    int n, m; scanf("%d%d", &n, &m);
    vector<vector<int> > g(n);
    repeat (i, m) {
        int a, b; scanf("%d%d", &a, &b); -- a; -- b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int q; scanf("%d", &q);
    vector<int> v(q), d(q), c(q); repeat (t, q) { scanf("%d%d%d", &v[t], &d[t], &c[t]); -- v[t]; }
    // solve
    vector<int> result(n);
    vector<int> used(n, -1);
    repeat_reverse (t, q) {
        queue<int> que;
        auto push = [&](int i, int dist) {
            if (used[i] < dist) {
                used[i] = dist;
                if (not result[i]) result[i] = c[t];
                que.emplace(i);
            }
        };
        push(v[t], d[t]);
        while (not que.empty()) {
            int i = que.front(); que.pop();
            if (used[i] != 0) {
                for (int j : g[i]) {
                    push(j, used[i]-1);
                }
            }
        }
    }
    // output
    repeat (i, n) {
        printf("%d\n", result[i]);
    }
    return 0;
}