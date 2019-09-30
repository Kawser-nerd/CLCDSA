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

    int n, c, k;
    cin >> n >> c >> k;

    int t[n];
    for (int i = 0; i < n; i++) cin >> t[i];

    sort(t, t+n);

    int idx = 0;
    int lim = t[0] + k;
    int cnt = 0;
    int ans = 0;
    while (true) {
        if (idx >= n) {
            if (cnt) ans++;
            break;
        }

        if (cnt == c) {
            ans++;
            cnt = 0;
            lim = t[idx] + k;
        }

        if (t[idx] <= lim) {
            cnt++;
        } else {
            ans++;
            lim = t[idx] + k;
            cnt = 1;
        }
        idx++;
    }

    cout << ans << "\n";
    return 0;
}