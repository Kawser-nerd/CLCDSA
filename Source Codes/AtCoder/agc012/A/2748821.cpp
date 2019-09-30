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

    vector<int> a(n*3);
    rep(i, n*3){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());

    int ans = 0;
    rep(i, 2*n){
        if(i % 2 == 1){
            ans += a[i];
        }
    }
    cout << ans << endl;

    return 0;
}