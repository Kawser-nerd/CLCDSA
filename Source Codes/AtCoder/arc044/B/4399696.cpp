#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    using ll = long long;
    const ll mod = 1000000007;
    
    vector<ll> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];   
    }
    
    if (a[0] != 0 || count(a.begin() + 1, a.end(), 0) != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<ll> cnt(n);
    
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    
    ll ans = 1;
    
    auto pow_mod = [&](ll x, ll n) {
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
    };
    
    int m = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (cnt[i] != 0) {
            m = i;
            break;
        }
    }
    
    for (int i = 1; i <= m; i++) {
        ans = ans * pow_mod((pow_mod(2, cnt[i - 1]) - 1 + mod) % mod, cnt[i]) % mod;
        ans = ans * pow_mod(2, cnt[i] * (cnt[i] - 1) / 2) % mod;
    }
    
    cout << ans << endl;
}