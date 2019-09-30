#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

bool go(const vector<int>& h, vector<int>& y, long long dx, long long dy, int l, int r) {
    if (l >= r) return true;
    bool result = true;
    
    for (int i = l; i < r; i++) if (h[i] > r) result = false;
    if (!result) return result;

    for (int i = l; i < r; i++) if (h[i] == r) {
        long long X = r - i;
        long long Y = (dy * X + dx) / dx;
        y[i] = y[r] - Y;
        assert(y[i] >= 0);
        result &= go(h, y, X, Y, i + 1, r);
        result &= go(h, y, X, Y, l, i);
        return result;
    }

    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> h(n-1), y(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> h[i];
        h[i]--;
    }

    y[n-1] = 1e9;
    bool can = true;
    for (int i = 0; i < n - 1; i++)
        can &= h[i] > i;

    can &= go(h, y, 1, 0, 0, n - 1);

    static int test;
    cout << "Case #" << ++test << ": ";
    if (can) {
        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            cout << y[i];
        }
    } else {
        cout << "Impossible";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
