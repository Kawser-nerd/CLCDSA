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

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    int n;
    cin >> n;
    vector<vector<bool>> s(n, vector<bool>(n, false));
    rep(i, n){
        rep(j, n){
            char c;
            cin >> c;
            if(c == 'o'){
                s[i][j] = true;
            }
        }
    }

    int ans = 0;
    rep(i, n){
        for(int j = n-1; j >= 0; j--){
            if(s[i][j]){
                continue;
            }

            rep(k, n){
                if(k <= j){
                    s[i][k] = true;
                }
                if(i + 1 < n && k >= j){
                    s[i+1][k] = true;
                }
            }
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}