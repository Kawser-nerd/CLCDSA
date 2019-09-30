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
using namespace std;
typedef pair<string, string> Ps;
typedef pair<ll, ll> Pi;

int main() {
    int n;
    string s;
    cin >> n >> s;

    map <Ps, Pi> mp;
    for (int i = 0; i < (1 << n); i++) {
        string s1="", s2="";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) s1 += s[j];
            else s2 += s[j];
        }
        mp[Ps(s1, s2)].first++;
    }

    for (int i = 0; i < (1 << n); i++) {
        string s1="", s2="";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) s1 += s[2*n-1-j];
            else s2 += s[2*n-1-j];
        }
        mp[Ps(s1, s2)].second++;
    }

    ll ans = 0LL;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        ans += itr->second.first * itr->second.second;
    }

    cout << ans << "\n";
    return 0;
}