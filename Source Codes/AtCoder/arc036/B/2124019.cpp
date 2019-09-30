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
    int n;
    cin >> n;

    vector<int> h(n);
    rep(i, n) cin >> h[i];

    vector<int> up(n), down(n);
    int c = 1;
    for(int i = 0; i < n-1; i++){
        if(h[i] > h[i+1]){
            up[i] = c;
            c = 1;
            continue;
        }
        c++;
    }
    up[n-1] = c;

    c = 1;
    for(int i = n-1; i > 0; i--){
        if(h[i] > h[i-1]){
            down[i] = c;
            c = 1;
            continue;
        }
        c++;
    }
    down[0] = c;

    int ans = 0;
    rep(i, n){
        int m = up[i] + down[i] - 1;
        if(ans < m){
            ans = m;
        }
    }
    cout << ans << endl;

    return 0;
}