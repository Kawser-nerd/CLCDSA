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
vector2<int> edge;
vector<int> len;

int dfs(int v){
    vector<P> child;
    for(int u : edge[v]){
        child.emplace_back(dfs(u), u);
    }

    sort(ALL(child), greater<P>());
    int lenMax = 0;
    for(int i = 1; i <= SZ(child); i++){
        int dist = child[i-1].first;
        int u = child[i-1].second;
        len[u] = i;
        lenMax = max(lenMax, dist + i);
    }

    return lenMax;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    edge = initVec2<int>(n + 1, 0);
    for(int i = 2; i <= n; i++){
        int a;
        cin >> a;
        edge[a].push_back(i);
    }

    len = vector<int>(n + 1);
    cout << dfs(1) << endl;

    return 0;
}