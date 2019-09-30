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

class lowest_common_ancestor{
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
        lowest_common_ancestor(vector<vector<int>>& edge, int n):
            n(n), m(log2(n)), parent(m, vector<int>(n, -1)), dep(n){
                init(edge);
            }

        int ancestor(int v, int d){
            if(d >= n){
                return 0;
            }

            int a = v;
            rep(i, m){
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

signed main(){
    int n;
    cin >> n;

    vector<vector<int>> edge(n+1, vector<int>());
    rep(i, n-1){
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    lowest_common_ancestor lca(edge, n+1);

    int q;
    cin >> q;

    rep(i, q){
        int a, b;
        cin >> a >> b;

        int anc = lca.query(a, b);
        int ans = lca.depth(a) + lca.depth(b) - lca.depth(anc) * 2 + 1;
        cout << ans << endl;
    }

    return 0;
}