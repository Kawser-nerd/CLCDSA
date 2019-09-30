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

int f(const vector<int>& a, const vector<int>& d, int m){
    int n = a.size();

    int k = 0;
    rep(i, n){
        if(m < a[i]){
            continue;
        }
        k += (m - a[i]) / d[i] + 1;
    }
    return k;
}

signed main(){
    int k, n;
    cin >> k >> n;

    vector<int> a(n), d(n);
    rep(i, n) cin >> a[i] >> d[i];

    int lo = 0;
    int hi = 1e12;
    while(hi - lo > 1){
        int m = (hi + lo) / 2;
        if(f(a, d, m) >= k){
            hi = m;
        }else{
            lo = m;
        }
    }

    int ans = 0;
    int cnt = 0;
    rep(i, n){
        if(hi < a[i]){
            continue;
        }
        int x = (hi - a[i]) / d[i] + 1;
        cnt += x;
        ans += a[i] * x + (x - 1) * x / 2 * d[i];
    }
    ans -= (cnt - k) * hi;
    cout << ans << endl;

    return 0;
}