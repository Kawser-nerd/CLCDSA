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

const int INF = 1e18;
const int MOD = 1e9+7;

int f(int x){
    if(x == 1){
        return 5;
    }
    return 2 * x + 1;
}

signed main(){
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> s(n+1);
    rep(i, n){
        s[i+1] += s[i] + a[i];
    }

    int ans = INF;
    for(int k = 1; k <= n; k++){
        int last = n;
        bool ng = false;
        int tmp = 0;
        int c = 1;
        while(last > 0){
            int nLast = max(0LL, last - k);
            tmp += (s[last] - s[nLast]) * f(c++);
            if(tmp >= ans){
                ng = true;
            }
            last = nLast;
        }

        if(ng){
            continue;
        }

        ans = min(ans, tmp + k * x);
    }
    cout << ans + n * x << endl;

    return 0;
}