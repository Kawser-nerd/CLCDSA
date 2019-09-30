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

    ans = max(ans, (a[0] - '0' - 1) + 9 * (n - 1));

    cout << ans << endl;
}