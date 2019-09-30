#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

using ll = long long;

ll pow_mod(ll x, ll n, ll mod) {
    ll ret = 1;
    
    ll base = x;
    
    while(n > 0) {
        if (n & 1) {
            ret = ret * base % mod;
        }
        
        base = base * base % mod;
        
        n >>= 1;
    }
    
    return ret;
}

int main() {
    
    int n;
    cin >> n;
    
    vector<ll> a(n), l(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> l[i];
    }
    
    ll b;
    cin >> b;
    
    ll ans = 0;
    
    ll base10 = 0;
    
    for (int i = n - 1; i >= 0; --i) {
        ll m = to_string(a[i]).size();
        
        ll s = 0;
        ll x = a[i];
        ll p = m;
        ll d = 0;
        ll k = l[i]; 
        
        while (k > 0) {
            if (k & 1) {
                s = (s + x * pow_mod(10, d, b)) % b;
                
                d += p;
            }
            
            x = (x * pow_mod(10, p, b) % b + x) % b;                        
            k >>= 1;
            p *= 2;
        }
        
        ans = (ans + s * pow_mod(10, base10, b) % b) % b; 
        base10 += m * l[i];
    }
   
    cout << ans << endl;
}