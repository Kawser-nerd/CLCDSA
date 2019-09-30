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

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int s = 0;
    int x = 0;
    int r = 0;
    int ans = 0;
    for(int l = 0; l < n; l++){

        while(r < n && s + a[r] == (x xor a[r])){
            s += a[r];
            x ^= a[r];
            r++;
        }
        ans += r - l;
        s -= a[l];
        x ^= a[l];
    }
    cout << ans << endl;

    return 0;
}