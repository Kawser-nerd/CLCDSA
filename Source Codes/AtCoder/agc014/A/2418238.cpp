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
    int a, b, c;
    cin >> a >> b >> c;

    if(a == b && b == c && a % 2 == 0){
            cout << -1 << endl;
            return 0;
    }

    int ans = 0;
    while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0){
        int aa = (b + c) / 2;
        int bb = (a + c) / 2;
        int cc = (a + b) / 2;
        a = aa;
        b = bb;
        c = cc;
        ans++;
    }
    cout << ans << endl;

    return 0;
}