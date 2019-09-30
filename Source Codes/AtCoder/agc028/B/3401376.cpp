#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>

#define int long long int
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> P;

const int INF = 1e15;
const int MOD = 1e9+7;

int powM(int x, int n){
    if(n == 0){
        return 1;
    }
    if(n % 2 == 0){
        return powM(x * x % MOD, n / 2);
    }
    return powM(x, n-1) * x % MOD;
}

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

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> p(n+1);
    int all = factM(n) % MOD;
    rep(i, n){
        p[i+1] = (p[i] + all * powM(i+1, MOD-2) % MOD) % MOD;
    }

    int ans = 0;
    rep(i, n){
        ans = (ans + a[i] * ((MOD + p[i+1] + p[n-i] - p[1]) % MOD) % MOD) % MOD;
    }
    cout << ans << endl;

    return 0;
}