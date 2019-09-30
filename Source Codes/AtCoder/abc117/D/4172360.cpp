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

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> cnt(40);
    rep(i, n){
        int x = a[i];
        rep(j, 40){
            cnt[j] += (x >> j) % 2;
        }
    }

    vector<int> pow(41);
    pow[0] = 1;
    rep(i, 40) pow[i+1] = pow[i] * 2;

    auto dp = initVec3<int>(41, 2, 2, -1);
    dp[40][0][1] = 0;
    for(int i = 40; i > 0; i--){
        rep(j, 2){
            if(dp[i][j][0] != -1){
                dp[i-1][0][0] = max(dp[i-1][0][0], dp[i][j][0] + cnt[i-1] * pow[i-1]);
                dp[i-1][1][0] = max(dp[i-1][1][0], dp[i][j][0] + (n - cnt[i-1]) * pow[i-1]);
            }
            if(dp[i][j][1] != -1){
                if((k >> (i - 1)) % 2 == 0){
                    dp[i-1][0][1] = max(dp[i-1][0][1], dp[i][j][1] + cnt[i-1] * pow[i-1]);
                }else{
                    dp[i-1][1][1] = max(dp[i-1][1][1], dp[i][j][1] + (n - cnt[i-1]) * pow[i-1]);
                    dp[i-1][0][0] = max(dp[i-1][0][0], dp[i][j][1] + cnt[i-1] * pow[i-1]);
                }
            }
        }
    }
    cout << max(dp[0][0][0], max(dp[0][1][0], dp[0][k%2][1])) << endl;

    return 0;
}