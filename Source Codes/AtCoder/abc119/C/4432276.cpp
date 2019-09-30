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

template <typename T>
using vector2 = vector<vector<T>>;
template <typename T>
vector2<T> initVec2(size_t n0, size_t n1, T e = T()){
    return vector2<T>(n0, vector<T>(n1, e));
}

template <typename T>
using vector3 = vector<vector<vector<T>>>;
template <typename T>
vector3<T> initVec3(size_t n0, size_t n1, size_t n2, T e = T()){
    return vector3<T>(n0, vector2<T>(n1, vector<T>(n2, e)));
}

int n;
vector<int> l, x(3);
int ans = INF;
stack<int> st[3];

void solve(int i){
    if(i >= n){
        rep(j, 3){
            if(st[j].empty()){
                return;
            }
        }
        int tmp = -30;
        vector<int> y(3);
        rep(j, 3){
            stack<int> sst = st[j];
            while(not sst.empty()){
                y[j] += sst.top();
                sst.pop();
                tmp += 10;
            }
            tmp += abs(x[j] - y[j]);
        }
        ans = min(ans, tmp);
        return;
    }

    rep(j, 4){
        if(j == 3){
            solve(i + 1);
            continue;
        }
        st[j].push(l[i]);
        solve(i + 1);
        st[j].pop();
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    rep(i, 3) cin >> x[i];
    l = vector<int>(n);
    rep(i, n) cin >> l[i];

    solve(0);
    cout << ans << endl;

    return 0;
}