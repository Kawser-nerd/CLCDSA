#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

void solve() {
    bool can = false;

    int n, W, H;
    cin >> n >> W >> H;
    vector<int> r(n), x(n), y(n);
    for (int i = 0; i < n; i++) cin >> r[i];
    vector< pair<int, int> > id;
    for (int i = 0; i < n; i++)
        id.push_back(make_pair(r[i], i));
    sort(id.begin(), id.end());

    reverse(id.begin(), id.end());
    int curX = 0;

    for (int i = 0; i < n; ) {
        if (i) {
            W -= id[i].first;
            curX += id[i].first;
        }

        x[id[i].second] = curX;
        y[id[i].second] = 0;

        int j = i + 1;

        int curH = 0;
        
        while (j < n && curH + id[j].first + id[j-1].first <= H) {
            curH += id[j].first + id[j-1].first;

            x[id[j].second] = curX;
            y[id[j].second] = curH;

            j++;
        }

        if (j < n) {
            curX += id[i].first;
        }
        i = j;
    }

    assert(curX <= W);

    static int test;
    cout << "Case #" << ++test << ": ";
    cout << fixed;
    cout.precision(10);
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << x[i] << ' ' << y[i];
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
