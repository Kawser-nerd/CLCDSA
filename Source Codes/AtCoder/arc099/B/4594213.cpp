#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <string>

using namespace std;

using ll = long long;

ll S(ll n) {
    ll ret = 0;
    
    while(n > 0) {
        ret += n % 10;
        
        n /= 10;
    }
    
    return ret;
}

int main() {
    vector<ll> ans;
    
    for (int i = 1; i < 10; i++) {
        ans.push_back(i);
    }
    
    for (int i = 0; i <= 15; i++) {
        for (int j = 1; j < i * 10; j++) {
            bool ok = true;
            
            ll n = stoll(to_string(j) + string(i, '9'));
            
            for (int k = j + 1; k < i * 10; k++) {
                ll m = stoll(to_string(k) + string(i, '9'));
                
                if (n * S(m) > m * S(n)) {
                    ok = false;
                    break;
                }
            }
            
            if (ok) {
                ans.push_back(n);
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    
    int k;
    cin >> k;
    
    for (int i = 0; i < k; i++) {
        cout << ans[i] << endl;
    }
}