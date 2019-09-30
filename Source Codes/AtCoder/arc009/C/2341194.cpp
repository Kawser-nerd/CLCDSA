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
const int MOD = 1777777777;

int montmort(int n){
    static vector<int> m = {1, 0, 1, 2};
    if((int)m.size()-1 >= n){
        return m[n];
    }

    int x = (n-1) * ((montmort(n-1) + montmort(n-2)) % MOD) % MOD;
    m.push_back(x);
    return m[n];
}

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

int comb(int n, int k){
    if(n < k){
        return 0;
    }
    int kFactInv = powM(factM(k), MOD - 2);
    int x = 1;
    for(int i = n; i > n - k; i--){
        x = i % MOD * x % MOD;
    }
    return kFactInv * x % MOD;
}

signed main(){
    int n, k;
    cin >> n >> k;

    cout << comb(n, k) * montmort(k) % MOD << endl;

    return 0;
}