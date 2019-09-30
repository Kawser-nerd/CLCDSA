#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    vector<int> a(7);
    rep(i, 7) cin >> a[i];

    int i = a[0];
    int j = a[3];
    int l = a[4];
    int m = min(a[0], min(a[3], a[4]));
    a[0] -= m;
    a[3] -= m;
    a[4] -= m;
    int ans = m * 3;
    ans += a[0] / 2 * 2 + a[3] / 2 * 2 + a[4] / 2 * 2;
    if(i > 0 && a[3] % 2 == 1 && a[4] % 2 == 1){
        ans++;
    }
    if(j > 0 && a[0] % 2 == 1 && a[4] % 2 == 1){
        ans++;
    }
    if(l > 0 && a[3] % 2 == 1 && a[0] % 2 == 1){
        ans++;
    }
    cout << ans + a[1] << endl;

    return 0;
}