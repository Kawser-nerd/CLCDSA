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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m; 
    vector<vector<int>> edge(n + 1, vector<int>());
    rep(i, m){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int q;
    cin >> q;
    vector<int> v(q), d(q), c(q);
    rep(i, q) cin >> v[i] >> d[i] >> c[i];
    reverse(ALL(v));
    reverse(ALL(d));
    reverse(ALL(c));

    vector<vector<int>> dp(n + 1, vector<int>(11));
    rep(i, q){
        stack<P> st;
        st.emplace(v[i], d[i]);

        while(not st.empty()){
            int u = st.top().first;
            int dd = st.top().second;
            st.pop();

            bool marked = false;
            for(int j = dd; j <= 10; j++){
                if(dp[u][j] != 0){
                    marked = true;
                }
            }
            if(marked){
                continue;
            }
            dp[u][dd] = c[i];

            for(int w : edge[u]){
                st.emplace(w, dd - 1);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int ans = 0;
        rep(j, 11){
            if(dp[i][j] != 0){
                ans = dp[i][j];
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}