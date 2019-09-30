#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int p[10] = { 0 };
    int ans = 0;
    int maxI = 0, maxP = 0;
    for (int i = 0; i < n; i++) {
        int pi; cin >> pi;
        p[i] = pi;
        if (maxP < pi) {
            maxI = i;
            maxP = pi;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i == maxI) ans += maxP / 2;
        else ans += p[i];
    }
    cout << ans << endl;

    return 0;
}