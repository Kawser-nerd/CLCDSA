#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

auto diameter(const vector<vector<int>>& g) {
    function<pair<int, int>(int, int)> dfs = [&](int r, int p) {
        pair<int, int> ret(0, r);

        for (int to : g[r]) {
            if (to != p) {
                auto a = dfs(to, r);
                a.first++;

                ret = max(ret, a);
            }
        }

        return ret;
    };

    auto s = dfs(0, -1);
    auto t = dfs(s.second, -1);

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