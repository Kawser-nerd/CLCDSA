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

    int ans = 0;
    rep(i, n){
        int a, b;
        cin >> a >> b;
        ans += a * b;
    }

    ans = ans * 1.05;
    cout << ans << endl;

    return 0;
}