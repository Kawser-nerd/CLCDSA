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
const int MOD = 998244353;

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

int powM(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        return powM(x * x % MOD, n / 2);
    }
    return powM(x, n-1) * x % MOD;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    bool isSame = false;
    bool isAllSame = true;
    int sum = 0;
    rep(i, SZ(s)){
        if(s[0] != s[i]){
            isAllSame = false;
        }
        if(i < SZ(s) - 1 && s[i] == s[i+1]){
            isSame = true;
        }
        sum += s[i] - 'a';
        sum %= 3;
    }

    if(isAllSame){
        cout << 1 << endl;
        return 0;
    }

    if(SZ(s) == 2){
        cout << 2 << endl;
        return 0;
    }

    if(SZ(s) == 3){
        if(isSame){
            cout << 6 << endl;
        }else if(sum == 0){
            cout << 3 << endl;
        }else{
            cout << 7 << endl;
        }
        return 0;
    }

    vector3<int> dp1 = initVec3<int>(SZ(s), 3, 3, 0);
    dp1[0][0][0] = dp1[0][1][1] = dp1[0][2][2] = 1;
    rep(i, SZ(s) - 1){
        rep(j, 3){
            rep(k, 3){
                rep(l, 3){
                    if(k == l){
                        continue;
                    }
                    dp1[i+1][(j+l)%3][l] += dp1[i][j][k];
                    dp1[i+1][(j+l)%3][l] %= MOD;
                }
            }
        }
    }
    vector2<int> dp2 = initVec2<int>(SZ(s) + 1, 3, 0);
    dp2[0][0]  = 1;
    rep(i, SZ(s)){
        rep(j, 3){
            rep(k, 3){
                dp2[i+1][(j+k)%3] += dp2[i][j];
                dp2[i+1][(j+k)%3] %= MOD;
            }
        }
    }
    int ans = dp2[SZ(s)][sum];
    rep(i, 3){
        ans = ans + MOD - dp1[SZ(s)-1][sum][i];
        ans %= MOD;
    }

    if(not isSame){
        ans++;
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}