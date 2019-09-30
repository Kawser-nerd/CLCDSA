#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
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
    int x, y;
    cin >> x >> y;

    if(x != y && abs(x) == abs(y)){
        cout << 1 << endl;
        return 0;
    }

    if(abs(x) < abs(y)){
        int ans = abs(y) - abs(x);
        if(x < 0){
            ans++;
        }
        if(y < 0){
            ans++;
        }
        cout << ans << endl;
        return 0;
    }

    int ans = abs(x) - abs(y);
    if(x > 0){
        ans++;
    }
    if(y > 0){
        ans++;
    }
    cout << ans << endl;
    return 0;
}