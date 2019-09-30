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

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    while (true) {
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += a[i] / n;
            a[i] = a[i] % n - a[i] / n;
        }

        ans += cnt;

        bool flag = true;
        for (int i = 0; i < n; i++) {
            a[i] += cnt;
            if (a[i] >= n) flag = false;
        }

        if (flag) break;
    }

    cout << ans << "\n";
    return 0;
}