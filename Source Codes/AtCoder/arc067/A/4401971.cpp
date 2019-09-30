#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
typedef unsigned int uint;
using namespace std;

const ll MOD = 1000000007;

map<int, int> prime_factor(int n) {
    map<int, int> ret;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }

    if (n != 1) ret[n] = 1;
    return ret;
}

int main() {
    int n;
    cin >> n;

    map <int, int> mp;
    for (int i = 2; i <= n; i++) {
        map <int, int> m = prime_factor(i);
        for (auto itr = m.begin(); itr != m.end(); ++itr) {
            mp[itr->first] += itr->second;
        }
    }

    ll ans = 1;
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        if (itr->first == 1) continue;
        ans = ans * (itr->second + 1) % MOD;
    }

    cout << ans << "\n";
    return 0;
}