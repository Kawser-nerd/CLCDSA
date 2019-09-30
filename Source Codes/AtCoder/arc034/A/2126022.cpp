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

    double ans = 0;
    rep(i, n){
        double a, b, c, d, e, tmp;
        cin >> a >> b >> c >> d >> e;
        tmp = a + b + c + d + e * 110 / 900;
        if(tmp > ans){
            ans = tmp;
        }
    }

    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}