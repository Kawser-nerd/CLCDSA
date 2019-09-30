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

    int h, w, k;
    cin >> h >> w >> k;

    if(w == 1){
        cout << 1 << endl;
        return 0;
    }

    vector<vector<int>> line(w, vector<int>(w));
    rep(s, 1 << (w - 1)){
        bool ok = true;
        rep(i, w - 2){
            if((s >> i) % 2 == 1 && (s >> (i + 1)) % 2 == 1){
                ok = false;
            }
        }
        if(not ok){
            continue;
        }

        vector<int> pos(w);
        rep(i, w) pos[i] = i;

        rep(i, w - 1){
            if((s >> i) % 2 == 0){
                continue;
            }
            swap(pos[i], pos[i+1]);
        }
        rep(i, w){
            line[i][pos[i]]++;
        }
    }

    vector<vector<int>> dp(h+1, vector<int>(w));
    dp[0][0] = 1;
    rep(i, h){
        rep(j, w){
            rep(l, w){
                dp[i+1][l] += dp[i][j] * line[j][l] % MOD;
                dp[i+1][l] %= MOD;
            }
        }
    }
    cout << dp[h][k-1] << endl;

    return 0;
}