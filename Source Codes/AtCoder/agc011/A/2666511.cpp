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
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    sort(t.begin(), t.end());

    int ans = 0;
    int i = 0;
    while(i < n){
        int cc = c;
        int limit = t[i] + k;
        while(i < n && t[i] <= limit && cc > 0){
            cc--;
            i++;
        }
        ans++;
    }
    cout << ans << endl;

    return 0;
}