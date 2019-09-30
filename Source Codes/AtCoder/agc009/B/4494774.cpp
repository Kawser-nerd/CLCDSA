#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<vector<int>> g;

int dfs(int r) {

    vector<int> v;

    for (int to : g[r]) {
        int t = dfs(to);
        v.push_back(t);
    }
    
    sort(v.begin(), v.end(), greater<>());

    int ret = 0;

    for (int i = 0; i < (int)v.size(); i++) {
        ret = max(ret, v[i] + i + 1);
    }

    return ret;
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