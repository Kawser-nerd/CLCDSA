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
 
    ll l = 2, r = 2;
    
    for (int i = k - 1; i >= 0; i--) {
        ll x = (l + a[i] - 1) / a[i] * a[i];
        ll y = r / a[i] * a[i];
        
        if (x <= r && l <= y) {
            l = x;
            r = y + a[i] - 1;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    
    cout << l << ' ' << r << endl;
    return 0;
}