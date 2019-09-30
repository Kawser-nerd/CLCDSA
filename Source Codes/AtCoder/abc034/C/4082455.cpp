#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#define all(x) (x).begin(),(x).end()

const ll MOD = 1e9 + 7;

void solve(){

}

//a^n(mod M);
ll modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll factorial(ll n){
    if (n == 1) return 1;
    return n * factorial(n-1) % MOD;
}
    
int main(){
    int H,W;
    cin >> H >> W;
    ll nul = factorial(W+H-2);
    ll div = (factorial(H-1)*factorial(W-1)) %MOD;
    div = modpow(div,MOD-2,MOD);

    cout << nul*div%MOD << endl;


    

    return 0;
}