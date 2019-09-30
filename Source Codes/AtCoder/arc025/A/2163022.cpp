#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> d(7), j(7);
    rep(i, 7){
        cin >> d[i];
    }
    rep(i, 7){
        cin >> j[i];
    }

    int ans = 0;
    rep(i, 7){
        if(d[i] > j[i]){
            ans += d[i];
        }else{
            ans += j[i];
        }
    }
    cout << ans << endl;

    return 0;
}