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

class combination{
    private:
        vector<int> t;

    public:
        combination(int n): t(n+1){
            t[n] = powM(factM(n), MOD-2);

            for(int i = n-1; i >= 0; i--){
                t[i] = t[i+1] * (i+1) % MOD;
            }

        }

        int comb(int n, int k){
            return n * t[k] % MOD;
        }
};

signed main(){
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    combination c(n);
    int t = 0;
    int pre = a[0];
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(a[i] != -1){
            int diff = a[i] - pre;

            ans = c.comb(ans, t);
            for(; t > 0; t--){
                ans = ans * (diff + t) % MOD;
            }

            pre = a[i];
            continue;
        }
        t++;
    }
    cout << ans << endl;

    return 0;
}