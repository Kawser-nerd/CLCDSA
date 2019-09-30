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

    int h, w;
    cin >> h >> w;
    vector<vector<bool>> s(h, vector<bool>(w, false));
    rep(i, h) rep(j, w){
        char c;
        cin >> c;
        if(c == '.'){
            s[i][j] = true;
        }
    }

    vector<vector<bool>> t(h - 1, vector<bool>(w - 1, false));
    rep(i, h - 1) rep(j, w - 1){
        t[i][j] = s[i][j] ^ s[i+1][j] ^ s[i][j+1] ^ s[i+1][j+1];
    }

    vector<vector<int>> hist(h - 1, vector<int>(w - 1));
    rep(i, w - 1){
        int cnt = 0;
        rep(j, h - 1){
            if(t[j][i]){
                cnt = 0;
                continue;
            }
            hist[j][i] = ++cnt;
        }
    }

    int ans = max(h, w);
    rep(i, h - 1){
        stack<P> st;
        st.emplace(hist[i][0], 0);
        for(int j = 1; j < w - 1; j++){
            if(st.top().first == hist[i][j]){
                continue;
            }
            if(st.top().first < hist[i][j]){
                st.emplace(hist[i][j], j);
                continue;
            }
            int idx;
            while(not st.empty() && hist[i][j] <= st.top().first){
                P p = st.top();
                st.pop();
                idx = p.second;

                ans = max(ans, (j - idx + 1) * (p.first + 1));
            }
            st.emplace(hist[i][j], idx);
        }
        int idx;
        while(not st.empty()){
            P p = st.top();
            st.pop();
            idx = p.second;

            ans = max(ans, (w - idx) * (p.first + 1));
        }
    }
    cout << ans << endl;

    return 0;
}