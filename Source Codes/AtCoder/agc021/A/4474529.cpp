#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a;
    cin >> a;

    int n = a.size();

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += a[i] - '0';
    }

    int s = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            ans = max(ans, s + (a[i] - '0' - 1) + 9 * (n - i - 1));
        }

        s += a[i] - '0';
    }

    cout << ans << endl;
}