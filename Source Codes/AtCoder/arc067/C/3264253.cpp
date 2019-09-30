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

int n, a, b, c, d;
vector<int> num;
int ans = 0;

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
    public:
        vector<int> t;
        combination(int n): t(n+1){
            t[n] = powM(factM(n), MOD-2);

            for(int i = n-1; i >= 0; i--){
                t[i] = t[i+1] * (i+1) % MOD;
            }

        }

        int comb(int n, int k){
            if(n < k){
                return 0;
            }
            return factM(n) * t[k] % MOD * t[n-k] % MOD;
        }
};

signed main(){
    cin >> n >> a >> b >> c >> d;
    num = vector<int>(b+1);
    combination comb(n);

    vector<vector<int>> dp(b+1, vector<int>(n+1));
    dp[a-1][0] = 1;
    for(int i = a; i <= b; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; j - i * k >= 0; k++){
                if(k != 0 && (k < c || d < k)){
                    continue;
                }
                int tmp = factM(n-j+i*k) * comb.t[n-j] % MOD * powM(comb.t[i], k) % MOD * comb.t[k] % MOD;
                dp[i][j] = (dp[i][j] + dp[i-1][j-i*k] * tmp % MOD) % MOD;
            }
        }
    }
    cout << dp[b][n] << endl;

    return 0;
}