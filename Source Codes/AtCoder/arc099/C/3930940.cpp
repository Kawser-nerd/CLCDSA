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

struct connect{
    int x, y, edge;
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    bool exist[701][701] = {};
    rep(i, m){
        int a, b;
        cin >> a >> b;
        exist[a][b] = exist[b][a] = true;
    }

    vector<vector<int>> edge(n+1, vector<int>());
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(exist[i][j] || i == j){
                continue;
            }
            edge[i].push_back(j);
        }
    }

    vector<int> mark(n+1);
    stack<P> st;
    int c = 0;
    for(int i = 1; i <= n; i++){
        if(mark[i] != 0){
            continue;
        }
        st.emplace(i, ++c);

        while(not st.empty()){
            int v = st.top().first;
            int col = st.top().second;
            st.pop();

            if(mark[v] != 0){
                if(mark[v] != col){
                    cout << -1 << endl;
                    return 0;
                }
                continue;
            }
            mark[v] = col;

            for(int u : edge[v]){
                st.emplace(u, -col);
            }
        }
    }

    vector<connect> vc(c + 1);
    for(int i = 1; i <= n; i++){
        if(mark[i] > 0){
            vc[mark[i]].x++;
        }else{
            vc[-mark[i]].y++;
        }
        vc[abs(mark[i])].edge += edge[i].size();
    }

    for(int i = 1; i <= c; i++){
        vc[i].edge /= 2;
    }

    map<P, bool> dp;
    dp[{0, 0}] = 0;
    for(int i = 1; i <= c; i++){
        map<P, bool> tmp;
        for(pair<P, bool> pp : dp){
            P p = pp.first;

            P p1 = {p.first + vc[i].x, p.second + vc[i].y};
            P p2 = {p.first + vc[i].y, p.second + vc[i].x};
            tmp[p1] = true;
            tmp[p2] = true;
        }
        dp = tmp;
    }

    int ans = INF;
    for(pair<P, bool> p : dp){
        int tmp = (p.first.first - 1) * p.first.first / 2;
        tmp += (p.first.second - 1) * p.first.second / 2;
        ans = min(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}