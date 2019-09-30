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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, n;
    cin >> l >> n;
    vector<int> x(n);
    rep(i, n) cin >> x[i];

    vector<int> left(n + 1), right(n + 1);
    rep(i, n){
        right[i+1] = right[i] + x[i] * 2;
    }
    for(int i = n; i > 0; i--){
        left[i-1] = left[i] + (l - x[i-1]) * 2;
    }

    int ans = 0;
    //right
    rep(i, n){
        int tmp = 0;
        if((n - i) % 2 == 0){
            int cnt = (n - i) / 2;
            tmp += right[i+cnt] - right[i];
            tmp += left[n-cnt+1];
            tmp += l - x[n-cnt];
        }else{
            int cnt = (n - i) / 2;
            tmp += right[i+cnt] - right[i];
            tmp += left[n-cnt];
            tmp += x[i+cnt];
        }
        ans = max(ans, tmp);
    }

    //left
    rep(i, n){
        int tmp = 0;
        if((n - i) % 2 == 0){
            int cnt = (n - i) / 2;
            tmp += left[n-i-cnt] - left[n-i];
            tmp += right[cnt-1];
            tmp += x[cnt-1];
        }else{
            int cnt = (n - i) / 2;
            tmp += left[n-i-cnt] - left[n-i];
            tmp += right[cnt];
            tmp += l - x[n-i-cnt-1];
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}