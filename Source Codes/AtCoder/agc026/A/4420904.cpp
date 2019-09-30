#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;

    int prev;
    cin >> prev;

    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;

        if (a == prev) {
            ans++;

            prev = -1;
        } else {
            prev = a;
        }
    }

    cout << ans << endl;
}