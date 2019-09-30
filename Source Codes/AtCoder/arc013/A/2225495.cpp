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
    int n, m, l, p, q, r;
    cin >> n >> m >> l >> p >> q >> r;

    int ans = (n / p) * (m / q) * (l / r);
    ans = max(ans, (n / p) * (m / r) * (l / q));
    ans = max(ans, (n / q) * (m / p) * (l / r));
    ans = max(ans, (n / q) * (m / r) * (l / p));
    ans = max(ans, (n / r) * (m / p) * (l / q));
    ans = max(ans, (n / r) * (m / q) * (l / p));
    cout << ans << endl;

    return 0;
}