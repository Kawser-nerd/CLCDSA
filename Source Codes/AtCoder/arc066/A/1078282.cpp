#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    long long int n;
    cin >> n;

    long long int a[n];
    int num[n];

    for (int i = 0; i < n; i++) {
        num[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        num[a[i]]++;
    }

    long long int ans = 0;
    bool ok = true;
    if (n % 2 == 0) {
        if (num[0] == 0) {
            for (long long int i = 1; i < n; i += 2) {
                if (num[i] != 2) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = 1;
                for (long long int i = 0; i < n / 2; i++) {
                    ans *= 2;
                    ans %= 1000000007;
                }
            } else { ans = 0; }
        }
    } else {
        if (num[0] == 1) {
            for (long long int i = 2; i < n; i += 2) {
                if (num[i] != 2) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = 1;
                for (long long int i = 0; i < (n - 1) / 2; i++) {
                    ans *= 2;
                    ans %= 1000000007;
                }
            } else { ans = 0; }
        }
    }

    cout << ans << endl;

    return 0;
}