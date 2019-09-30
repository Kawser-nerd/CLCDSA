#include <algorithm>
#include <complex>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;
using std::map;
using std::pair;
using std::make_pair;

typedef long long int ll;
const int MOD = 1e9 + 7;


pair<int, int> dfs(const vector<vector<int>> &g, int v, vector<bool> &used) {
    int wcnt = 1;
    int bcnt = 1;
    used[v] = true;
    for (int u : g[v]) {
        if(used[u]){
            continue;
        }
        pair<int, int> tmp = dfs(g, u, used);
        ll wcnt_u = tmp.first;
        ll bcnt_u = tmp.second;

        wcnt = wcnt * (wcnt_u + bcnt_u) % MOD;
        bcnt = bcnt * (wcnt_u) % MOD;
    }
    used[v] = false;
    return make_pair(wcnt, bcnt);
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

    vector<bool> used(n);
    pair<int, int> ans = dfs(g, 0, used);
    cout << (ans.first + ans.second) % MOD << endl;

    return 0;
}