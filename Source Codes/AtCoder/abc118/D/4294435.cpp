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

    vector<int> cost = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    int n, m;
    cin >> n >> m;
    vector<int> num(8);
    rep(i, m){
        int a;
        cin >> a;
        num[cost[a]] = max(num[cost[a]], a);
    }

    vector<string> dp(n + 1, "0");
    dp[0] = "";
    rep(i, n){
        rep(j, 8){
            if(i + j > n || num[j] == 0 || dp[i] == "0"){
                continue;
            }
            string s = dp[i];
            s.push_back(num[j] + '0');

            if(dp[i+j] == "" || SZ(dp[i+j]) < SZ(s) || dp[i+j] < s){
                dp[i+j] = s;
            }
        }
    }
    cout << dp[n] << endl;

    return 0;
}