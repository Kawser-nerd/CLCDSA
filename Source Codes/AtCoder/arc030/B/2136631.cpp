#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

bool check(const vector<vector<int>>& graph, vector<bool> mark, const vector<int>& h, int x){
    stack<int> st;
    st.push(x);
    bool ft = false;

    while(not st.empty()){
        int v = st.top();
        st.pop();

        if(mark[v]){
            continue;
        }
        mark[v] = true;

        if(h[v] == 1){
            ft = true;
        }

        for(int i = 0; i < (int)graph[v].size(); i++){
            int u = graph[v][i];
            if(mark[u]){
                continue;
            }
            st.push(u);
        }
    }
    return ft;
}

int dfs(const vector<vector<int>>& graph, const vector<int>& h, int x){
    stack<int> st;
    st.push(x);
    int ans = -2;

    vector<bool> mark(graph.size(), false);
    while(not st.empty()){
        int v = st.top();
        st.pop();

        if(mark[v]){
            continue;
        }
        mark[v] = true;
        ans += 2;

        for(int i = 0; i < (int)graph[v].size(); i++){
            int u = graph[v][i];
            if(check(graph, mark, h, u)){
                st.push(u);
            }
        }
    }
    return ans;
}

signed main(){
    int n, x;
    cin >> n >> x;

    vector<int> h(n+1);
    rep(i, n) cin >> h[i+1];

    vector<vector<int>> graph(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << dfs(graph, h, x) << endl;

    return 0;
}