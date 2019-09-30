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
typedef pair<ll, int> P;

int main() {
    int n, k;
    cin >> n >> k;
    vector <P> vec;
    for (int i = 0; i < n; i++) {
        int t;
        ll d;
        cin >> t >> d;
        vec.push_back(P(d, t));
    }

    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    vector <ll> redundant;
    map <int, int> mp;
    ll sm = 0LL;
    for (int i = 0; i < k; i++) {
        sm += vec[i].first;
        if (mp[vec[i].second] == 0) {
            mp[vec[i].second] = 1;
        } else {
            redundant.push_back(vec[i].first);
        }
    }

    int pos = redundant.size() - 1;
    ll sz = mp.size();
    ll ans = sm + sz * sz;
    for (int i = k; i < n; i++) {
        if (sz == k) break;
        if (mp[vec[i].second] > 0) continue;

        sm -= redundant[pos--];
        sm += vec[i].first;
        mp[vec[i].second] = 1;
        sz++;

        ans = max(ans, sm + sz * sz);
    }

    cout << ans << "\n";
    return 0;
}