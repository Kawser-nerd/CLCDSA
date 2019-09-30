#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int k;
    int f[n];
    fill(f, f+n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> k;
            if (k == 1) f[i] |= (1<<j);
        }
    }

    int p[n][11];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 11; j++) {
            cin >> p[i][j];
        }
    }

    int ans;
    int tmp_ans;
    ans = INT_MIN;

    for (int i = 1; i < 1<<10; i++) {
        tmp_ans = 0;

        for (int j = 0; j < n; j++) {
            tmp_ans += p[j][__builtin_popcount(i&f[j])];
        }

        ans = max(ans, tmp_ans);
    }

    cout << ans << endl;
    return 0;
}