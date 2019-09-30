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
    int m, n, l;
    cin >> m >> n >> l;

    int ans = l;
    int re = l;
    while(re >= m){
        int a = re / m;
        ans += a * n;
        re = re - a * m + a * n;
    }
    cout << ans << endl;
    return 0;
}