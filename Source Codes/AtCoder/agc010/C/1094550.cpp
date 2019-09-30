#include <iostream>

#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <cmath>
#include <algorithm>

#include <fstream>

using namespace std;


const long long INF = 1e9;
using LD = long double;
using LL = long long;
vector < LL > w;
vector < vector < int > > g;
bool ok = true;

LL dfs(int v, int p) {
    if (g[v].size() == 1 && p != -1) {
        return w[v];
    }
    LL mx = 0;
    LL ans = 0;
    for (auto to: g[v]) {
        if (to == p) {
            continue;
        }
        auto res = dfs(to, v);
        ans += res;
        mx = max(mx, res);
    }
    if (w[v] * 2 < ans) {
        ok = false;
    }
    LL x = w[v] * 2 - ans;
    if (p == -1 && g[v].size() == 1) {
        x -= w[v];
        return x;
    }
    if ( (ans - x) % 2 != 0) {
        ok = false;
    }
    LL y = (ans - x) / 2;
    if (y < 0) {
        ok = false;
    }
    LL mxy = min(ans/2, ans - mx);
    if (y > mxy) {
        ok = false;
    }
    //cout << v << " " << x << " " << y << " " << mxy << endl;

    return x;
}

int main()
{
    //ifstream cin ("/Users/Roman/ClionProjects/Calculations/input.txt");
    //ofstream cout ("/Users/Roman/ClionProjects/Calculations/output.txt");

    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cout.setf(ios_base::fixed);
    cout.precision(10);
    srand(179);
    LL n;
    cin >> n;
    w.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    vector < vector < int > > gr(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    g = gr;
    auto ans = dfs(0, -1);
    if (ok && ans == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}