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

int n, k;

int dfs(const vector<vector<int>>& edge, int s){
    vector<int> depth(n+1, -1);
    stack<P> st;
    st.emplace(s, 0);
    while(not st.empty()){
        int v = st.top().first;
        int d = st.top().second;
        st.pop();

        if(depth[v] != -1){
            continue;
        }
        depth[v] = d;

        for(int u : edge[v]){
            st.emplace(u, d+1);
        }
    }

    int ans = 0;
    for(int v = 1; v <= n; v++){
        if(k / 2 < depth[v]){
            ans++;
        }
    }
    return ans;
}

int dfs(const vector<vector<int>>& edge, int s, int t){
    vector<int> depth(n+1, -1);
    stack<P> st;
    st.emplace(s, 0);
    while(not st.empty()){
        int v = st.top().first;
        int d = st.top().second;
        st.pop();

        if(depth[v] != -1){
            continue;
        }
        depth[v] = d;

        for(int u : edge[v]){
            if(u == t){
                continue;
            }
            st.emplace(u, d+1);
        }
    }
    st = stack<P>();
    st.emplace(t, 0);
    while(not st.empty()){
        int v = st.top().first;
        int d = st.top().second;
        st.pop();

        if(depth[v] != -1){
            continue;
        }
        depth[v] = d;

        for(int u : edge[v]){
            if(u == s){
                continue;
            }
            st.emplace(u, d+1);
        }
    }

    int ans = 0;
    for(int v = 1; v <= n; v++){
        if((k - 1) / 2 < depth[v]){
            ans++;
        }
    }
    return ans;
}

signed main(){
    cin >> n >> k;

    vector<vector<int>> edge(n+1, vector<int>());
    vector<P> edges(n-1);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
        edges[i] = make_pair(a, b);
    }

    int ans = INF;
    if(k % 2 == 0){
        for(int v = 1; v <= n; v++){
            ans = min(ans, dfs(edge, v));
        }
    }else{
        for(P e : edges){
            ans = min(ans, dfs(edge, e.first, e.second));
        }
    }
    cout << ans << endl;

    return 0;
}