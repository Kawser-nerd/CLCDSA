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

int factM(int n){
    static vector<int> t = {1};

    if((int)t.size() > n){
        return t[n];
    }

    for(int i = t.size(); i <= n; i++){
        t.push_back(t[i-1] * i % MOD);
    }
    return t[n];
}

signed main(){
    int n;
    cin >> n;

    vector<int> t(n), sum(n);
    rep(i, n) cin >> t[i];
    sort(t.begin(), t.end());
    rep(i, n){
        sum[i] = t[i];
        if(i > 0){
            sum[i] += sum[i-1];
        }
    }

    int ans1 = 0;
    rep(i, n) ans1 += sum[i];
    cout << ans1 << endl;

    vector<int> kind(1e5+1);
    rep(i, n) kind[t[i]]++;

    int ans2 = 1;
    rep(i, 1e5+1){
        ans2 = ans2 * factM(kind[i]) % MOD;
    }
    cout << ans2 << endl;

    return 0;
}