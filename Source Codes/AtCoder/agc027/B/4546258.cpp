#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

using ll = long long;

int main() {
    int n;
    ll a;
    cin >> n >> a;
    
    vector<ll> x(n);
    
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    ll ans = 1LL << 60;
    
    reverse(x.begin(), x.end());
    
    x.resize(2 * n);
    
    vector<ll> c(2 * n + 1);
    
    for (int i = 0; i < 2 * n; i++) {
        c[i + 1] = c[i] + x[i];   
    }
    
    for (int i = 1; i <= n; i++) {
        ll s = 0;
        
        int ind = 0;
        for (int j = 0; j < (n + i - 1) / i; j++) {
            ll t = c[ind + i] - c[ind];
            ind += i;
            
            if (j == 0) {
                s += 5 * t;
            } else {
                s += (2 * j + 3) * t;
            }
            
            if (s > ans) {
                break;
            }
        }
        
        ans = min(ans, s + a * i);
        
    }
    
    cout << ans + a * n << endl;
}