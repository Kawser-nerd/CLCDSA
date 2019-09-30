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
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

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

class Combination{
    private:
        vector<int> t;

    public:
        Combination(int n): t(n+1){
            t[n] = powM(factM(n), MOD-2);

            for(int i = n-1; i >= 0; i--){
                t[i] = t[i+1] * (i+1) % MOD;
            }
        }

        int comb(int n, int k){
            if(n < k || n < 0 || k < 0){
                return 0;
            }
            return factM(n) * t[k] % MOD * t[n-k] % MOD;
        }

        int getInv(int n){
            return t[n];
        }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, c, x, y, d, l;
    cin >> r >> c >> x >> y >> d >> l;

    Combination cc(1000);

    int ans = 0;
    for(int i = x; i >= x - 2 ; i--){
        for(int j = y; j >= y - 2; j--){
            if(i * j < d + l || i < 0 || j < 0){
                continue;
            }
            int tmp = cc.comb(i * j, d);
            tmp *= cc.comb(i * j - d, l);
            tmp %= MOD;

            if(i == x - 1){
                tmp *= 2;
                tmp %= MOD;
            }
            if(j == y - 1){
                tmp *= 2;
                tmp %= MOD;
            }

            if((i + j) % 2 == (x + y) % 2){
                ans += tmp;
            }else{
                ans += MOD - tmp;
            }
            ans %= MOD;
        }
    }
    ans *= (r - x + 1);
    ans %= MOD;
    ans *= (c - y + 1);
    ans %= MOD;

    cout << ans << endl;

    return 0;
}