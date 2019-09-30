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
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());

    int ans = 0;
    ans += (a[1] - a[0]) / 2;

    if((a[1] - a[0]) % 2 == 1){
        ans += a[2] - a[1] + 2;
    }else{
        ans += a[2] - a[1];
    }
    cout << ans << endl;

    return 0;
}