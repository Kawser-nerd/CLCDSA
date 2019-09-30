#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <array>
using namespace std;

constexpr int64_t mod = 1e9 + 7;

int64_t pow_mod(int64_t a, int64_t b){
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b & 1) return pow_mod(a * a % mod, b >> 1);
    return (a * pow_mod(a, b - 1)) % mod;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int N = n - 1 + k;
    vector<int64_t> data(N + 1);
    vector<int64_t> invdata(N + 1);

    data[1] = 1;
    for(int i = 2; i <= N; ++i){
        data[i] = (i * data[i - 1]) % mod;
    }
    
    int64_t tmp = data[N];
    int64_t doubling = mod - 2;
    invdata[N] = 1;
    while (doubling > 0) {
        if (doubling % 2){
            invdata[N] = (invdata[N] * tmp) % mod;
        }
        tmp = (tmp * tmp) % mod;
        doubling /= 2;
    }
 
    for (int64_t i = N; i > 0; --i){
        invdata[i - 1] = (invdata[i] * i) % mod;
    }

    int64_t ans = data[N];
    ans = (ans * invdata[k]) % mod;
    ans = (ans * invdata[n - 1]) % mod;
    cout << ans << endl;

    return 0;
}