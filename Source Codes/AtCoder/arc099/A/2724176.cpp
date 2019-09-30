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
    int x;
    rep(i, n){
        cin >> a[i];
        if(a[i] == 1){
            x = i;
        }
    }

    int l = x;
    int r = n - 1 - x;
    int nl = l % (k - 1);
    int nr = r % (k - 1);

    int ans = l / (k-1) + r / (k-1);
    ans += (nl + nr) / (k-1);
    if((nl + nr) % (k-1) > 0){
        ans++;
    }
    cout << ans << endl;

    return 0;
}