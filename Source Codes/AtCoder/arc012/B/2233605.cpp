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
    double n, a, b, l;
    cin >> n >> a >> b >> l;

    rep(i, n){
        l = b * l / a;
    }
    cout << fixed << setprecision(7) << l << endl;

    return 0;
}