#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
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

    vector<vector<char>> s(n, vector<char>(2*n+1));
    rep(i, n){
        rep(j, n){
            cin >> s[i][j];
        }
    }
    rep(i, n){
        for(int j = n; j < 2 * n; j++){
            s[i][j] = s[i][j-n];
        }
    }

    int ans = 0;
    rep(i, n){
        bool ok = true;
        for(int h = 0; h < n; h++){
            for(int w = i; w < n + i; w++){
                if(s[h][w] != s[w-i][h+i]){
                    ok = false;
                }
            }
        }

        if(ok){
            ans += n;
        }
    }
    cout << ans << endl;

    return 0;
}