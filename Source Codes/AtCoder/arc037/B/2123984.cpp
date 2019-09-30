#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

vector<int> no_ans;

int find(int v, vector<int>& p){
    if(p[v] == -1){
        return v;
    }
    p[v] = find(p[v], p);
    return p[v];
}

void unite(int u, int v, vector<int>& p){
    int u_root = find(u, p);
    int v_root = find(v, p);

    if(u_root == v_root){
        no_ans.push_back(u_root);
        return;
    }
    p[u_root] = v_root;
}

signed main(){
    int n, m;
    cin >> n >> m;

    vector<int> parent(n+1, -1);
    rep(i, m){
        int u, v;
        cin >> u >> v;
        unite(u, v, parent);
    }

    vector<bool> ans(n+1, false);
    for(int i = 1; i <= n; i++){
        int p = find(i, parent);
        ans[p] = true;
    }
    for(int i = 0; i < (int)no_ans.size(); i++){
        int p = find(no_ans[i], parent);
        ans[p] = false;
    }

    int c = 0;
    for(int i = 1; i <= n; i++){
        if(ans[i]){
            c++;
        }
    }
    cout << c << endl;

    return 0;
}