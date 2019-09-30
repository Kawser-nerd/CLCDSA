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

class LowestCommonAncestor{
    private:
        int n;
        int m;
        vector<vector<int>> parent;
        vector<int> dep;

        int log2(int n){
            int x = 0;
            while(n > 0){
                x++;
                n /= 2;
            }
            return x;
        }

        void init(const vector<vector<int>>& edge){
            stack<tuple<int, int, int>> st;
            st.emplace(1, 0, 1);
            while(not st.empty()){
                int v = get<0>(st.top());
                int d = get<1>(st.top());
                int p = get<2>(st.top());
                st.pop();

                dep[v] = d;
                parent[0][v] = p;

                for(int u : edge[v]){
                    if(parent[0][u] != -1){
                        continue;
                    }
                    st.emplace(u, d+1, v);
                }
            }

            //doubling
            for(int i = 1; i < m; i++){
                for(int v = 1; v < n; v++){
                    parent[i][v] = parent[i-1][parent[i-1][v]];
                }
            }
        }

    public:
        LowestCommonAncestor(vector<vector<int>>& edge, int n):
            n(n), m(log2(n)), parent(m, vector<int>(n, -1)), dep(n){
                init(edge);
            }

        int ancestor(int v, int d){
            if(d >= n){
                return 0;
            }

            int a = v;
            for(int i = 0; i < m; i++){
                if(d % 2 == 1){
                    a = parent[i][a];
                }
                d /= 2;
            }
            return a;
        }

        int query(int u, int v){
            if(dep[u] < dep[v]){
                swap(u, v);
            }
            u = ancestor(u, dep[u] - dep[v]);

            if(u == v){
                return u;
            }

            int lo = 0;
            int hi = n;
            while(hi - lo > 1){
                int mid = (lo + hi) / 2;
                if(ancestor(u, mid) == ancestor(v, mid)){
                    hi = mid;
                }else{
                    lo = mid;
                }
            }

            return ancestor(u, hi);
        }

        int depth(int v){
            return dep[v];
        }
};

int n;
vector<int> p;
vector<vector<int>> edge;
int mini = INF;
int maxi = 0;
vector<P> r;

void dfs1(int v, int par){
    //P r[v] = {-INF, INF};
    if(p[v] != -1){
        r[v].first = max(r[v].first, p[v]);
        r[v].second = min(r[v].second, p[v]);
    }

    for(int u : edge[v]){
        if(u == par){
            continue;
        }
        dfs1(u, v);
        r[v].first = max(r[v].first, r[u].first - 1);
        r[v].second = min(r[v].second, r[u].second + 1);
    }
    if(r[v].first > r[v].second){
        cout << "No" << endl;
        exit(0);
    }
}

void dfs2(int v, int par){
    if(p[v] == -1){
        if(r[v].first <= p[par] + 1 && p[par] + 1 <= r[v].second){
            p[v] = p[par] + 1;
        }else{
            p[v] = p[par] - 1;
        }
    }
    for(int u : edge[v]){
        if(u == par){
            continue;
        }
        dfs2(u, v);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    edge = vector<vector<int>>(n + 1, vector<int>());
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    p = vector<int>(n + 1, -1);
    int k;
    cin >> k;
    rep(i, k){
        int a, b;
        cin >> a >> b;
        p[a] = b;
    }

    LowestCommonAncestor lca(edge, n + 1);
    for(int v = 1; v <= n; v++){
        if(p[v] == -1){
            continue;
        }
        for(int u = 1; u <= n; u++){
            if(v == u || p[u] == -1){
                continue;
            }
            int w = lca.query(v, u);
            int dist = abs(lca.depth(v) - lca.depth(w));
            dist += abs(lca.depth(u) - lca.depth(w));

            int diff = abs(p[v] - p[u]);

            if(diff > dist || diff % 2 != dist % 2){
                cout << "No" << endl;
                return 0;
            }
        }
        break;
    }

    r = vector<P>(n + 1, {-INF, INF});
    dfs1(1, 0);
    p[0] = r[1].first - 1;
    dfs2(1, 0);

    cout << "Yes" << endl;
    rep(i, n){
        cout << p[i+1] << endl;
        //cout << p[i+1] << " " << r[i+1].first << " " << r[i+1].second << endl;
    }

    return 0;
}