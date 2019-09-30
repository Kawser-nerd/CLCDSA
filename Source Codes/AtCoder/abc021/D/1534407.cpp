#include <iostream>
#define MOD 1000000007
using namespace std;
using ull = unsigned long long;

ull fact(ull n, ull k){
    ull t = 1;
    for(int i = 0; i < k; ++i){
        t = t * (n + i) % MOD;
    }
    return t % MOD;
}

ull split(ull n){
    ull p = MOD - 2;
    ull seed = n % MOD;
    ull ans = 1;
    while(p){
        if(p & 1) ans = ans * seed % MOD; 
        seed = seed * seed % MOD;
        p >>= 1;
    }
    return ans;
}

ull defact(ull n, ull k){
    ull t = 1;
    for(int i = 1; i <= k; ++i){
        t = t * split(i) % MOD;
    }
    return t;
}

int main(){
    int n, k;
    cin >> n >> k;
    ull v1 = fact(n, k);
    ull v2 = defact(n, k);
    cout << v1 * v2 % MOD << endl;
    return 0;
}