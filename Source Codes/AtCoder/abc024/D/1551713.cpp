#include <iostream>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll p = c*((b-a+MOD) % MOD)%MOD;
    ll q = b*((c-a+MOD) % MOD)%MOD;
    ll r = ((-b*c+a*c+a*b) % MOD) + MOD % MOD;
    ll prime = MOD - 2, acc = 1, seed = r % MOD;
    while(prime){
        if(prime & 1) acc = acc * seed % MOD;
        seed = seed * seed % MOD;
        prime >>= 1;
    }
    cout << ((acc * p) % MOD + MOD) % MOD << " " << ((acc * q + MOD) % MOD + MOD) % MOD << endl;

    return 0;
}