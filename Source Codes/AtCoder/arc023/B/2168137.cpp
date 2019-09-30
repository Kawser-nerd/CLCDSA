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
    int r, c, d;
    cin >> r >> c >> d;

    int ans = 0;
    rep(i, r){
        rep(j, c){
            int a;
            cin >> a;
            if(i + j <= d && (i + j) % 2 == d % 2 && ans < a){
                ans = a;
            }
        }
    }
    cout << ans << endl;

    return 0;
}