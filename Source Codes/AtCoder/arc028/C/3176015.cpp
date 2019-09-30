#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

int n;

int dfs(const vector<vector<int>>& edge, vector<int>& a, int v, int p){
    int child = 0;
    for(int u : edge[v]){
        if(u == p){
            continue;
        }
        int c = dfs(edge, a, u, v);
        child += c;
        a[v] = max(a[v], c);
    }
    a[v] = max(a[v], n - 1 - child);

    return child + 1;
}


signed main(){
    cin >> n;

    vector<vector<int>> edge(n, vector<int>());
    rep(i, n-1){
        int p;
        cin >> p;

        edge[i+1].push_back(p);
        edge[p].push_back(i+1);
    }

    vector<int> ans(n);
    dfs(edge, ans, 0, -1);
    rep(i, n){
        cout << ans[i] << endl;
    }

    return 0;
}