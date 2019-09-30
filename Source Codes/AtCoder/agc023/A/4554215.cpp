#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <random>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    ll a[n];
    map <ll, ll> mp;
    mp[0]++;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) a[i] += a[i-1];
        mp[a[i]]++;
    }

    ll ans = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        ans += itr->second * (itr->second - 1) / 2;
    }

    cout << ans << "\n";
    return 0;
}