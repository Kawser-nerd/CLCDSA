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
    vector<int> a(n+1);
    rep(i, n) cin >> a[i];

    int height = 0;
    rep(i, n){
        if(a[i] < a[i+1] && a[i] + 1 != a[i+1]){
            cout << -1 << endl;
            return 0;
        }
        if(a[i] == 0){
            height = 1;
            continue;
        }
        if(height >= a[i]){
            height++;
            continue;
        }
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    for(int i = n; i > 0; i--){
        if(a[i-1] >= a[i]){
            ans += a[i-1];
        }
    }
    cout << ans << endl;

    return 0;
}