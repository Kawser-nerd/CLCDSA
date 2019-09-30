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

const int MAX_N = 200005;
int sz, bit[MAX_N + 1];

// i?????????a[1]+a[2]+...+a[i]?????
int sum(int i) {
    int s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i; // ???1???
    }
    return s;
}

// i?x?????????a[i]?x???
void add(int i, int x) {
    while (i <= sz) {
        bit[i] += x;
        i += i & -i;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll k;
    cin >> n >> k;

    ll a[n+1];
    vector <ll> sa(n+1);
    a[0] = sa[0] = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= k;
        a[i] += a[i-1];
        sa[i] = a[i];
    }

    sort(sa.begin(), sa.end());
    unique(sa.begin(), sa.end());

    map <ll, int> mp;
    sz = sa.size();
    for (int i = 1; i <= sz; i++) {
        if (mp[sa[i-1]] > 0) break;
        mp[sa[i-1]] = i;
    }

    for (int i = 0; i <= n; i++) {
        ans += sum(mp[a[i]]);
        add(mp[a[i]], 1);
    }

    cout << ans << "\n";
    return 0;
}