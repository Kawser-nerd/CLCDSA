#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    ll N, K; cin >> N >> K;
    map<ll, ll> mp;
    for (int i = 0; i<N; i++) {
        ll a, b; cin >> a >> b;
        mp[a] += b;
    }
    
    for (map<ll, ll>::iterator it = mp.begin(); it != mp.end(); it++) {
        K -= it->second;
        if (K <= 0) {
            cout << it->first << endl;
            return 0;
        }
    }
    return 0;
}