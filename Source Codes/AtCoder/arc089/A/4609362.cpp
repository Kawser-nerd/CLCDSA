#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> t(n), x(n), y(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }

    int pt = 0, px = 0, py = 0;

    for (int i = 0; i < n; i++) {
        int dt = t[i] - pt;
        int dx = abs(px - x[i]);
        int dy = abs(py - y[i]);

        if (dt < dx + dy || dt % 2 != (dx + dy) % 2) {
            cout << "No" << endl;
            return 0;
        }

        pt = t[i];
        px = x[i];
        py = y[i];
    }

    cout << "Yes" << endl;
}