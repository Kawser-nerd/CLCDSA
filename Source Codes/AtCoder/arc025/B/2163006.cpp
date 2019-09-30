#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
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
    int h, w;
    cin >> h >> w;

    vector<vector<int>> c(h, vector<int>(w));
    rep(i, h){
        rep(j, w){
            cin >> c[i][j];
            if((i + j) % 2 == 0){
                c[i][j] *= -1;
            }
        }
    }

    vector<vector<int>> a(h+1, vector<int>(w+1));
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            a[i][j] += c[i-1][j-1] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }

    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = i+1; j <= h; j++){
            for(int k = 0; k < w; k++){
                for(int l = k+1; l <= w; l++){
                    int s = a[j][l] - a[j][k] - a[i][l] + a[i][k];
                    int t = (j - i) * (l - k);
                    if(s == 0 && t > ans){
                        ans = t;
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}