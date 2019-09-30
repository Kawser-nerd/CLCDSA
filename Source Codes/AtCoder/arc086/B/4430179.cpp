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

const int inf = 1 << 30;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int a[n];
    int mx = -inf, mn = inf;
    int mx_idx = 0, mn_idx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > mx) {
            mx = a[i];
            mx_idx = i;
        }
        if (a[i] < mn) {
            mn = a[i];
            mn_idx = i;
        }
    }

    cout << 2 * n - 1 << '\n';
    if (mx > -mn) {
        for (int i = 0; i < n; i++) cout << mx_idx + 1 << " " << i+1 << "\n";
        for (int i = 1; i < n; i++) cout << i << " " << i+1 << "\n";
    } else {
        for (int i = 0; i < n; i++) cout << mn_idx + 1 << " " << i+1 << "\n";
        for (int i = n; i > 1; i--) cout << i << " " << i-1 << "\n";
    }

    return 0;
}