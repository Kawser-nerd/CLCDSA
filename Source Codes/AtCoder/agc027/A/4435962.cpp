#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (i != n - 1 ? a[i] <= x : a[i] == x) {
            ans++;
            x -= a[i];
        } else {
            break;
        }
    }

    cout << ans << endl;
}