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

vector<int> solve(int x){
    vector<int> res;

    int bi = 2;
    rep(i, 60){
        res.push_back(x / bi * (bi / 2));
        if(x % bi > bi / 2){
            res.back() += x % bi - bi / 2;
        }

        bi *= 2;
    }
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    auto va = solve(a);
    auto vb = solve(b + 1);

    int ans = 0;
    rep(i, SZ(vb)){
        if((vb[i] - va[i]) % 2){
            ans ^= 1LL << i;
        }
    }
    cout << ans << endl;

    return 0;
}