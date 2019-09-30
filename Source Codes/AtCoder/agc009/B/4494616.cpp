#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<vector<int>> g;

int dfs(int r) {
    vector<int> v;

    v.push_back(0);

    for (int to : g[r]) {
        int t = dfs(to);
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < (int)v.size() - 1; i++) {
        v[i + 1] = max(v[i], v[i + 1]) + 1;
    }

    return v.back();
}

int main() {
    cin >> n;

    g.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int a;
        cin >> a;

        g[a - 1].push_back(i + 1);
    }

    cout << dfs(0) << endl;
}