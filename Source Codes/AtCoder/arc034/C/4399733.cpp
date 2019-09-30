#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

int main() {
    using ll = long long;
    const ll mod = 1000000007;
    
    ll a, b;
    cin >> a >> b;
    
    map<ll, ll> cnt;
    
    for (ll x = b + 1; x <= a; x++) {
        ll tmp = x;
        
        for (ll i = 2; i * i <= x; i++) {
            while(tmp % i == 0) {
                cnt[i]++;
                
                tmp /= i;
            }
        }
        
        if (tmp != 1) {
            cnt[tmp]++;
        }
    }
    
    ll ans = 1;
    
    for (auto& p : cnt) {
        ans = ans * (p.second + 1) % mod;   
    }
    
    cout << ans << endl;
}