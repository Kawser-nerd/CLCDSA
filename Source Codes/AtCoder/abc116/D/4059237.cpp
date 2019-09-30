#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;

using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    
    vector<ll> a(n);
    vector<ll> b;
   
 
    for (int i = 0; i < n; i++) {
        ll t, d;
        cin >> t >> d;
        
        t--;
       
        if (a[t] == 0) {
            a[t] = d;
        } else if (a[t] < d) {
            b.push_back(a[t]);
            a[t] = d;
        } else {
            b.push_back(d);   
        }
    }
    
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    
    ll ans = 0;
    ll sum = 0;
    
    if (b.size() > k) {
        b.resize(k);
    }
    
    sum = accumulate(b.begin(), b.end(), ll(0));
    
    for (ll i = 0; i < k; i++) {
        if (a[i] == 0) {
            break;
        }
        
        if (b.size() + i + 1 > k) {
            sum -= b.back();
            b.pop_back();
        }
        
        sum += a[i];
        
        ans = max(ans, sum + (i + 1) * (i + 1));
    }
    
    cout << ans << endl;
}