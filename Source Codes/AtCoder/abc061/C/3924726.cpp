#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    ll n, k, a, b;
    cin >> n >> k;
    map<ll, ll> mp;
    
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        mp[a] += b;
    }
    
    for(auto x: mp) {
        k -= x.second;
        if (k <=0) {
            cout << x.first << endl;
            return 0;
        }
    }
}