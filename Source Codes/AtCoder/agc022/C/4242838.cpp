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
vector<int> a, b;

bool floyd_warshall(set<int> st){
    auto edge = initVec2<int>(51, 51, INF);
    rep(i, 51){
        edge[i][i] = 0;
    }
    for(int k : st){
        rep(i, 51){
            edge[i][i%k] = 1;
        }
    }

    rep(k, 51){
        rep(i, 51){
            rep(j, 51){
                edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        }
    }

    rep(i, n){
        if(edge[a[i]][b[i]] == INF){
            return false;
        }
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    a = vector<int>(n);
    b = vector<int>(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    set<int> st;
    rep(i, 50){
        st.insert(i + 1);
    }

    if(not floyd_warshall(st)){
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    for(int k = 50; k > 0; k--){
        st.erase(k);
        if(not floyd_warshall(st)){
            ans += (1LL << k);
            st.insert(k);
        }
    }
    cout << ans << endl;


    return 0;
}