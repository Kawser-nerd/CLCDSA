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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

int n;
vector<int> a;
vector<vector<int>> edge;

bool dfs(int v, int par){
    int sum = 0;
    int maxi = 0;
    int child = 0;
    for(int u : edge[v]){
        if(u == par){
            continue;
        }
        if(not dfs(u, v)){
            return false;
        }
        sum += a[u];
        maxi = max(maxi, a[u]);
        child++;
    }

    if(child == 0){
        return true;
    }

    int rest = a[v] * 2 - sum;
    maxi = max(maxi, rest);
    if(rest < 0){
        return false;
    }
    if(maxi > a[v]){
        return false;
    }
    if(child == 1 && rest != a[v]){
        return false;
    }

    a[v] = rest;
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a = vector<int>(n);
    rep(i, n) cin >> a[i];
    edge = vector<vector<int>>(n, vector<int>());
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }

    if(not dfs(0, -1)){
        cout << "NO" << endl;
        return 0;
    }
    if(SZ(edge[0]) > 1 && a[0] > 0){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;

    return 0;
}