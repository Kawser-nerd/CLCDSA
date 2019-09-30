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
    int n, x;
    cin >> n >> x;
    int s = max(x, n-x);
    int t = min(x, n-x);

    int ans = 0;
    while(t != 0){
        ans += s / t * t * 3;
        int tmp = s % t;
        s = t;
        t = tmp;
    }
    cout << ans << endl;
    return 0;
}