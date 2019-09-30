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

    vector<int> a(n), b(n);
    rep(i, n){
        cin >> a[i] >> b[i];
    }

    int ans = 0;
    for(int i = n - 1; i >= 0; i--){
        ans += (b[i] - (a[i] + ans) % b[i]) % b[i];
    }
    cout << ans << endl;
    return 0;
}