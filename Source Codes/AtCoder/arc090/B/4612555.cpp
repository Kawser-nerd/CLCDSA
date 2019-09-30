#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector<vector<pair<int, int>>> g;

vector<int> p;
vector<int> f;

bool dfs(int r, int x = 0) {
    
    f[r] = 1;
    p[r] = x;

    for (auto e : g[r]) {
        int to = e.first;
        int d = e.second;

        if (!f[to]) {
            if (!dfs(to, x + d)) {
                return false;
            }
        } else if (p[to] != p[r] + d) {
            return false;
        }
    }

    return true;
}


int main() {
    cin >> n >> m;

    g.resize(n);
    p.resize(n);
    f.resize(n);

    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        r--;

        g[l].emplace_back(r, d);
        g[r].emplace_back(l, -d);
    }

    for (int i = 0; i < n; i++) {
        if (!f[i]) {
            if(!dfs(i)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
}