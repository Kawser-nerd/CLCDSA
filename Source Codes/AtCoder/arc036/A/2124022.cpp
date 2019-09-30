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
    int n, k;
    cin >> n >> k;

    vector<int> t(n);
    rep(i, n) cin >> t[i];

    for(int i = 2; i < n; i++){
        int s = t[i-2] + t[i-1] + t[i];
        if(s < k){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}