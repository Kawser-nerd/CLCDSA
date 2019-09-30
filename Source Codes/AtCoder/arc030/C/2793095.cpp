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
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

class SCC{
    public:
        int n, indexed;
        vector<bool> used;
        vector<int> cmp;
        vector<vector<int>> edge;
        vector<vector<int>> rev;
        vector<int> vs;

        SCC(int _n, int indexed)
            : n(_n + indexed), indexed(indexed), used(n), cmp(n),
            edge(n, vector<int>()), rev(n, vector<int>()) {}

        void add_edge(int u, int v){
            edge[u].push_back(v);
            rev[v].push_back(u);
        }

        void dfs(int v){
            if(used[v]){
                return;
            }
            used[v] = true;

            rep(i, (int)edge[v].size()){
                dfs(edge[v][i]);
            }
            vs.push_back(v);
        }

        void rdfs(int v, int k){
            if(used[v]){
                return;
            }
            used[v] = true;
            cmp[v] = k;

            rep(i, (int)rev[v].size()){
                rdfs(rev[v][i], k);
            }
        }

        int scc(){
            for(int v = indexed; v < n; v++){
                if(used[v]){
                    continue;
                }
                dfs(v);
            }

            used.assign(n, false);
            int k = 0;
            for(int i = vs.size()-1; i >= 0; i--){
                if(used[vs[i]]){
                    continue;
                }
                rdfs(vs[i], k++);
            }
            return k;
        }

        bool is_same(int u, int v){
            return cmp[u] == cmp[v];
        }
};

int k;

void dp(vector<vector<string>>& memo, vector<bool>& used, const vector<vector<int>>& edge, const vector<string>& t, int v){
    if(used[v]){
        return;
    }
    used[v] = true;

    for(int u: edge[v]){
        rep(i, k){
            for(int j = 0; i + j <= k; j++){
                if((i != 0 && memo[v][i] == "") || j > (int)t[u].length()){
                    continue;
                }
                string s = memo[v][i];
                s.append(t[u].substr(0, j));

                if(memo[u][i+j] == ""){
                    memo[u][i+j] = s;
                }else{
                    memo[u][i+j] = min(memo[u][i+j], s);
                }
            }
        }
    }
}

signed main(){
    int n, m;
    cin >> n >> m >> k;

    vector<char> alpha(n+1);
    rep(i, n) cin >> alpha[i+1];

    SCC s(n, 1);

    rep(i, m){
        int a, b;
        cin >> a >> b;
        s.add_edge(a, b);
    }

    int cmpN = s.scc();
    vector<string> t(cmpN);
    rep(i, cmpN){
        string ss = "";
        for(int j = 1; j <= n; j++){
            if(s.cmp[j] != i){
                continue;
            }
            ss.push_back(alpha[j]);
        }
        sort(ss.begin(), ss.end());
        t[i] = ss;
    }

    vector<vector<int>> graph(cmpN, vector<int>());
    rep(i, n){
        for(int j: s.edge[i+1]){
            if(s.cmp[i+1] != s.cmp[j]){
                graph[s.cmp[i+1]].push_back(s.cmp[j]);
            }
        }
    }

    vector<bool> used(cmpN, false);
    vector<vector<string>> memo(cmpN, vector<string>(k+1));

    rep(i, cmpN){
        rep(j, k+1){
            if(j > (int)t[i].length()){
                continue;
            }
            memo[i][j] = t[i].substr(0, j);
        }
    }

    rep(i, cmpN){
        if(used[i]){
            continue;
        }
        dp(memo, used, graph, t, i);
    }

    string ans = "~~~~~";
    rep(i, cmpN){
        if(ans > memo[i][k] && memo[i][k] != ""){
            ans = memo[i][k];
        }
    }
    cout << (ans == "~~~~~" ? "-1" : ans) << endl;

    return 0;
}