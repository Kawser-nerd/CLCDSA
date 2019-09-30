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
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> x(n+1), y(n+1);
    for(int i = 0; i < n; i++){
        x[i+1] = x[i] + a[i];
        y[i+1] = y[i] + max(0LL, a[i]);
    }

    int ans = 0;
    for(int i = 0; i <= n - k; i++){
        int tmp = max(0LL, x[i+k] - x[i]);
        tmp += y[i] + y[n] - y[i+k];
        if(tmp > ans){
            ans = tmp;
        }
    }
    cout << ans << endl;

    return 0;
}