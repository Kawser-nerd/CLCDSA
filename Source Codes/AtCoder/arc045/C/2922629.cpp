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

signed main(){
    int n, k;
    cin >> n >> k;

    vector<vector<P>> edge(n+1, vector<P>());
    rep(i, n-1){
        int x, y, c;
        cin >> x >> y >> c;

        edge[x].emplace_back(y, c);
        edge[y].emplace_back(x, c);
    }
    edge[0].emplace_back(1, 0);

    stack<P> st;
    map<int, int> m;
    vector<bool> mark(n+1, false);
    int ans = 0;
    st.emplace(1, 0);

    while(not st.empty()){
        P e = st.top();
        st.pop();

        if(mark[e.first]){
            continue;
        }
        mark[e.first] = true;

        for(P p : edge[e.first]){
            st.emplace(p.first, e.second ^ p.second);
        }

        if(m.find(e.second ^ k) != m.end()){
            ans += m[e.second ^ k];
        }

        if(m.find(e.second) == m.end()){
            m.emplace(e.second, 0);
        }
        m[e.second]++;
    }
    cout << ans << endl;

    return 0;
}