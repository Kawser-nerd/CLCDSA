#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, A;
    cin >> A;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());

    int ans = 1 << 20;

    for (int l = 0; l <= n; ++l) {
        int X = A;
        int cur = l;
        for (int j = 0; j < n - l; ++j)
            if (X > v[j]) {
                X += v[j];
            } else {
                if (X == 1) { cur = 1 << 30; break; }
                X += X - 1;
                cur++;
                --j;
            }
        ans = min(cur, ans);
    }

    static int testid;
    cout << "Case #" << ++testid << ": " << ans << endl;
}

int main() {
    int tests;
    cin >> tests;
    while (tests --> 0)
        solve();
    return 0;
}
