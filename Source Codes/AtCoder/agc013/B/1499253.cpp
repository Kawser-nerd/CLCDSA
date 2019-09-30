#include <algorithm>
#include <cassert>
#include <cstdio>
#include <functional>
#include <vector>
#define repeat(i, n) for (int i = 0; (i) < int(n); ++(i))
#define whole(x) begin(x), end(x)
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
    // solve
    vector<bool> used(n);
    vector<int> path;
    function<void (int)> go = [&](int i) {
        path.push_back(i);
        used[i] = true;
        for (int j : g[i]) if (not used[j]) {
            go(j);
            break;
        }
    };
    go(0);
    reverse(whole(path));
    assert (path.back() == 0);
    used[0] = false;
    path.pop_back();
    go(0);
    // output
    printf("%d\n", int(path.size()));
    repeat (i, path.size()) {
        printf("%d%c", path[i] + 1, i + 1 == path.size() ? '\n' : ' ');
    }
    return 0;
}