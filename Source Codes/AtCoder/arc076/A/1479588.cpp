#include <iostream>
#define MOD 1000000007
using namespace std;
using ull = unsigned long long;

ull fact(ull n){
    ull h[n+1];
    h[0] = 1;
    for(int i = 1; i <= n; ++i){
        h[i] = i * h[i-1] % MOD;
    }
    return h[n];
}

int main(){
    ull N, M;
    ull ans;
    cin >> N >> M;

    if(N == M){
        ans = 2 * (fact(N) % MOD) * (fact(N) % MOD) % MOD;
    }else if(M - N == 1 || N - M == 1){
        ans = (fact(N) % MOD) * (fact(M) % MOD) % MOD; 
    }else{
        ans = 0;
    }
    
    cout << ans << endl;
    return 0;
}