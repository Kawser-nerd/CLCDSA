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
    int q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;

    q *= 4;
    h *= 2;

    int one = min(q, min(h, s));

    if(one < d / 2.0){
        cout << one * n << endl;
        return 0;
    }

    int ans = n / 2 * d;
    ans += n % 2 * one;

    cout << ans << endl;

    return 0;
}