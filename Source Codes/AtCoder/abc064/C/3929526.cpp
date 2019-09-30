#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
typedef long long ll;
using namespace std;

int main() {
    
    ll n; cin >> n;
    ll extra = 0;
    set<ll> colors;
    for (int i = 0; i < n; i++) {
        ll a; cin >> a;
        ll val = a/400;
        if (val < 8) {
            colors.insert(val);
        } else {
            extra++;
        }
    }
    if (colors.size()==0) {
        cout << 1 << " " << extra << endl;
    } else {
        cout << colors.size() << " " << colors.size()+extra << endl;
    }
    return 0;
}