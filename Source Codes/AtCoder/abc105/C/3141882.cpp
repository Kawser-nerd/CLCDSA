#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool s[1000] = {};
    int i;
    long long mod = 2;
    for (i = 0; n != 0; i++) {
        if (n % mod) {
            s[i] = true;
            n -= pow(-2, i);
        }
        mod *= 2;
    }

    for (i -= 1; i > 0; i--) cout << s[i];
    cout << s[0] << endl;
}