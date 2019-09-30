#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

void solve() {
    bool can = false;

    int n, D;
    cin >> n;
    vector<int> l(n);
    vector<int> d(n);

    for (int i = 0; i < n; i++)
        cin >> d[i] >> l[i];
    assert(d[0] <= l[0]);
    cin >> D;

    vector<int> best(n, -1);
    best[0] = d[0];

    for (int i = 0; i < n; i++) if (best[i] != -1) {
        for (int j = i + 1; j < n; j++) {
            if (d[i] + best[i] >= d[j]) {
                best[j] = max(best[j], min(l[j], d[j] - d[i]));
            }
        }

        if (d[i] + best[i] >= D) can = true;
    }


    static int test;
    cout << "Case #" << ++test << ": ";
    if (can) cout << "YES"; else cout << "NO";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
