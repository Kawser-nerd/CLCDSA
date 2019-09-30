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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    auto edge = initVec2<int>(n + 1, 0);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    int d4 = 0;
    int d6 = 0;
    vector<int> v4;
    for(int i = 1; i <= n; i++){
        if(SZ(edge[i]) % 2){
            cout << "No" << endl;
            return 0;
        }
        if(SZ(edge[i]) == 4){
            v4.push_back(i);
        }
        if(SZ(edge[i]) >= 4){
            d4++;
        }
        if(SZ(edge[i]) >= 6){
            d6++;
        }
    }

    if(d4 >= 3 || d6 >= 1){
        cout << "Yes" << endl;
        return 0;
    }

    if(SZ(v4) != 2){
        cout << "No" << endl;
        return 0;
    }

    vector<bool> used(n + 1, false);
    used[v4[1]] = true;
    stack<P> st;
    st.emplace(v4[0], 0);
    while(not st.empty()){
        int v = st.top().first;
        int p = st.top().second;
        st.pop();

        if(used[v]){
            continue;
        }
        used[v] = true;

        for(int u : edge[v]){
            if(u == p){
                continue;
            }
            st.emplace(u, v);
        }
    }

    for(int v = 1; v <= n; v++){
        if(not used[v]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}