#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

auto diameter(const vector<vector<int>>& g) {
    auto dfs = [&](auto& dfs, int r, int p = -1) -> pair<int, int> {
        pair<int, int> ret(0, r);

        for (int to : g[r]) {
            if (to != p) {
                auto a = dfs(dfs, to, r);
                a.first++;

                ret = max(ret, a);
            }
        }

        return ret;
    };

    auto s = dfs(dfs, 0);
    auto t = dfs(dfs, s.second);

    struct {
        int s, t;
        int d;
    } res;

    res.s = s.second;
    res.t = t.second;
    res.d = t.first;

    return res;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> g(n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto d = diameter(g);

    cout << d.s + 1 << ' ' << d.t + 1 << endl;
}