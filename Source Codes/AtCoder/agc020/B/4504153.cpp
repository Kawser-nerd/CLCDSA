#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

using ll = long long;

int main() {
    int k;
    cin >> k;
    
    vector<int> a(k);
    
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
 
    ll l1 = 0, r1 = 1LL << 60;
    
    while (r1 - l1 > 1) {
        ll m = (r1 + l1) / 2;
        
        ll x = m;
        for (int i = 0; i < k; i++) {
            x = x / a[i] * a[i];   
        }
        
        if (x > 2) {
            r1 = m;   
        } else {
            l1 = m;
        }
    }
    
    ll l2 = 0, r2 = 1LL << 60;
    
    while (r2 - l2 > 1) {
        ll m = (r2 + l2) / 2;
        
        ll x = m;
        for (int i = 0; i < k; i++) {
            x = x / a[i] * a[i];   
        }
        
        if (x >= 2) {
            r2 = m;   
        } else {
            l2 = m;
        }
    }
    
    if (l1 - r2 > 0) {
        cout << r2 << ' ' << l1 << endl;   
    } else {
        cout << -1 << endl;
    }
}