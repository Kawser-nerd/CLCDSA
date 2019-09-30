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

int r, c;

int dist(int x, int y){
    if(y == 0){
        return x;
    }
    if(x == r){
        return r + y;
    }
    if(y == c){
        return 2 * r + c - x;
    }
    return 2 * (r + c) - y;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> r >> c >> n;

    vector<P> vp;
    rep(i, n){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if(x1 != 0 && x1 != r && y1 != 0 && y1 != c){
            continue;
        }
        if(x2 != 0 && x2 != r && y2 != 0 && y2 != c){
            continue;
        }
        vp.emplace_back(dist(x1, y1), i);
        vp.emplace_back(dist(x2, y2), i);
    }
    sort(ALL(vp));

    vector<bool> used(n, false);
    stack<int> st;
    rep(i, SZ(vp)){
        if(used[vp[i].second]){
            if(st.top() != vp[i].second){
                cout << "NO" << endl;
                return 0;
            }
            st.pop();
            continue;
        }
        st.push(vp[i].second);
        used[vp[i].second] = true;
    }
    cout << "YES" << endl;

    return 0;
}