#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

typedef pair<int, int> P;

int main() {
    int n, m; cin >> n >> m;
    vector<P> bridges;
    bridges.resize(m);
    for (int i = 0; i < m; ++i) {
        int l, r; cin >> l >> r;
        bridges[i] = P(l, r);
    }

    sort(bridges.begin(), bridges.end());

    int ans = 0;
    int l = 0, r = 0;

    for (int i = 0; i < m; ++i) {
        if (bridges[i].first >= r) {
            ++ans;
            l = bridges[i].first;
            r = bridges[i].second;
            continue;
        }

        l = max(l, bridges[i].first);
        r = min(r, bridges[i].second);
    }

    cout << ans << endl;

    return 0;
}