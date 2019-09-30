#include <iostream>
#define MOD 1000000007
using namespace std;
using ull = unsigned long long;

void fact(ull *n, ull *k, ull *nk){
    int num[*n+1];
    num[0] = 1;
    for(ull i = 1; i <= *n; ++i){
        num[i] = i * num[i-1] % MOD;
    }

    *nk = num[*n - *k];
    *n = num[*n];
    *k = num[*k];

    return ;
}

ull a_p(ull a, ull p){
    ull ans = 1;
    while(p > 0){
        if(p & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        p>>=1;
    }

    return ans;
}

int main(){
    int W, H;
    cin >> W >> H;
    
    ull fact_n = W + H - 2, fact_k = H - 1, fact_nk = W - 1;
    fact(&fact_n, &fact_k, &fact_nk);

    ull newVal = fact_k * fact_nk % MOD;
    newVal = (fact_n * (a_p(newVal, MOD-2) % MOD)) % MOD;
    
    cout << newVal << endl;
    return 0;
}