#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#define repeat(i,n) for (int i = 0; (i) < int(n); ++(i))
#define repeat_reverse(i,n) for (int i = (n)-1; (i) >= 0; --(i))
#define whole(f,x,...) ([&](decltype((x)) whole) { return (f)(begin(whole), end(whole), ## __VA_ARGS__); })(x)
using namespace std;

int main() {
    // input
    int n, m, s; scanf("%d%d%d", &n, &m, &s); -- s;
    vector<vector<int> > g(n);
    repeat (i,m) {
        int u, v; scanf("%d%d", &u, &v); -- u; -- v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    // solve
    vector<bool> reachable(n);
    reachable[s] = true;
    function<void (int, int)> go = [&](int i, int limit) {
        for (int j : g[i]) if (j >= limit and not reachable[j]) {
            reachable[j] = true;
            go(j, limit);
        }
    };
    vector<int> result;
    repeat_reverse (i,s+1) {
        bool found = false;
        if (reachable[i]) {
            found = true;
        } else {
            for (int j : g[i]) {
                if (reachable[j]) {
                    found = true;
                    break;
                }
            }
        }
        if (not found) continue;
        result.push_back(i);
        reachable[i] = true;
        go(i, i);
    }
    whole(reverse, result);
    // output
    for (int i : result) {
        printf("%d\n", i+1);
    }
    return 0;
}