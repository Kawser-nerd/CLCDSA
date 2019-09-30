#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>

using namespace std;

int main() {
    int n; cin >> n;

    vector<int> vc;
    vc.resize(n);

    for (int i = 0; i < n; ++i) {
        int t; cin >> t;
        vc[i] = t;
    }

    int minDiff = INT_MAX;
    int ans = 0;

    for (int bit = 0; bit < 1 << n; ++bit) {
        int left = 0, right = 0;
        for (int i = 0; i < n; ++i) {
            if (bit & 1 << i) left += vc[i];
            else              right += vc[i];
        }
        int diff = abs(left - right);
        if (diff < minDiff) {
            minDiff = diff;
            ans = max(left, right);
        }
    }

    cout << ans << endl;

    return 0;
}